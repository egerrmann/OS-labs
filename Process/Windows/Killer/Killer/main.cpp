#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <cstdlib>
#include <cwchar>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool killProcess(const wchar_t* procName)
{
    bool isKilled = false;
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof(pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);
    while (hRes)
    {
        if (wcscmp(pEntry.szExeFile, procName) == 0)
        {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
                (DWORD)pEntry.th32ProcessID);
            if (hProcess != NULL)
            {
                TerminateProcess(hProcess, 0);
                CloseHandle(hProcess);
                isKilled = true;
            }
        }
        hRes = Process32Next(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);
    if (isKilled) return true;
    else return false;
}

bool killProcess(const DWORD procID)
{
    bool isKilled = false;
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof(pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);
    while (hRes)
    {
        if (pEntry.th32ProcessID == procID)
        {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
                (DWORD)pEntry.th32ProcessID);
            if (hProcess != NULL)
            {
                TerminateProcess(hProcess, 0);
                CloseHandle(hProcess);
                isKilled = true;
            }
        }
        hRes = Process32Next(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);
    if (isKilled) return true;
    else return false;
}

string getEnvVar(string const& key)
{
    char* val = getenv(key.c_str());
    return val == NULL ? string("") : string(val);
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
    for (string procName : procs) {
        wstring wsProcName = wstring(procName.begin(), procName.end());
        if (killProcess(wsProcName.c_str()))
            cout << "process with " << procName << " name is killed\n";
        else
            cout << "couldn't find process with " << procName << " name\n";
    }

    string flag = argc > 1 ? argv[1] : "";
    if (argc == 3 && flag == "--name") {
        string procName = argv[2];
        wstring wsProcName = wstring(procName.begin(), procName.end());
        if (killProcess(wsProcName.c_str()))
            cout << "process with " << procName << " name is killed\n";
        else
            cout << "couldn't find process with " << procName << " name\n";
    }
    else if (argc == 3 && flag == "--id") {
        string procIDString = argv[2];
        DWORD procID = stoi(procIDString);
        if (killProcess(procID))
            cout << "process with " << procID << " PID is killed\n";
        else
            cout << "couldn't find process with " << procID << " PID\n";
    }
    return 0;
}
