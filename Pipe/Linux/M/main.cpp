#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int num;
    string str;
    getline(cin, str);
    stringstream ss(str);
    while (ss >> num) {
        cout << num * 7 << " ";
    }
    cout << '\n';
    return 0;
}
