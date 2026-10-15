#include "CpuMonitor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

void CpuMonitor::pollCpu()
{
    CpuStats first = getCpuStats();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    CpuStats second = getCpuStats();

    long long total1 =
        first.user + first.nice + first.system +
        first.idle + first.iowait + first.irq +
        first.softirq + first.steal;

    long long total2 =
        second.user + second.nice + second.system +
        second.idle + second.iowait + second.irq +
        second.softirq + second.steal;

    long long idle1 = first.idle + first.iowait;
    long long idle2 = second.idle + second.iowait;

    long long totalDelta = total2 - total1;
    long long idleDelta = idle2 - idle1;

    double usage = 0.0;

    if (totalDelta > 0)
    {
        usage = 100.0 * (totalDelta - idleDelta) / totalDelta;
    }

    std::cout << "CPU usage: " << usage << "%\n";
}

CpuStats CpuMonitor::getCpuStats()
{
    std::ifstream file("/proc/stat");

    std::string label;
    CpuStats stats{};

    if (file.is_open())
    {
        file >> label >> stats.user >> stats.nice >> stats.system >> stats.idle >> stats.iowait >> stats.irq >> stats.softirq >> stats.steal;
    }

    return stats;
}