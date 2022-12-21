#include <string>
#include <windows.h>
#include <wininet.h>
#include <dxgi1_6.h>
#include <d3d11_5.h>

#include "WEB.h"

std::string WEB::replaceAll(std::string subject, const std::string& search,
                            const std::string& replace)
{
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos)
    {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

std::string WEB::downloadString(const std::string& URL)
{
    HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
    HINTERNET urlFile;
    std::string rtn;
    if (interwebs)
    {
        urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
        if (urlFile)
        {
            char buffer[2000];
            DWORD bytesRead;
            do
            {
                InternetReadFile(urlFile, buffer, 2000, &bytesRead);
                rtn.append(buffer, bytesRead);
                memset(buffer, 0, 2000);
            } while (bytesRead);
            InternetCloseHandle(urlFile);
        }
        InternetCloseHandle(interwebs);
    }
    return replaceAll(rtn, "|n", "\r\n");
}

HRESULT WEB::resizeHook(IDXGISwapChain* swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags)
{
    ImGui_ImplDX11_Shutdown();
    renderTargetView->Release();
    immediateContext->Release();
    device->Release();
    device = nullptr;

    return resizeOriginal(swapChain, bufferCount, width, height, newFormat, swapChainFlags);
}
