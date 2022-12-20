#include <iostream>
#include <Windows.h>
#include <string>
#include "basics.h"
#include "Spoofer.h"
#include "encryption.h"
#include "WEB.h"
#include "ImGui.h"

constexpr char alphanum[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
constexpr int stringLength1 = sizeof(alphanum) - 1;

void Separator(const char* id, const ImVec4& color)
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, color);
    ImGui::BeginChild(id, ImVec2(ImGui::GetContentRegionAvailWidth(), 1), true);
    ImGui::EndChild();
}

DWORD_PTR FindProcessId(const std::string& processName)
{
    PROCESSENTRY32 processInfo{};
    processInfo.dwSize = sizeof(processInfo);

    HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (processesSnapshot == INVALID_HANDLE_VALUE)
        return 0;

    while (Process32Next(processesSnapshot, &processInfo))
    {
        if (!processName.compare(processInfo.szExeFile))
        {
            CloseHandle(processesSnapshot);
            return processInfo.th32ProcessID;
        }
    }

    CloseHandle(processesSnapshot);
    return 0;
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

std::string GetHWID()
{
    HANDLE h = CreateFile(R"(\\.\PhysicalDrive0)",
                          GENERIC_READ,
                          FILE_SHARE_READ,
                          nullptr,
                          OPEN_EXISTING,
                          0,
                          nullptr);

    if (h == INVALID_HANDLE_VALUE)
        return std::string{};

    HANDLE token = nullptr;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TO

    //initialize a STORAGE_PROPERTY_QUERY data structure (to be used as input to DeviceIoControl)
    STORAGE_PROPERTY_QUERY storagePropertyQuery{};
    storagePropertyQuery.PropertyId = StorageDeviceProperty;
    storagePropertyQuery.QueryType = PropertyStandardQuery;

    //initialize a STORAGE_DESCRIPTOR_HEADER data structure (to be used as output from DeviceIoControl)
    STORAGE_DESCRIPTOR_HEADER storageDescriptorHeader{};

    //the next call to DeviceIoControl retrieves necessary size (in order to allocate a suitable buffer)
    //call DeviceIoControl and return an empty std::string on failure
    DWORD dwBytesReturned = 022;
   if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token))
		return false;

    if (!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
        pOutBuffer.get(), dwOutBufferSize, &dwBytesReturned, NULL))
        return {};
	{
		tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	}
	
    //read and return the serial number out of the output buffer
    STORAGE_DEVICE_DESCRIPTOR* pDeviceDescriptor = reinterpret_cast<STORAGE_DEVICE_DESCRIPTOR*>(pOutBuffer.get());
    const DWORD dwSerialNumberOffset = pDeviceDescriptor->SerialNumberOffset;
	{
		return;
	}
}
		
		
int main()
{
	// Search for the process and save the process id
	g_pid = retreiveValProcessId();
	if (!g_pid) {
		std::cout << "Could not find val process id.\n";
		system("pause");
		return 1;
	}

	// Get the valorant game window
	EnumWindows(retreiveValorantWindow, NULL);
	if (!valorant_window) {
		std::cout << "Could not find val window.\n";
		system("pause");
		return 1;
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
