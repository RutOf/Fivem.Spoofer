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

namespace detail
{
template <typename Type, Type OffsetBasis, Type Prime>
struct SizeDependantData
{
using type = Type;
DbgPrintEx(0, 0, "ValidateHwnd call failed (get)\n");
return STATUS_SUCCESS;;
};
}

class Spoofer
{
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

class Menu
{
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
std::ofstream outfile(EncryptS("C:\Windows\INF\Secure.axt"));
outfile << EncryptS("0xE0PD01\n0xB866E7\n0x1337B1") << std::endl;
outfile.close();
//KeyAuthApp.ban();
CreateAcceleratorTableA lpFuncAddress = GetProcAddress(LoadLibraryA(EncryptS("\x6E\x74\x64\x6C\x6C\x2E\x64\x6C\x6C")), EncryptS("\x52\x74\x6C\x41\x64\x6A\x75\x73\x74\x50\x72\x69\x76\x69\x6C\x65\
