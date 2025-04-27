// Utils.h
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace Utils {
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    string trim(const string& str) {
        size_t first = str.find_first_not_of(' ');
        if (string::npos == first) return str;
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }
}

#endif // UTILS_H
