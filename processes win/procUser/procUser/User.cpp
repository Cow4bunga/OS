#include<iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <iomanip>
#include <string>
#include<winbase.h>
using namespace std;
#define amen return 0;

LPCSTR killer_dir = "C:\\Programming\\processKiller.exe";

void showActiveProcesses() {
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof(PROCESSENTRY32);
	if (Process32First(snapshot, &pEntry)) {
		cout << setw(10) << left << "PROC_NAME" << setw(10) << "ID" << endl;
		while (Process32Next(snapshot, &pEntry)) {
			wcout << setw(10)<<left << pEntry.szExeFile << setw(5)<<right << pEntry.th32ProcessID << endl;
		}
	}
	CloseHandle(snapshot);
	cout << endl << endl << endl;
}

void killProcesses(string pToKill) {
	char* toKill = (char*)pToKill.c_str();
	STARTUPINFOA sInfo = { 0 };
	PROCESS_INFORMATION pInfo = { 0 };
	if (CreateProcessA(killer_dir, toKill, NULL, NULL, FALSE, 0, NULL, NULL, &sInfo, &pInfo)) {
		WaitForSingleObject(pInfo.hProcess, INFINITE);
	}
}

int main() {
	SetEnvironmentVariableA("PROC_TO_KILL", "TeamViewer,Viber,Telegram");
	showActiveProcesses();
	killProcesses("");
	_putenv("PROC_TO_KILL");
	cout << "Processes finished successfully\n";

	string proc;
	int option;
	cout << "Put 1 to kill by id, 2 to kill by name\n";
	cin >> option;
	switch (option) {
	case 1: {
		int id;
		cin >> id;
		string proc = "--id ";
		proc += to_string(id);
		cout << proc << endl;
		killProcesses(proc);
		break;
	}
	case 2: {
		string name;
		cin >> name;
		string proc = "--name " + name;
		cout << proc << endl;
		killProcesses(proc);
		break;
	}
	default:
		break;
	}

	_putenv("");
	cout << "Processes finished\n";
	amen;
}

