#include "monom.h"
#include <sstream>

double monom::evaluate(double x, double y, double z) const 
{
    int xDeg = sumdeg / 100;
    int yDeg = (sumdeg / 10) % 10;
    int zDeg = sumdeg % 10;
    return coef * pow(x, xDeg) * pow(y, yDeg) * pow(z, zDeg);
}

void monom::print() const
{
    int xDeg = sumdeg / 100;
    int yDeg = (sumdeg / 10) % 10;
    int zDeg = sumdeg % 10;
    cout << coef;
    if (xDeg > 0) cout << "x^" << xDeg;
    if (yDeg > 0) cout << "y^" << yDeg;
    if (zDeg > 0) cout << "z^" << zDeg;
}
bool monom::operator<(const monom& other) const
{
    return sumdeg < other.sumdeg;
}
bool monom::operator==(const monom& other) const
{
    return sumdeg == other.sumdeg && abs(coef - other.coef) < 1e-10;
}