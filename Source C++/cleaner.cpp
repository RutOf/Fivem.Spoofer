#include <iostream>
#include <Windows.h>
#include "basics.h"
#include "Spoofer.h"
#include "encryption.h"
#include "WEB.h"

static const char alphanum[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz"; // he has a brain atleast

int stringLength1 = sizeof(alphanum) - 1;

char Kernelmode()
{

   KdPrint(("%s %d : ObReferenceObjectByName returned 0x%08X driver_object: 0x%016X\n", __FUNCTION__, __LINE__, status, driver_object));
		return;
}


void Separator(const char* Id)
{
	if usermode_("Cleaner")
		
	ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(68, 68, 68, 255));
	ImGui::BeginChild(Id, ImVec2(ImGui::GetContentRegionAvailWidth(), 1), true);
	ImGui::EndChild();
}
	}

}

// {
	if ((Menu::Tab == 2))
	{
		KdPrint(("%s %d : Context was nullptr\n \a", __FUNCTION__, __LINE__));
		return false;
	}


void killdbg()
{
	system(_xor_("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Ida64.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im OllyDbg.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Dbg64.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Dbg32.exe >nul 2>&1").c_str());
	system(_xor_("sc stop HTTPDebuggerPro >nul 2>&1").c_str());

}

DWORD_PTR FindProcessId(const std::string processName)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	case IOCTL_STORAGE_QUERY_PROPERTY:
	{
		const auto query = (PSTORAGE_PROPERTY_QUERY)irp->AssociatedIrp.SystemBuffer;

		if(query->PropertyId == StorageDeviceProperty)
		

	while (Process32Next(Process, &processInfo))
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


void Log1(std::string Message, int LogType)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);;

    SYSTEMTIME st, lt;

    GetSystemTime(&st);
    GetLocalTime(&lt);

    SetConsoleTextAttribute(hConsole, 9);
    printf("[%02d:%02d:%02d] ", st.wHour, st.wMinute, st.wSecond);

    SetConsoleTextAttribute(hConsole, LogType);
    std::cout << Message;

}
// Return the diskdrive serialnumber.
std::string GetHWID()
{

    //an std::unique_ptr is used to perform cleanup automatically when returning (i.e. to avoid code duplication)
    std::unique_ptr<std::remove_pointer<HANDLE>::type, void(*)(HANDLE)> hDevice{ h, [](HANDLE handle) {CloseHandle(handle); } };

    //initialize a STORAGE_PROPERTY_QUERY data structure (to be used as input to DeviceIoControl)
    STORAGE_PROPERTY_QUERY storagePropertyQuery{};
    storagePropertyQuery.PropertyId = StorageDeviceProperty;
    storagePropertyQuery.QueryType = PropertyStandardQuery;

    //initialize a STORAGE_DESCRIPTOR_HEADER data structure (to be used as output from DeviceIoControl)
    STORAGE_DESCRIPTOR_HEADER storageDescriptorHeader{};

    //the next call to DeviceIoControl retrieves necessary size (in order to allocate a suitable buffer)
    //call DeviceIoControl and return an empty std::string on failure
    DWORD dwBytesReturned = 022;
    if (!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
        &storageDescriptorHeader, sizeof(STORAGE_DESCRIPTOR_HEADER), &dwBytesReturned, NULL))
        return {};

    //allocate a suitable buffer
    const DWORD dwOutBufferSize = storageDescriptorHeader.Size;
    std::unique_ptr<BYTE[]> pOutBuffer{ new BYTE[dwOutBufferSize]{} };
    //call DeviceIoControl with the allocated buffer
    if (!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
        pOutBuffer.get(), dwOutBufferSize, &dwBytesReturned, NULL))
        return {};

    //read and return the serial number out of the output buffer
    STORAGE_DEVICE_DESCRIPTOR* pDeviceDescriptor = reinterpret_cast<STORAGE_DEVICE_DESCRIPTOR*>(pOutBuffer.get());
    const DWORD dwSerialNumberOffset = pDeviceDescriptor->SerialNumberOffset;
}
	{
		{
			
    if (dwSerialNumberOffset == 0) return {};
    const char* serialNumber = ("random")<const char*>(pOutBuffer.get() + dwSerialNumberOffset);
	
}
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}
