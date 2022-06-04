#include <iostream>
#include <unistd.h>

using namespace std;

string procPaths[] = {"~/OS-labs/Pipe/Linux/M/cmake-build-debug/M",
                      "~/OS-labs/Pipe/Linux/A/cmake-build-debug/A",
                      "~/OS-labs/Pipe/Linux/P/cmake-build-debug/P",
                      "~/OS-labs/Pipe/Linux/S/cmake-build-debug/S"};

int main() {
    int p[3], pid;
    cout << "insert numbers. -1 means end of line\n";
    for (int i = 0; i < 3; i++) {
        pipe(p);
        pid = fork();
        if (!pid) {
            dup2(p[1], 1);
            system(procPaths[i].c_str());
            exit(0);
        }
        dup2(p[0],0);
        close(p[1]);
    }
    system(procPaths[3].c_str());
    return 0;
}
