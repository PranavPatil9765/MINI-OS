# MiniOS - A Simple Operating System Simulator in C++

## Overview

MiniOS is a simple operating system simulator built in C++ that mimics basic OS functionalities such as user login, file management, process management, and memory allocation. It runs in a terminal environment, and allows users to execute basic commands such as file creation, deletion, reading, writing, process handling, and memory management.

The system is designed to demonstrate the core concepts of operating systems in a simplified, interactive way.

---

## Features

- **User Authentication**: Users must log in with a username and password to access the system.
- **File System**: Create, read, write, and delete files.
- **Process Management**: Start, kill, and list running processes.
- **Memory Management**: Allocate and free memory for applications.
- **Command-line Interface**: A shell that allows users to interact with the system through commands.

---

## Commands

Once logged in, you can use the following commands in the MiniOS shell:

### File System Commands
- `create <filename> <content>`: Creates a file with the specified content.
- `read <filename>`: Reads and displays the content of a file.
- `write <filename> <content>`: Overwrites the content of a file.
- `delete <filename>`: Deletes the specified file.
- `ls`: Lists all the files in the system.

### Process Management Commands
- `start <processname>`: Starts a new process with the specified name.
- `kill <pid>`: Kills the process with the given process ID (PID).
- `ps`: Lists all running processes.

### Memory Management Commands
- `alloc <appname> <size>`: Allocates a specified amount of memory for an application.
- `free <appname>`: Frees the memory allocated to a specified application.
- `mem`: Displays the current memory usage and allocation.

### Other Commands
- `help`: Displays a list of available commands.
- `shutdown`: Shuts down the system.
- `clear`: Clears the terminal screen.

---

## Installation

### Prerequisites
Make sure you have the following installed:
- A C++ compiler (e.g., `g++` or `clang`)
- A terminal to run the program

### Steps to Install
1. Clone or download the project files.
2. Navigate to the project directory in the terminal.
3. Compile the project with the following command:
   ```bash
   g++ -o miniOS main.cpp User.cpp Shell.cpp ProcessManager.cpp MemoryManager.cpp -std=c++11



   
   
# Run the program 
./miniOS


