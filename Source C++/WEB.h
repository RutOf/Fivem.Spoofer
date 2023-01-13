#pragma once

#include <Windows.h>
#include <string>
#include <iostream>
#include <Wininet.h>

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "wininet.lib")

class WEB {
public:
    WEB() = default;
    ~WEB() = default;

    std::string downloadString(const std::string& url);
    void checkVersion(const std::string& version);
    int fixed();
};
