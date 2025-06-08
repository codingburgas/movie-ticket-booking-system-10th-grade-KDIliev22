#include "Menu.h"
#include "User.h"
#include "Database.h"
#include <iostream>

int main() {
    Database::instance().execute("CREATE TABLE IF NOT EXISTS users(id INTEGER PRIMARY KEY, username TEXT UNIQUE, password TEXT);");
    Menu mainMenu({ "Login","Register","Exit" });
    while (true) {
        int choice = mainMenu.navigate();
        if (choice == 2) break;
        std::string uname, pwd;
        std::cout << "Username: "; std::cin >> uname;
        pwd = mainMenu.promptHidden("Password: ");
        if (choice == 0) {
            if (User::loginUser(uname, pwd)) std::cout << "Login successful\n";
            else std::cout << "Login failed\n";
        }
        else if (choice == 1) {
            if (User::registerUser(uname, pwd)) std::cout << "Registration successful\n";
            else std::cout << "Registration failed (duplicate?)\n"; // tova NE raboti, ZASHTOTO NQMAQM DB VSE OSHTE SDFOISHFIOUAEHFIOASDIO
        }
        system("pause");
    }
    return 0;
}
