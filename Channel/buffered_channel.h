#ifndef CHANNEL__BUFFERED_CHANNEL_H_
#define CHANNEL__BUFFERED_CHANNEL_H_

#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

template<class T>
class Channel
{
 private:
	int buffer_size;
	bool isOpened;
	std::queue<T> queue;
	std::mutex mtx;
	std::condition_variable notify;

 public:
	explicit Channel(int bufferSize) : buffer_size(bufferSize) {}

	bool isFull() { return queue.size() == buffer_size; }

	bool isEmpty() { return queue.empty(); }

	void send(T value) {
		std::unique_lock<std::mutex> uLock(mtx);

		if (isFull())
			notify.wait(uLock);

		if (isOpened)
			throw std::runtime_error("Sending value is impossible, channel's closed.");

		queue.push(value);
		uLock.unlock();
		notify.notify_one();
	}

	std::pair<T, bool> recv() {
		std::unique_lock<std::mutex> uLock(mtx);

		if (isEmpty())
			notify.wait(uLock);

		T element = queue.front();
		queue.pop();
		uLock.unlock();
		notify.notify_one();

		return std::make_pair(element, isOpened);
	}

	void close() {
		std::unique_lock<std::mutex> uLock(mtx);
		isOpened = false;
		uLock.unlock();
		notify.notify_one();
	}
};

#endif //CHANNEL__BUFFERED_CHANNEL_H_
