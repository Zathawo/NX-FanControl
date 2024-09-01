#include "utils.hpp"

u64 IsRunning() {
    u64 pid = 0;
    pmdmntGetProcessId(&pid, SysFanControlID);
    return pid;
}

void RemoveB2F()
{
    remove(SysFanControlB2FPath);
}

void CreateB2F()
{
    FILE *f = fopen(SysFanControlB2FPath, "w");
    fclose(f);
}