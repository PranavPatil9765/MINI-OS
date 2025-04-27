// ProcessManager.h
#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <string>
#include <unordered_map>

using namespace std;

class ProcessManager {
private:
    int nextPid;
    unordered_map<int, string> processes; // PID -> process name
public:
    ProcessManager();
    int createProcess(const string& name);
    void listProcesses();
    void killProcess(int pid);
};

#endif // PROCESSMANAGER_H
