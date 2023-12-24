#include <iostream>
#include "pyl.h"
#include <string>

int main() 
{
    setlocale(LC_ALL, "Russian"); 
    string input;
    cout << "Введите первый полином : ";
    getline(cin, input);
    if (input == "0")
    {
        return 0;
    }
    Polinom poly1(input);
    cout << "Полином 1: ";
    poly1.print();
    cout << "Введите второй полином: ";
    getline(cin, input);
    if (input == "0")
    {
        return 0;
    }
    Polinom poly2(input);
    cout << "Полином 2: ";
    poly2.print();
    Polinom result;
    cout << "Выберите операцию (+, -, *): ";
    char operation;
    cin >> operation;

    switch (operation)
    {
    case '+':
        result = poly1 + poly2;
        cout << "Результат сложения: ";
        result.print();
        break;
    case '-':
        result = poly1 - poly2;
        cout << "Результат вычитания: ";
        result.print();
        break;
    case '*':
        result = poly1 * poly2;
        cout << "Результат умножения: ";
        result.print();
        break;
    default:
        cout << "Неверная операция" << endl;
        return 1;
    }
    return 0;
}