// FileSystem.cpp
#include "FileSystem.h"
#include <iostream>

using namespace std;

void FileSystem::createFile(const string& filename, const string& content) {
    if (files.find(filename) != files.end()) {
        cout << "File already exists!" << endl;
        return;
    }
    files[filename] = content;
    cout << "File '" << filename << "' created." << endl;
}

void FileSystem::readFile(const string& filename) {
    auto it = files.find(filename);
    if (it != files.end()) {
        cout << "Content of '" << filename << "': " << endl;
        cout << it->second << endl;
    } else {
        cout << "File not found!" << endl;
    }
}

void FileSystem::writeFile(const string& filename, const string& content) {
    auto it = files.find(filename);
    if (it != files.end()) {
        files[filename] = content;
        cout << "File '" << filename << "' updated." << endl;
    } else {
        cout << "File not found!" << endl;
    }
}

void FileSystem::deleteFile(const string& filename) {
    if (files.erase(filename)) {
        cout << "File '" << filename << "' deleted." << endl;
    } else {
        cout << "File not found!" << endl;
    }
}

void FileSystem::listFiles() {
    cout << "Files in system:" << endl;
    for (auto& file : files) {
        cout << "- " << file.first << endl;
    }
}
