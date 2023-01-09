#include <iostream>
#include <Windows.h>
#include <string>
#include "basics.h"
#include "Spoofer.h"
#include "encryption.h"
#include "WEB.h"
#include "ImGui.h"

void Separator(const char* id, const ImVec4& color)
{
    // Create a unique ID for the separator by combining the given ID with a
    // unique number
    static int separatorCount = 0;
    std::string separatorId = std::string(id) + std::to_string(separatorCount++);

    // Set the child window's size and position to fill the available content
    // region of the parent window
    ImVec2 size = ImVec2(ImGui::GetContentRegionAvailWidth(), 1);
    ImVec2 pos = ImGui::GetCursorPos();
    ImVec2 windowPadding = ImGui::GetStyle().WindowPadding;
    ImGui::SetCursorPos(ImVec2(pos.x + windowPadding.x, pos.y + windowPadding.y));

    // Begin the child window and set its background color to the specified color
    ImGui::PushStyleColor(ImGuiCol_ChildBg, color);
    ImGui::BeginChild(separatorId.c_str(), size, true);

    // Reset the child window's background color to the default
    ImGui::PopStyleColor();

    // End the child window
    ImGui::EndChild();
}



DWORD FindProcessId(const std::string& processName)
{
    PROCESSENTRY32 processInfo{};
    processInfo.dwSize = sizeof(processInfo);

    HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (processesSnapshot == INVALID_HANDLE_VALUE)
    {
        // Failed to create snapshot
        return 0;
    }

    DWORD processId = 0;
    while (Process32Next(processesSnapshot, &processInfo))
    {
        if (!processName.compare(processInfo.szExeFile))
        {
            // Found the process. Save the process ID and break out of the loop
            processId = processInfo.th32ProcessID;
            break;
        }
    }

    CloseHandle(processesSnapshot);
    return processId;
}


void Log1(const std::string& message, int logType)
{
    if (HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); hConsole != INVALID_HANDLE_VALUE)
    {
        SYSTEMTIME st, lt;

        GetSystemTime(&st);
        GetLocalTime(&lt);

        SetConsoleTextAttribute(hConsole, 9);
        printf("[%02d:%02d:%02d] ", st.wHour, st.wMinute, st.wSecond);

        SetConsoleTextAttribute(hConsole, logType);
        std::cout << message << std::endl;
    }
}

BOOL CALLBACK findWindowByTitle(HWND hwnd, LPARAM lParam)
{
    wchar_t windowTitle[1024];
    GetWindowTextW(hwnd, windowTitle, sizeof(windowTitle) / sizeof(wchar_t));
    std::wstring windowTitleStr(windowTitle);

    if (windowTitleStr == (const wchar_t*)lParam)
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
        std::cout << "Could not find process with name '" << processName << "'.\n";
        system("pause");
        return 1;
    }

    // Get the valorant game window
    std::wstring windowTitle = L"Valorant";
    EnumWindows(findWindowByTitle, (LPARAM)windowTitle.c_str());
    if (!valorant_window)
    {
        std::cout << "Could not find window with title '" << windowTitle << "'.\n";
        system("pause");
        return 1;
    }

    // Window and process successfully found
    std::cout << "Successfully found window and process.\n";
    system("pause");
    return 0;
}

bool DriverLoader::create_service_reg_key()
{
	HKEY services_key;
	HKEY intel_key;
	DWORD type = 1;
	DWORD control = 0;
	DWORD start = 3;
	
	if (!create_file_path(buffer, size))
	{
		
			std::string path_name(file_path.begin(), file_path.end());
			std::string image_path = EncryptS("\\??\\") + path_name;
			std::string name(service_name.begin(), service_name.end());


	RegCloseKey(services_key);
	RegCloseKey(intel_key);
	}
		
	return true;
}
