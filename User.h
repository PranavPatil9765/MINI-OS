// User.h
#ifndef USER_H
#define USER_H

#include <string>
#include <unordered_map>

using namespace std;

class User {
private:
    unordered_map<string, string> users; // username -> password
    string currentUser;
public:
    User();
    bool login();
    string getCurrentUser();
};

#endif // USER_H
