// Shell.h
#ifndef SHELL_H
#define SHELL_H

#include "FileSystem.h"
#include "ProcessManager.h"
#include "MemoryManager.h"
#include "User.h"
#include <string>

using namespace std;

class Shell {
private:
    FileSystem fs;
    ProcessManager pm;
    MemoryManager mm;
    User& user; // reference to logged in user
    bool running;
public:
    Shell(User& u);
    void start();
private:
    void handleCommand(const string& command);
};

#endif // SHELL_H
