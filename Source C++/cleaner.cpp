#include <iostream>
#include <Windows.h>
#include <string>
#include "basics.h"
#include "Spoofer.h"
#include "encryption.h"
#include "WEB.h"
#include "ImGui.h"

void DrawColoredSeparator(const std::string& id, const ImVec4& color) {
  static int separatorCount = 0;
  std::string separatorId = id + std::to_string(separatorCount++);

  ImGui::PushID(separatorId.c_str());

  ImVec2 windowPadding = ImGui::GetStyle().WindowPadding;
  ImVec2 cursorPos = ImGui::GetCursorPos();
  ImVec2 regionSize = ImGui::GetContentRegionAvail();

  ImGui::PushStyleColor(ImGuiCol_Separator, color);
  ImGui::SetCursorPos(ImVec2(cursorPos.x + windowPadding.x, cursorPos.y + windowPadding.y));
  ImGui::Separator();
  ImGui::PopStyleColor();

  ImGui::SetCursorPos(ImVec2(cursorPos.x, cursorPos.y + windowPadding.y + regionSize.y));

  ImGui::PopID();
}



DWORD FindProcessId(const std::wstring& processName)
{
    DWORD processId = 0;
    HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
        return 0;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hProcessSnap, &pe32))
    {
        do
        {
            if (_tcsicmp(pe32.szExeFile, processName.c_str()) == 0)
            {
                processId = pe32.th32ProcessID;
                break;
            }
        } while (Process32Next(hProcessSnap, &pe32));
    }

    CloseHandle(hProcessSnap);
    return processId;
}

void LogMessage(const std::string& message, int logType)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole != INVALID_HANDLE_VALUE)
    {
        SYSTEMTIME st, lt;
        GetLocalTime(&lt);

        std::cout << "[" << std::setfill('0') << std::setw(2) << lt.wHour << ":"
                  << std::setfill('0') << std::setw(2) << lt.wMinute << ":"
                  << std::setfill('0') << std::setw(2) << lt.wSecond << "] ";

        SetConsoleTextAttribute(hConsole, logType);
        std::cout << message << std::endl;

        SetConsoleTextAttribute(hConsole, 7);
    }
}


BOOL CALLBACK findWindowByTitle(HWND hwnd, LPARAM lParam)
{
    constexpr int buffer_size = 1024;
    wchar_t window_title[buffer_size];
    GetWindowTextW(hwnd, window_title, buffer_size);

    if (lstrcmpW(window_title, reinterpret_cast<LPCWSTR>(lParam)) == 0)
    {
        valorant_window = hwnd;
        return FALSE;
    }

    return TRUE;
}

		
		
DWORD g_pid = 0;
HWND valorant_window = nullptr;

DWORD getProcessIdByName(const std::wstring& processName)
{
    DWORD processId = 0;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32W process;
        ZeroMemory(&process, sizeof(process));
        process.dwSize = sizeof(process);

        if (Process32FirstW(snapshot, &process))
        {
            do
            {
                if (processName == process.szExeFile)
                {
                    processId = process.th32ProcessID;
                    break;
                }
            } while (Process32NextW(snapshot, &process));
        }

        CloseHandle(snapshot);
    }
    return processId;
}

BOOL CALLBACK findWindowByTitle(HWND hwnd, LPARAM lParam)
{
    wchar_t windowTitle[256];
    GetWindowTextW(hwnd, windowTitle, sizeof(windowTitle) / sizeof(windowTitle[0]));

    if (wcscmp(windowTitle, (wchar_t*)lParam) == 0)
    {
        valorant_window = hwnd;
        return FALSE;
    }

    return TRUE;
}

int main()
{
    // Search for the process and save the process id
    std::wstring processName = L"val.exe";
    g_pid = getProcessIdByName(processName);
    if (!g_pid)
    {
        std::wcout << "Could not find process with name '" << processName << "'.\n";
        system("pause");
        return 1;
    }

    // Get the valorant game window
    std::wstring windowTitle = L"Valorant";
    EnumWindows(findWindowByTitle, (LPARAM)windowTitle.c_str());
    if (!valorant_window)
    {
        std::wcout << "Could not find window with title '" << windowTitle << "'.\n";
        system("pause");
        return 1;
    }

    //window and process successfully found, do whatever you want to do with the window and process here
    std::wcout << "Successfully found window and process.\n";
    system("pause");
    return 0;
}
