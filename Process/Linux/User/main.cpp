#include <stdlib.h>
#include <iostream>

using namespace std;
string killerPath = "~/OS-labs/Process/Linux/Killer/cmake-build-debug/Killer";

int main() {
    string procToKillValue;
    cout << "insert value of PROC_TO_KILL (last element should be space): ";
    cin >> procToKillValue;
    setenv("PROC_TO_KILL", procToKillValue.c_str(), 0);

    cout << "1 - kill processes by PID\n2 - kill processes by name\n";
    int flag;
    cin >> flag;
    switch (flag)
    {
        case 1: {
            cout << "insert PID: ";
            int pid;
            cin >> pid;
            string command = "--id " + pid;
            system((killerPath + " " + command).c_str());
            break;
        }
        case 2: {
            cout << "insert process name: ";
            string name;
            cin >> name;
            string command = "--name " + name;
            system((killerPath + " " + command).c_str());
            break;
        }
        default:
            break;
    }

    unsetenv("PROC_TO_KILL=");
    return 0;
}