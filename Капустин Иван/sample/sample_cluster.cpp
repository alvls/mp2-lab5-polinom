#include <iostream>
#include "pyl.h"
#include <string>

int main() 
{
    setlocale(LC_ALL, "Russian"); 
    string input;
    cout << "������� ������ ������� : ";
    getline(cin, input);
    if (input == "0")
    {
        return 0;
    }
    Polinom poly1(input);
    cout << "������� 1: ";
    poly1.print();
    cout << "������� ������ �������: ";
    getline(cin, input);
    if (input == "0")
    {
        return 0;
    }
    Polinom poly2(input);
    cout << "������� 2: ";
    poly2.print();
    Polinom result;
    cout << "�������� �������� (+, -, *): ";
    char operation;
    cin >> operation;

    switch (operation)
    {
    case '+':
        result = poly1 + poly2;
        cout << "��������� ��������: ";
        result.print();
        break;
    case '-':
        result = poly1 - poly2;
        cout << "��������� ���������: ";
        result.print();
        break;
    case '*':
        result = poly1 * poly2;
        cout << "��������� ���������: ";
        result.print();
        break;
    default:
        cout << "�������� ��������" << endl;
        return 1;
    }
    return 0;
}