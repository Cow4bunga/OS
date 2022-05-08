#include<iostream>
#include<windows.h>
#include<TlHelp32.h>
#include<stdio.h>
#include<string>
#include<sstream>
#include<winbase.h>

#define amen return 0;

void terminateByName(const char* szExeName) {
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof(PROCESSENTRY32);

	std::string sName(szExeName);
	if (Process32First(hSnapshot, &pEntry)) {
		while (Process32Next(hSnapshot, &pEntry)) {
			std::wstring wst = std::wstring(sName.begin(), sName.end());
			const wchar_t* wstr = wst.c_str();
			if (std::wcscmp(pEntry.szExeFile, wstr) == 0) {
				HANDLE terminate = OpenProcess(PROCESS_TERMINATE, FALSE, pEntry.th32ProcessID);
				if (terminate != NULL) {
					TerminateProcess(terminate, 0);
					CloseHandle(terminate);
				}
			}
		}
	}
	CloseHandle(hSnapshot);
}

//the only difference is that here we compare id(int) instead of name(string)
void terminateByID(int procID) {
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hSnapshot, &pEntry)) {
		while (Process32Next(hSnapshot, &pEntry)) {
			if (pEntry.th32ProcessID == procID) {
				HANDLE terminate = OpenProcess(PROCESS_TERMINATE, 0, pEntry.th32ProcessID);
				if (terminate != NULL) {
					TerminateProcess(terminate, 0);
					CloseHandle(terminate);
				}
			}
		}
	}
	CloseHandle(hSnapshot);
}


int main(int argc, char* argv[]) {
	const CHAR* proc = "PROC_TO_KILL";
	const DWORD buffSize = 65535;
	char buff[buffSize];

	int id = 0;
	GetEnvironmentVariableA(proc, buff, buffSize);
	std::stringstream stream(buff);
	while (stream.getline(buff, buffSize, ',')) {
		std::string str(buff);
		str += ".exe";
		const char* ch = str.c_str();
		terminateByName(ch);
	}

	std::string flag = argc > 1 ? argv[0] : "";
	if (flag == "--name") {
		std::cout << flag << std::endl;
		std::string name(argv[1]);
		name += ".exe";
		const char* filename = name.c_str();
		terminateByName(filename);
	}
	else if (flag == "--id") {
		std::cout << flag << std::endl;
		terminateByID(atoi(argv[1]));
	}

	amen;
}