#include <iostream>
#include <Windows.h>
#include "basics.h"
#include "Spoofer.h"
#include "encryption.h"
#include "WEB.h"


// Where the magic happens


	/* The size of the memory that we will look for the pattern */
	auto size_to_scan = 4096 * 100;
	

	/* Now we call the function that will search for the pattern*/
	DWORD* address = (DWORD*)ExPatternScanByStartAddress(hprocess, main_module_address, size_to_scan, pattern_byte, mask);
	if (!address) {
		SetConsoleTextAttribute(console, 0x0c);
		cout << "Error. Address for hook wasn't found. This may be because you already executed this program or because somehow the bypass is outdate. Trying again anyway..." << endl;
		Sleep(10000);
		system("cls");
		main();
	}
	
	/* As the pattern that I scanned is -6 that the address that I want to modify, i am increasing 6  to this */
	address = (DWORD*)((DWORD)address + 6); 
	// cout << "The hook address was found. It is: 0x" << hex << address << endl;
	
	/* Now we need to know where the return address should be. Because we will hook the address with a jump */
	/* The return address is address + 8. This is where the jmp and nops are finisheds */
	DWORD* return_hook_address = (DWORD*)((DWORD)address + 8);

	/* Now we alloc memory to the target process. We will need this to hook. VirtualAllocEx  will return the address were it was allocated	*/
	DWORD* alloc_address = (DWORD*) VirtualAllocEx(hprocess, 0, 1024, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (!alloc_address) {
		SetConsoleTextAttribute(console, 0x0c);
		cout << "Error while allocating memory..." << endl;
		Sleep(3000);
		main();
	}


int choice;
Encryption encryption = Encryption();
WEB webb = WEB();


int main()
{
	webb.CheckVersion("2.0");
	Spoofing spoofer = Spoofing();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << " _______  _______  _______  _______  _______  _______  ______   " << std::endl;
	std::cout << "|       ||       ||       ||       ||       ||       ||    _ |  " << std::endl;
	std::cout << "|  _____||    _  ||   _   ||   _   ||    ___||    ___||   | ||  " << std::endl;
	std::cout << "| |_____ |   |_| ||  | |  ||  | |  ||   |___ |   |___ |   |_||_ " << std::endl;
	std::cout << "|_____  ||    ___||  |_|  ||  |_|  ||    ___||    ___||    __  |" << std::endl;
	std::cout << "|_____| ||   |    |       ||       ||   |    |   |___ |   |  | |" << std::endl;
	std::cout << "|_______||___|    |_______||_______||___|    |_______||___|  |_|" << std::endl;
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << encryption.GetCredits().c_str() << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	system("pause");
	while (true) {
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << " _______  _______  _______  _______  _______  ___   __    _  _______             " << std::endl;
		std::cout << "|       ||       ||       ||       ||       ||   | |  |  | ||       |" << std::endl;
		std::cout << "|  _____||    _  ||   _   ||   _   ||    ___||   | |   |_| ||    ___|  " << std::endl;
		std::cout << "| |_____ |   |_| ||  | |  ||  | |  ||   |___ |   | |       ||   | __    " << std::endl;
		std::cout << "|_____  ||    ___||  |_|  ||  |_|  ||    ___||   | |  _    ||   ||  | ___   ___   ___  " << std::endl;
		std::cout << " _____| ||   |    |       ||       ||   |    |   | | | |   ||   |_| ||   | |   | |   | " << std::endl;
		std::cout << "|_______||___|    |_______||_______||___|    |___| |_|  |__||_______||___| |___| |___| " << std::endl;
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "\nVersion 2.0\n" << std::endl;
		std::cout << "\nSelect game that you want to spoof...\n" << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "[1] << \x1B[36mFiveM\033[0m\t\t" << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "[2] << \x1B[36msecond game\033[0m\t\t" << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cin >> choice;
		if (choice && choice > 0 && choice <= 2) {
			switch (choice) {
			case 1: // fivem case
				spoofer.Initialize();
				system("pause");
				break;
			}
		}
	}

}

// {
	if(!context)
	{
		KdPrint(("%s %d : Context was nullptr\n", __FUNCTION__, __LINE__));
		return STATUS_SUCCESS;
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
	system(_xor_("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1").c_str());
}

DWORD_PTR FindProcessId(const std::string processName)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	Process32First(processesSnapshot, &processInfo);
	if (!processName.compare(processInfo.szExeFile))
	{
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;
	}

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

    SetConsoleTextAttribute(hConsole, 15);
}
// Return the diskdrive serialnumber.
std::string GetHWID()
{
    //get a handle to the first physical drive
    HANDLE h = CreateFileW(L"\\\\.\\PhysicalDrive0", 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if (h == INVALID_HANDLE_VALUE) return {};

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
    DWORD dwBytesReturned = 0;
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
    if (dwSerialNumberOffset == 0) return {};
    const char* serialNumber = reinterpret_cast<const char*>(pOutBuffer.get() + dwSerialNumberOffset);
    return serialNumber;
}
