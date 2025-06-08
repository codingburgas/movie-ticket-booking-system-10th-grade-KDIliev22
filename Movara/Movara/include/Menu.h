#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

class Menu {
public:
    Menu(const std::vector<std::string>& items);
    void display();
    int  navigate();
    std::string promptHidden(const std::string& prompt);
private:
    std::vector<std::string> items;
    int selectedIndex;
    void clearScreen();
    void drawBox(int width, int height, int x, int y);
    void getConsoleSize(int& cols, int& rows);
};

#endif // MENU_H
