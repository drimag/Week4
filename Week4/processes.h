#pragma once

void printProcess();

struct Process {
    int pid;
    std::string type;
    std::string name;
    std::string gpuMemory;
};