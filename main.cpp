#include <iostream>
#include "CpuMonitor.h"
#include <thread>
#include <chrono>

int main()
{
    CpuMonitor cpu;

    while (true)
    {
        cpu.pollCpu();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
