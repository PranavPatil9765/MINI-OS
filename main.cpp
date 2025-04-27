// main.cpp
#include <iostream>
#include "User.h"
#include "Shell.h"

using namespace std;

int main() {
    User user;
    cout << "Welcome to MiniOS!" << endl;

    bool loggedIn = false;
    while (!loggedIn) {
        loggedIn = user.login();
    }

    Shell shell(user);
    shell.start();

    cout << "MiniOS shutdown successfully." << endl;
    return 0;
}
