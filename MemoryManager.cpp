// MemoryManager.cpp
#include "MemoryManager.h"
#include <iostream>

using namespace std;

MemoryManager::MemoryManager(int total) {
    totalMemory = total;
    usedMemory = 0;
}

bool MemoryManager::allocate(string appName, int size) {
    if (usedMemory + size > totalMemory) {
        cout << "Not enough memory to allocate for " << appName << "!" << endl;
        return false;
    }
    allocations[appName] = size;
    usedMemory += size;
    cout << "Allocated " << size << " units to " << appName << "." << endl;
    return true;
}

void MemoryManager::free(string appName) {
    auto it = allocations.find(appName);
    if (it != allocations.end()) {
        usedMemory -= it->second;
        cout << "Freed " << it->second << " units from " << appName << "." << endl;
        allocations.erase(it);
    } else {
        cout << "No such allocation found!" << endl;
    }
}

void MemoryManager::memoryStatus() {
    cout << "Memory Usage: " << usedMemory << "/" << totalMemory << endl;
}
