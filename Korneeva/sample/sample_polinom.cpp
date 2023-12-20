#include <iostream>
#include <ctime>
#include "polinom.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    try
    {
        double a;
        cout << "������� �������� ������ �� ��� ���������� (x,y,z)" << endl;
        cout << "���������� ������� �� ������ ��������� ����� 9" << endl << endl;
        cout << "������� ������ �������: ";
        string inputStr;
        getline(cin, inputStr);
        Polinom polinom1(inputStr);

        cout << "������� ������ �������: ";
        getline(cin, inputStr);
        Polinom polinom2(inputStr);

        cout << "������� ���������: ";
        cin >> a;

        Polinom result1 = polinom1 + polinom2;
        Polinom result2 = polinom1 - polinom2;
        Polinom result3 = polinom1 * polinom2;
        Polinom result4 = polinom1 * a;

        cout << endl << "��������� �������� ���������: " << result1.toString() << endl;
        cout << "��������� ��������� ������� ������� �� �������: " << result2.toString() << endl;
        cout << "��������� ������������ ���������: " << result3.toString() << endl;
        cout << "��������� ������������ ������� �������� �� ���������: " << result4.toString() << endl;
    }
    catch (const exception& e)
    {
        cerr << "������: " << e.what() << std::endl;
    }

    return 0;
}