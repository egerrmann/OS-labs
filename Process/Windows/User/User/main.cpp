#include <stdlib.h>
#include <iostream>
#include <Windows.h>

using namespace std;
LPCSTR killerPath = "C:\\Studying\\Programming\\C++\\Derevyago\\2nd course\\OS labs\\Process\\Windows\\Killer\\x64\\Debug\\Killer.exe";

int main() {
	string procToKillValue;
	cout << "insert value of PROC_TO_KILL (last element should be space): ";
	cin >> procToKillValue;
	wstring wstrProcToKillValue = wstring(procToKillValue.begin(), procToKillValue.end());
	const wchar_t* widecstrProcToKillValue = wstrProcToKillValue.c_str();
	SetEnvironmentVariable(L"PROC_TO_KILL", widecstrProcToKillValue);

	cout << "1 - kill processes by PID\n2 - kill processes by name\n";
	int flag;
	cin >> flag;
	switch (flag)
	{
	case 1: {
		cout << "insert PID: ";
		int pid;
		cin >> pid;

		STARTUPINFOA startupinfo = { 0 };
		PROCESS_INFORMATION procinfo = { 0 };

		string command = "--id " + pid;
		char* input = (char*)command.c_str();

		CreateProcessA(killerPath, input, NULL, NULL, FALSE, 0, NULL, NULL, &startupinfo, &procinfo);
		break;
	}
	case 2: {
		cout << "insert process name: ";
		string name;
		cin >> name;

		STARTUPINFOA startupinfo = { 0 };
		PROCESS_INFORMATION procinfo = { 0 };

		string command = "--name " + name;
		char* input = (char*)command.c_str();

		CreateProcessA(killerPath, input, NULL, NULL, FALSE, 0, NULL, NULL, &startupinfo, &procinfo);
		break;
	}
	default:
		break;
	}

	_putenv("PROC_TO_KILL=");
	return 0;
}