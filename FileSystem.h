// FileSystem.h
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <unordered_map>

using namespace std;

class FileSystem {
private:
    unordered_map<string, string> files; // filename -> content
public:
    void createFile(const string& filename, const string& content);
    void readFile(const string& filename);
    void writeFile(const string& filename, const string& content);
    void deleteFile(const string& filename);
    void listFiles();
};

#endif // FILESYSTEM_H
