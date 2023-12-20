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
        cout << "Вводите полиномы только от трёх переменных (x,y,z)" << endl;
        cout << "Показатели степени не должны превышать число 9" << endl << endl;
        cout << "Введите первый полином: ";
        string inputStr;
        getline(cin, inputStr);
        Polinom polinom1(inputStr);

        cout << "Введите второй полином: ";
        getline(cin, inputStr);
        Polinom polinom2(inputStr);

        cout << "Введите константу: ";
        cin >> a;

        Polinom result1 = polinom1 + polinom2;
        Polinom result2 = polinom1 - polinom2;
        Polinom result3 = polinom1 * polinom2;
        Polinom result4 = polinom1 * a;

        cout << endl << "Результат сложения полиномов: " << result1.toString() << endl;
        cout << "Результат вычитания второго полином из первого: " << result2.toString() << endl;
        cout << "Результат перемножения полиномов: " << result3.toString() << endl;
        cout << "Результат перемножения первого полинома на константу: " << result4.toString() << endl;
    }
    catch (const exception& e)
    {
        cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}