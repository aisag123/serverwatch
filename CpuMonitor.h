#ifndef CPUMONIITOR_h
#define CPUMONIITOR_h

struct CpuStats
{
    long long user;
    long long nice;
    long long system;
    long long idle;
    long long iowait;
    long long irq;
    long long softirq;
    long long steal;
};

class CpuMonitor
{

public:
    void pollCpu();
    CpuStats getCpuStats();

private:
    double CpuUsage_{0.0};
};

#endif