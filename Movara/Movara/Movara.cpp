#include "Menu.h"
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<std::string> loginMenu = { "Login", "Register", "Exit" };
    Menu menu(loginMenu);
    int choice = menu.navigate();
    switch (choice) {
    case 0: std::cout << "User Login selected\n"; break;
    case 1: std::cout << "User Registration selected\n"; break;
    case 2: return 0;
    }
    return 0;
}
