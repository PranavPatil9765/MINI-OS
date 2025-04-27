// Shell.cpp
#include "Shell.h"
#include "Utils.h"
#include <iostream>

using namespace std;

Shell::Shell(User& u) : user(u) {
    running = true;
}

void Shell::start() {
    string command;
    cout << "Welcome to MiniOS Shell! Type 'help' to see available commands.\n";

    while (running) {
        cout << user.getCurrentUser() << "@MiniOS> ";
        getline(cin, command);

        command = Utils::trim(command);
        if (command.empty()) continue;

        handleCommand(command);
    }
}

void Shell::handleCommand(const string& input) {
    vector<string> tokens = Utils::split(input, ' ');
    string cmd = tokens[0];

    if (cmd == "help") {
        cout << "Available Commands:" << endl;
        cout << "  create <filename> <content>   - Create a file" << endl;
        cout << "  read <filename>               - Read a file" << endl;
        cout << "  write <filename> <content>    - Overwrite a file" << endl;
        cout << "  delete <filename>             - Delete a file" << endl;
        cout << "  ls                            - List files" << endl;
        cout << "  start <processname>           - Start a process" << endl;
        cout << "  kill <pid>                    - Kill a process" << endl;
        cout << "  ps                             - List processes" << endl;
        cout << "  alloc <appname> <size>         - Allocate memory" << endl;
        cout << "  free <appname>                 - Free memory" << endl;
        cout << "  mem                            - Show memory usage" << endl;
        cout << "  shutdown                       - Shutdown MiniOS" << endl;
        cout << "  clear                          - Clear the screen" << endl;
    } else if (cmd == "create" && tokens.size() >= 3) {
        string filename = tokens[1];
        string content = input.substr(input.find(filename) + filename.length() + 1);
        fs.createFile(filename, content);
    } else if (cmd == "read" && tokens.size() >= 2) {
        fs.readFile(tokens[1]);
    } else if (cmd == "write" && tokens.size() >= 3) {
        string filename = tokens[1];
        string content = input.substr(input.find(filename) + filename.length() + 1);
        fs.writeFile(filename, content);
    } else if (cmd == "delete" && tokens.size() >= 2) {
        fs.deleteFile(tokens[1]);
    } else if (cmd == "ls") {
        fs.listFiles();
    } else if (cmd == "start" && tokens.size() >= 2) {
        pm.createProcess(tokens[1]);
    } else if (cmd == "kill" && tokens.size() >= 2) {
        int pid = stoi(tokens[1]);
        pm.killProcess(pid);
    } else if (cmd == "ps") {
        pm.listProcesses();
    } else if (cmd == "alloc" && tokens.size() >= 3) {
        string app = tokens[1];
        int size = stoi(tokens[2]);
        mm.allocate(app, size);
    } else if (cmd == "free" && tokens.size() >= 2) {
        mm.free(tokens[1]);
    } else if (cmd == "mem") {
        mm.memoryStatus();
    } else if (cmd == "shutdown") {
        cout << "Shutting down MiniOS..." << endl;
        running = false;
    } else if (cmd == "clear") {
#if defined(_WIN32) || defined(_WIN64)
        system("cls");
#else
        system("clear");
#endif
    } else {
        cout << "Unknown command! Type 'help' for list of commands." << endl;
    }
}
