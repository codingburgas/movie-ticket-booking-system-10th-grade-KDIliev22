#include "Menu.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
//shtot namespace std ne e dobra praktika
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