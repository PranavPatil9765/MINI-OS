// ProcessManager.cpp
#include "ProcessManager.h"
#include <iostream>

using namespace std;

ProcessManager::ProcessManager() {
    nextPid = 1; // starting PID
}

int ProcessManager::createProcess(const string& name) {
    processes[nextPid] = name;
    cout << "Process '" << name << "' created with PID: " << nextPid << endl;
    return nextPid++;
}

void ProcessManager::listProcesses() {
    cout << "Running processes:" << endl;
    for (auto& p : processes) {
        cout << "PID: " << p.first << " | Name: " << p.second << endl;
    }
}

void ProcessManager::killProcess(int pid) {
    if (processes.erase(pid)) {
        cout << "Process with PID " << pid << " killed." << endl;
    } else {
        cout << "Process not found!" << endl;
    }
}
