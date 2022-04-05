#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>

#define MATRIX vector<vector<int>>

using namespace std;

mutex mtx;

MATRIX randomMatrix(int size) {
	MATRIX res(size, vector<int> (size));
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			res[i][j] = rand() % (i + j + 7);
		}
	}
	return res;
}

MATRIX standardMatricesMultiplication(MATRIX A, MATRIX B, int dim) {
	MATRIX C(dim, vector<int> (dim));
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j) {
			for (int k = 0; k < dim; ++k) {
				C[i][j] += B[i][k] * A[k][j];
			}
		}
	}

	return C;
}

void blocksMultiplication(MATRIX& C,
						  MATRIX A,
						  MATRIX B,
						  int ii,
						  int jj,
						  int kk,
						  int blockSize) {
	for (int i = ii; i < ii + blockSize; ++i) {
		for (int j = jj; j < jj + blockSize; ++j) {
			int sum = 0;
			for (int k = 0; k < blockSize; ++k) {
				sum += A[i][kk + k] * B[kk + k][j];
			}
			mtx.lock();
			C[i][j] += sum;
			mtx.unlock();
		}
	}
}

MATRIX blockMatricesMultiplication(MATRIX A, MATRIX B, int numberOfBlocks) {
	MATRIX C(A.size(), vector<int> (A.size()));
	int blockSize = A.size() / numberOfBlocks;
	vector<thread> threadsArr;
	for (int i = 0; i < C.size(); i += blockSize) {
		for (int j = 0; j < C.size(); j += blockSize) {
			for (int k = 0; k < C.size(); k += blockSize) {
				thread thr(blocksMultiplication, ref(C), A, B, i, j, k, blockSize);
				threadsArr.push_back(move(thr));
			}
		}
	}

	for (int i = 0; i < threadsArr.size(); ++i) {
		threadsArr[i].join();
	}

	return C;
}

int main() {
	int matrixSize;
	cout << "insert matrix size:" << endl;
	cin >> matrixSize;

	MATRIX A, B, C;

	A = randomMatrix(matrixSize);
	B = randomMatrix(matrixSize);

	cout << "########## STANDARD MULTIPLICATION ##########\ntime: ";
	int a = clock();
	C = standardMatricesMultiplication(A, B, matrixSize);
	cout << clock() - a << "ms" << endl << endl;

	cout << "########## BLOCK MULTIPLICATION ##########\n";

	for (int i = 1; i <= matrixSize; ++i) {
		if (matrixSize % i == 0) {
			cout << "number of blocks: " << i << endl << "time: ";
			a = clock();
			C = blockMatricesMultiplication(A, B, i);
			cout << clock() - a << "ms" << endl << endl;
		}
	}

	return 0;
}