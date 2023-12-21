#include <iostream>
#include <windows.h>
#include "sorted_list.h"
#include "monom.h"
#include "polynom.h"

int main() {
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 0);
    string expression, operation;
    setlocale(LC_ALL, "ru");
    setlocale(LC_NUMERIC, "en");
    system("title Калькулятор полиномов");
    auto& b_op = Polynom::binary_operations;
    auto& u_op = Polynom::unary_operations;
    auto& t_op = Polynom::binary_operations;
    bool flag = 0;
    while (!flag)
    {
        SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 0);
        cout << "Введите арифметическое выражение: ";
        getline(cin, expression);
        try {
            Polynom tmp(expression);
            flag = true;
        }
        catch (invalid_argument) {
            SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | 0);
            cout << "Неверное выражение" << endl;
            system("PAUSE");
            system("cls");
        }
    }
    Polynom p(expression);
    label:
    while (1) {
        SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 0);
        system("cls");
        cout << "Текущее арифметическое выражение: ";
        cout << p << endl;
        cout << "Введите операцию: ";
        getline(cin, operation);
        if (b_op.find(operation) != b_op.end()) {
            string exp;
            cout << "second expression: ";
            getline(cin, exp);
            flag = 0;
            try {
                Polynom tmp(exp);
                flag = true;
            }
            catch (invalid_argument) {
                SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | 0);
                cout << "Неверное выражение" << endl;
                system("PAUSE");
                goto label;
                
            }
            Polynom p1(exp);
            cout << endl << "result: ";
            p = b_op[operation](p, p1);
        }
        else if (u_op.find(operation) != u_op.end())
            p = u_op[operation](p);
        else if (operation == "exit")
            exit(0);
        else if (operation == "clr")
            p = Polynom{};
    }
}
