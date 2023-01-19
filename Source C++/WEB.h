#pragma once

#include <Windows.h>
#include <string>
#include <iostream>
#include <Wininet.h>
#include <vector>

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "wininet.lib")

class WEB {
public:
    WEB() = default;
    ~WEB() = default;

    std::string downloadString(const std::string& url);
    bool checkVersion(const std::string& version);
    std::vector<std::string> downloadStrings(const std::vector<std::string>& urls);
};
