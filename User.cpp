// User.cpp
#include "User.h"
#include <iostream>

using namespace std;

User::User() {
    users["admin"] = "admin"; // default admin
    users["guest"] = "guest"; // default guest
}

bool User::login() {
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        currentUser = username;
        cout << "Login successful! Welcome " << username << "!" << endl;
        return true;
    }
    cout << "Invalid credentials!" << endl;
    return false;
}

string User::getCurrentUser() {
    return currentUser;
}
