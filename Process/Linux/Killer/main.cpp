#include <cstdlib>
#include <csignal>
#include <cwchar>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

pid_t getPid(const string& name) {
    char buf[512];
    FILE *cmd_pipe = popen(("pidof -s " + name).c_str(), "r");
    fgets(buf, 512, cmd_pipe);
    pid_t pid = strtoul(buf, nullptr, 10);
    pclose( cmd_pipe );
    return pid;
}

void killProcessPID(const int procID) {
    if (kill(procID, 9)) {
        cout << "couldn't kill process with " << procID << " pid\n";
        exit(0);
    }
    else cout << "process is killed\n";
}

void killProcessName(const string& procName) {
    int pid = getPid(procName);
    killProcessPID(pid);
}

string getEnvVar(string const& key)
{
    char* val = getenv(key.c_str());
    return val == nullptr ? string("") : string(val);
}

vector<string> getProcNames(string procToKill) {
    vector<string> procNames;
    string procName = "";
    int index = 0;
    char curChar = procToKill[0];
    while (curChar != ' ') {
        procName += curChar;
        curChar = procToKill[++index];
        if (curChar == ',') {
            procNames.push_back(procName);
            procName = "";
            curChar = procToKill[++index];
        }
    }
    procNames.push_back(procName);
    return procNames;
}

int main(int argc, char* argv[])
{
    string procToKill = getEnvVar("PROC_TO_KILL");
    vector<string> procs = getProcNames(procToKill);
    if (!procToKill.empty()) {
        for (string procName: procs) {
            killProcessName(procName);
        }
    }

    string flag = argc > 1 ? argv[1] : "";
    if (argc == 3 && flag == "--name") {
        string procName = argv[2];
        killProcessName(procName);
    }
    else if (argc == 3 && flag == "--id") {
        string procIDString = argv[2];
        killProcessPID(stoi(procIDString));
    }
    return 0;
}
