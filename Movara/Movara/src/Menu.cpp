#include "Menu.h"        
#include <iostream>      
#include <conio.h>       
#include <windows.h>     
#include <string>        

Menu::Menu(const std::vector<std::string>& items)
    : items(items), selectedIndex(0) {
}

void Menu::getConsoleSize(int& cols, int& rows) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void Menu::clearScreen() {
    system("cls");
}

void Menu::display() {
    clearScreen();
    int cols, rows;
    getConsoleSize(cols, rows);

    int boxWidth = cols / 2;
    int boxHeight = static_cast<int>(items.size()) + 4;
    int startX = (cols - boxWidth) / 2;
    int startY = (rows - boxHeight) / 2;

    drawBox(boxWidth, boxHeight, startX, startY);

    for (size_t i = 0; i < items.size(); ++i) {
        int y = startY + 2 + static_cast<int>(i);
        COORD pos = { static_cast<SHORT>(startX + 2), static_cast<SHORT>(y) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        if (static_cast<int>(i) == selectedIndex)
            std::cout << "> " << items[i];
        else
            std::cout << "  " << items[i];
    }
}

// Box drawer thingy

void Menu::drawBox(int width, int height, int x, int y) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(h, pos);
    std::cout << char(201) << std::string(width - 2, char(205)) << char(187);
    for (int i = 1; i < height - 1; ++i) {
        pos.Y = static_cast<SHORT>(y + i);
        SetConsoleCursorPosition(h, pos);
        std::cout << char(186) << std::string(width - 2, ' ') << char(186);
    }
    pos.Y = static_cast<SHORT>(y + height - 1);
    SetConsoleCursorPosition(h, pos);
    std::cout << char(200) << std::string(width - 2, char(205)) << char(188);
}

// Arrow key UI navigation

int Menu::navigate() {
    display();
    while (true) {
        int key = _getch();
        switch (key) {
        case 72:
            selectedIndex = (selectedIndex - 1 + items.size()) % items.size();
            break;
        case 80:
            selectedIndex = (selectedIndex + 1) % items.size();
            break;
        case 13:
            return selectedIndex;
        }
        display();
    }
}

std::string Menu::promptHidden(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b' && !input.empty()) {
            input.pop_back();
            std::cout << "\b \b";
        }
        else if (isprint(ch)) {
            input += ch;
            std::cout << '*';
        }
    }
    std::cout << '\n';
    return input;
}