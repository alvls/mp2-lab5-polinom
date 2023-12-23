#include <iostream>
#include "Polinom.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "ru_RU");

    polinom pm1("2x^2z^3-z^4+2x^5");
    polinom pm2("2x^2 + 4x^2 + zx - 3zx");
    polinom pm3("2x^2 + z^3x - 3zx");
    polinom pm4("x^2 + 3zx");
    polinom pm5("2x^2 + y^2");
    polinom pm6("y^2 + 2x^2");

    cout << "Полином: " << pm1 << endl;

    cout << "\nЗначение в точке {1, 0, 2}: " << pm1.inPoint(1, 0, 2) << endl;

    cout << "\nПолином: " << pm2 << endl;

    pm2.bringingSimilar();

    cout << "\nПриведение подобных: " << pm2 << endl;

    cout << "\nСумма полиномов ('2x^2 + z^3x - 3zx' и 'x^2 + 3zx'): " << pm3.sum(pm4) << endl;

    cout << "\nУмножение полиномов ('2x^2 + y^2' и 'y^2 + 2x^2'): " << pm5.mult(pm6) << endl;

    return 0;
}
