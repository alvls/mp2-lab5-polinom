#include <Windows.h>
#include <cstdlib>
#include <iostream>
#include <conio.h>

#define KEY_EXIT 27
#define KEY_ENTER 13
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

int menu(char* menu[], int j) {
    CONSOLE_CURSOR_INFO structCursorInfo;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
    SetConsoleTextAttribute(hStdOut, COLOR_BACKGROUND);
    int key = 0;
    int code = 0;
    COORD cursor;
    do {
        system("cls");
        if (code == KEY_ARROW_UP) key--;
        if (code == KEY_ARROW_DOWN) key++;
        if (key < 0) key = j - 1;
        if (key > j - 1) key = 0;
        SetConsoleTextAttribute(hStdOut, 10);
        for (int i = 0; i < j; i++) {
            std::cout << menu[i] << endl;
        }
        SetConsoleTextAttribute(hStdOut, 15);
        cursor.Y = key;
        cursor.X = 0;
        SetConsoleCursorPosition(hStdOut, cursor);
        std::cout << menu[key];
        if ((code = getch()) == KEY_EXIT) {
            key = KEY_EXIT;
            break;
        }
    } while ((code = getch()) != KEY_ENTER);
    return key;
}