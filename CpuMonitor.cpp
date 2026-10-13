#include "CpuMonitor.h"
#include <iostream>
#include <fstream>
#include <string>

void CpuMonitor::getCpuUsage()
{
    std::ifstream f("/proc/stat");
    if (!f.is_open())
    {
        std::cerr << "Failed to open /proc/stat" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(f, line))
    {
        std::cout << "cpu test: " << line << std::endl;
    }
}