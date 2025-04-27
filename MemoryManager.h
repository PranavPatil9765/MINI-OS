// MemoryManager.h
#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <unordered_map>
#include <string>

using namespace std;

class MemoryManager {
private:
    int totalMemory;
    int usedMemory;
    unordered_map<string, int> allocations; // app name -> memory used
public:
    MemoryManager(int total = 1024); // default 1 KB memory
    bool allocate(string appName, int size);
    void free(string appName);
    void memoryStatus();
};

#endif // MEMORYMANAGER_H
