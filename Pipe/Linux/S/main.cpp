#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int num, sum = 0;
    string str;
    getline(cin, str);
    stringstream ss(str);
    while (ss >> num) {
        sum += num;
    }
    cout << sum;
    return 0;
}
