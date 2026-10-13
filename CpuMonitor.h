#ifndef CPUMONIITOR_h
#define CPUMONIITOR_h

class CpuMonitor
{

public:
    void getCpuUsage();

private:
    double CpuUsage_{0.0};
};

#endif