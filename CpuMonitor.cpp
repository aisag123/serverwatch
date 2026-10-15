#include "CpuMonitor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void CpuMonitor::getCpuUsage()
{
    std::ifstream f("/proc/stat");
    if (!f.is_open())
    {
        std::cerr << "Failed to open /proc/stat" << std::endl;
        return;
    }

    std::string line;

    if (!std::getline(f, line))
    {
        std::cerr << "Failed to read CPU statistics" << std::endl;
        return;
    }

    std::string label;
    long long user, nice, system, idle, iowait;
    long long irq, softirq, steal, guest, guest_nice;

    std::istringstream stream(line);

    stream >> label >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;

    std::cout << "CPU label: " << label << '\n';
    std::cout << "User: " << user << '\n';
    std::cout << "Nice: " << nice << '\n';
    std::cout << "System: " << system << '\n';
    std::cout << "Idle: " << idle << '\n';
    std::cout << "I/O Wait: " << iowait << '\n';
    std::cout << "IRQ: " << irq << '\n';
    std::cout << "SoftIRQ: " << softirq << '\n';
    std::cout << "Steal: " << steal << '\n';
    std::cout << "Guest: " << guest << '\n';
    std::cout << "Guest Nice: " << guest_nice << '\n';

    long long total;
    long long idle_total;
    double usage;

    total = user + nice + system + idle + iowait + irq + softirq + steal;
    idle_total = idle + iowait;

    if (idle_total == 0)
    {
        std::cerr << "idle total cant be 0!" << std::endl;
        return;
    }

    usage = 100.0 * (total - idle_total) / total;
    std::cout << "total cpu usage: " << usage << '\n';
}