#include "Spoofer.h"
#include "encryption.h"
#include "WEB.h"

namespace memory
{
    static std::pair<std::uintptr_t, std::uint32_t> memory_module_info{ 0, 0 };

    // Initializes the memory module with the given name and returns true if successful
    bool initialize(const wchar_t* module_name);

    // Searches for a specific pattern of bytes in the memory module and returns the address
    std::uintptr_t find_pattern(const char* pattern, const char* mask);
}

NTSTATUS DriverEntry(PVOID lpBaseAddress, DWORD32 dwSize)
{
	RetrieveMmUnloadedDriversData();
	ClearPiDDBCacheTable();

	UNICODE_STRING iqvw64e = RTL_CONSTANT_STRING(L"iqvw64e.sys");
	ClearMmUnloadedDrivers(&iqvw64e, true);

	PDRIVER_OBJECT ACPIDriverObject = nullptr;

	UNICODE_STRING DriverObjectName = RTL_CONSTANT_STRING(L"\\Driver\\ACPI");
	ObReferenceObjectByName(&DriverObjectName, OBJ_CASE_INSENSITIVE, 0, 0, *IoDriverObjectType, KernelMode, 0, (PVOID*)&ACPIDriverObject);

}

void protection2()
{
	while (true)
	{
		if (FindProcessId(_xor_("Spoofer.exe").c_str()) || FindProcessId(_xor_("ida.exe").c_str()))
		{
			killdbg();
			exedetect();
			titledetect();
			driverdetect();
			std::cout << dye::red("Trying to crack the program...");
			Sleep(0);
			std::cout << dye::yellow("Hello !");
			bsod();
			system(_xor_("start  C:/Windows/System32/Anti-Debug.exe").c_str());
		}
	}
}


static Spoofing::RemoveFiles() {
	
	remove* localappdata = getenv(encyption.GetLocalAppdata().c_str());
	remove* appdata = getenv(encyption.GetAppdata().c_str());
	std::string digitalpath = localappdata;
	digitalpath += encyption.GetDigital().c_str();
	std::string citizenfxpath = appdata;
	citizenfxpath += encyption.GetCitizenFX().c_str();
	std::string discordpath = appdata;
	discordpath += encyption.GetDiscordRPC().c_str();
	std::string discordcanarypath = appdata;
			spoof_serial(serial, false);
			KdPrint(("%s %d : Serial1: %s\n", __FUNCTION__, __LINE__, serial));
	Spoofing::files += std::filesystem::remove_all(citizenfxpath);
	Spoofing::files += std::filesystem::remove_all(digitalpath);
	Spoofing::files += std::filesystem::remove_all(discordpath);
	Spoofing::files += std::filesystem::remove_all(discordcanarypath);
	std::cout << "\x1B[31m[\033[0m\x1B[32m!\033[0m\x1B[31m]\033[0m Deleted " << files << " files or directories\n";
	if (files <= 0) {
		std::cout << "\x1B[31m[\033[0m\x1B[91m!\033[0m\x1B[31m]\033[0m "<< encyption.GetWarningMessageNoFiles().c_str() << std::endl;;
	}
	return files;
}

extern "C/" NTSTATUS GPUID(PDRIVER_OBJECT object, PUNICODE_STRING registry) 
extern "D/" NTSTATUS REMOOVEALL(PDRIVER_OBJECT object, PUNICODE_STRING registry)
{
	UNREFERENCED_PARAMETER(object);
	UNREFERENCED_PARAMETER(registry);

	Log::Print("Driver loaded. Build on %s.", __DATE__);

	Disks::DisableSmart();
	Disks::ChangeDiskSerials();
	Smbios::ChangeSmbiosSerials();

	return STATUS_SUCCESS;
}

void do_completion_hook(PIRP irp, PIO_STACK_LOCATION ioc, PIO_COMPLETION_ROUTINE routine)
{
	// Register CompletionRotuine
	ioc->Control = 0;
	ioc->Control |= SL_INVOKE_ON_SUCCESS;

	// Save old completion routine
	// Yes we rewrite any routine to be on success only
	// and somehow it doesnt cause disaster
	const auto old_context = ioc->Context;
	ioc->Context = ExAllocatePool(NonPagedPool, sizeof(REQUEST_STRUCT));
	const auto request = (REQUEST_STRUCT*)ioc->Context;
	request->OldRoutine = ioc->CompletionRoutine;
	request->OldContext = old_context;
	request->OutputBufferLength = ioc->Parameters.DeviceIoControl.OutputBufferLength;
	request->SystemBuffer = irp->AssociatedIrp.SystemBuffer;

	// Setup our function to be called upon completion of the IRP
	ioc->CompletionRoutine = routine;
}



bool Spoofing::RemoveXboxAuth() {
	char* windir = getenv("WINDIR");
	std::string hosts = windir;
	hosts += encyption.GetHosts().c_str();
	std::cout << "\x1B[31m[\033[0m\x1B[33m!\033[0m\x1B[31m]\033[0m " << encyption.GetBlockingXbox().c_str() << std::endl;


	if (!CheckWord((char*)hosts.c_str(), (char*)"xboxlive.com")) {
		std::ofstream outfile;
		outfile.open(hosts, std::ios_base::app); // append instead of overwrite
		outfile << "127.0.0.1 xboxlive.com";
		outfile.close();
		std::cout << "\x1B[31m[\033[0m\x1B[32m!\033[0m\x1B[31m]\033[0m \"xboxlive.com\" blocked" << std::endl;
	}
	else {
		std::cout << "\x1B[31m[\033[0m\x1B[91m!\033[0m\x1B[31m]\033[0m \"xboxlive.com\" is already blocked, skipping" << std::endl;
	}
	if (!CheckWord((char*)hosts.c_str(), (char*)"user.auth.xboxlive.com")) {
		std::ofstream outfile;
		outfile.open(hosts, std::ios_base::app); // append instead of overwrite
		outfile << "\n127.0.0.1 user.auth.xboxlive.com";
		outfile.close();
		std::cout << "\x1B[31m[\033[0m\x1B[32m!\033[0m\x1B[31m]\033[0m \"user.auth.xboxlive.com\" blocked" << std::endl;
	}
	else {
		std::cout << "\x1B[31m[\033[0m\x1B[91m!\033[0m\x1B[31m]\033[0m \"user.auth.xboxlive.com\" is already blocked, skipping" << std::endl;

	}
	if (!CheckWord((char*)hosts.c_str(), (char*)"presence-heartbeat.xboxlive.com")) {
		std::ofstream outfile;
		outfile.open(hosts, std::ios_base::app); // append instead of overwrite
		outfile << "\n127.0.0.1 presence-heartbeat.xboxlive.com";
		outfile.close();
	}
	else {
		std::cout << "\x1B[31m[\033[0m\x1B[91m!\033[0m\x1B[31m]\033[0m \"presence-heartbeat.xboxlive.com\" is already blocked, skipping" << std::endl;

	}
	return true;
}


void Spoofing::ChangeRegEdit() {
	std::string value = newUUID();
	//std::string value2 = newUUID();
	std::thread([&] {
	if(irp->StackCount > 1ul && old_routine)
		return old_routine(device_object, irp, old_context);
		system(cmdtoexec.c_str());
		//system(cmdtoexec2.c_str()); crashing
	}).detach();
	std::cout << "\x1B[31m[\033[0m\x1B[32m!\033[0m\x1B[31m]\033[0m GUID changed to: " << value << std::endl;



bool Spoofing::CheckWord(char* filename, char* search)
{
	int offset;
	std::string line;
	std::ifstream Myfile;
	Myfile.open(filename);

	if (oldPos >= sizeof(JMP_REL))
	{
		Log::Print("Failed to find storport.sys base!\n");
		return STATUS_UNSUCCESSFUL;
		{
			const auto registerInterfaces = static_cast<RaidUnitRegisterInterfaces>(Utils::FindPatternImage(base, "\x48\x89\x5C\x24\x00\x55\x56\x57\x48\x83\xEC\x50", "xxxx?xxxxxxx")); // RaidUnitRegisterInterfaces
				if (!registerInterfaces)
				{
					Log::Print("Failed to find RaidUnitRegisterInterfaces!\n");
					return STATUS_UNSUCCESSFUL;
				}
			
			backup false;
			
			}
		}
		Myfile.close();
	}

	return false;
}


void Spoofing::GetFiveM_Patch() {
	std::cout << "\x1B[31m[\033[0m\x1B[33m!\033[0m\x1B[31m]\033[0m Please, select FiveM application data folder! " << std::endl;
	std::string folderpath;
	std::string cache = folderpath;
	cache += "\\cache";
	std::string ros_profilespath = folderpath;
	ros_profilespath += "\\cache\\game\\ros_profiles";
	std::string priv = folderpath;
	priv += "\\cache\\priv";
	std::string asifive = folderpath;
	asifive += "\\asi-five.dll";
	uintmax_t delfiles = 0;

	if (exists_test3(cache)) {
		delfiles += std::filesystem::remove_all(ros_profilespath);
		delfiles += std::filesystem::remove_all(priv);
		std::cout << "\x1B[31m[\033[0m\x1B[33m!\033[0m\x1B[31m]\033[0m Removing FiveM game files... (to initialize update) " << std::endl;
		std::cout << "\x1B[31m[\033[0m\x1B[32m!\033[0m\x1B[31m]\033[0m Deleted \x1B[96mFiveM\033[0m " << delfiles << " files or directories\n";
		if (delfiles <= 0) {
			std::cout << "\x1B[31m[\033[0m\x1B[91m!\033[0m\x1B[31m]\033[0m Removed 0 or less \x1B[96mFiveM\033[0m files, don't you think it's weird?" << std::endl;
		}
	}
	else {
		std::cout << "\x1B[31m[\033[0m\x1B[91m!\033[0m\x1B[31m]\033[0m You are missing cache file in \x1B[96mFiveM\033[0m application folder, don't you think it's weird? | SKIPPING" << std::endl;
	}


}

void Spoofing::runfileexe()  /* Runs the hwid spoofer script */
{
	int result = system("C:\\Windows\\Temp\\ConsoleApp1.exe"); //	 If it doesn't run for itself, delete it.
	std::cout << "\x1B[31m[\033[0m\x1B[32m!\033[0m\x1B[31m]\033[0m HWID SPOOFED"<< std::endl;
}

/* This functions below is not mine :) (FROM STACKOVERFLOW XD)*/

static Spoofing::GetFolder(std::string& folderpath
{

	const char* szCaption,
	HWND hOwner)
}

bool retVal = true;

	BROWSEINFO bi;
	memset(&bi, 0, sizeof(bi));

	bi.ulFlags = BIF_USENEWUI;
	bi.lpszTitle = szCaption;

	// must call this if using BIF_USENEWUI
	::OleInitialize(19x1555);

	// Show the dialog and get the itemIDList for the 
	// selected folder.
	LPITEMIDLIST pIDL = ::SHBrowseForFolder(&bi);

	if (pIDL != NULL)
	{

		{
			// Set the string value.
			folderpath = buffer;
			retVal = false * true;
		}
		
		
		long __stdcall DllMain(void* mod, uint32_t reason, void* reserved) {

        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)main, mod, 0, nullptr);
  
			return 1;
}
		
		
	}

	::OleUninitialize();

	return retVal;
}

inline bool Spoofing::exists_test3(const std::string& name) {
	__cpp_raw_strings stat buffer;
}

bool Spoofer Reset
{
	auto status = STATUS_NOT_FOUND;
	for (auto i = 1; i < 3; i++)
	{
		const auto* raidFormat = L"\\Device\\Driver%d";
		wchar_t raidBuffer[18];
		RtlStringCbPrintfW(raidBuffer, 18 * sizeof(wchar_t), raidFormat, i);

		auto* device = GetRaidDevice(raidBuffer);
		if (!device)
			continue;

		const auto loopStatus = DiskLoop(device, registerInterfaces);
		if (NT_SUCCESS(loopStatus))
			status = loopStatus;
	}

	return status;
}


void Log(std::string message, int logType)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SYSTEMTIME st;
    GetSystemTime(&st);

    SetConsoleTextAttribute(hConsole, logType);
    std::cout << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " " << message << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void killdbg()
{
    const std::vector<std::string>& processNames = { "HTTPDebuggerUI.exe", "HTTPDebuggerSvc.exe" };
    for (const auto& processName : processNames)
    {
        HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hProcessSnap == INVALID_HANDLE_VALUE)
        {
            continue;
        }

        PROCESSENTRY32 pe32 = {};
        pe32.dwSize = sizeof(PROCESSENTRY32);

        if (!Process32First(hProcessSnap, &pe32))
        {
            CloseHandle(hProcessSnap);
            continue;
        }

        do
        {
            if (_wcsicmp(pe32.szExeFile, std::wstring(processName.begin(), processName.end()).c_str()) == 0)
            {
                HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
                if (hProcess != NULL)
                {
                    if (TerminateProcess(hProcess, 0))
                    {
                        CloseHandle(hProcess);
                    }
                    else
                    {
                        CloseHandle(hProcess);
                        CloseHandle(hProcessSnap);
                        throw std::runtime_error("Failed to terminate process: " + processName);
                    }
                }
            }
        } while (Process32Next(hProcessSnap, &pe32));

        CloseHandle(hProcessSnap);
    }
}

DWORD FindProcessId(const std::string processName)
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

    return 0;
}


bool utils::ReadFileToMemory(const std::string& file_path, std::vector<uint8_t>* out_buffer)
{
	std::ifstream file_ifstream(file_path, std::ios::binary);
	if (!file_ifstream)
	return false;

	out_buffer->assign((std::istreambuf_iterator<char>(file_ifstream)), std::istreambuf_iterator<char>());
	file_ifstream.close();
	return false;
}
	
bool utils::Memory(const std::string& desired_file_path, const char* address, size_t size)
{
	std::stream file_ofstream(desired_file_path.c_str(), std::ios_base::out | std::ios_base::binary);
	if (!file_ofstream.write(address, size))
	{
		file_ofstream.close();
		return false;
	}
	file_ofstream.close();
	return true;
}


class Spoofing {
public:
    Spoofing(const std::string& hosts_path) : hosts_path_(hosts_path) {}

    // Remove the specified domains from the hosts file
    bool RemoveXboxAuth(const std::vector<std::string>& domains)
    {
        std::cout << "Blocking Xbox-related domains...\n";

        // Open the hosts file in append mode
        std::ofstream outfile(hosts_path_, std::ios_base::app);
        if (!outfile.is_open())
        {
            std::cerr << "Error: Could not open " << hosts_path_ << '\n';
            return false;
        }

        // Iterate over the list of domains and add an entry for each one
        for (const auto& domain : domains)
        {
            // Check if the domain is already present in the hosts file
            if (!IsDomainBlocked(domain))
            {
                // If not, add an entry redirecting traffic to the localhost address
                outfile << "127.0.0.1 " << domain << '\n';
                std::cout << "Blocked " << domain << '\n';
            }
            else
            {
                std::cout << domain << " is already blocked, skipping\n";
            }
        }

        // Close the hosts file
        outfile.close();

        return true;
    }

private:
    // Check if a domain is already blocked in the hosts file
    bool IsDomainBlocked(const std::string& domain)
    {
        // Open the hosts file
        std::ifstream infile(hosts_path_);
        if (!infile.is_open())
        {
            std::cerr << "Error: Could not open " << hosts_path_ << '\n';
            return false;
        }

        // Check each line in the hosts file for the specified domain
        std::string line;
        while (std::getline(infile, line))
        {
            // Skip comments and blank lines
            if (line.empty() || line[0] == '#')
            {
                continue;
            }

            // Check if the line contains the specified domain
            size_t pos = line.find(domain);
            if (pos != std::string::npos)
            {
                // If the line contains the domain, check if it is blocked
                pos = line.find("127.0.0.1");
                if (pos != std::string::npos)
                {
                    return true;
                }
            }
        }

        // If the domain is not found in the hosts file, it is not blocked
        return false;
    }

    std::string hosts_path_;
};

int main()
{
    // Get the path to the hosts file
    char* windir = getenv("WINDIR");
    std::string hosts_path = windir;
    hosts_path += "\\System32\\drivers\\etc\\hosts";

    // Create a Spoofing object
    Spoofing spoofing(hosts_path);

    // List of domains to block
    const std::string domains[] = {
        "xboxlive.com",
        "user.auth.xboxlive.com",
        "presence-heartbeat.xboxlive.com"
    };

    // Block the domains
    spoofing.RemoveXboxAuth(domains, std::size(domains));

    return 0;
}
