#ifndef __MONOM_H__
#define __MONOM_H__

#include <string>
using namespace std;

static const size_t MAX_DEGREE = 9; // ћаксимально допустима€ степень переменной

class Monom {
public:
    double coefficient;
    size_t degree;

    Monom(double coef = 0.0, size_t deg = 0);
    Monom(const string& monomString);

    bool operator<(const Monom& other) const;
    bool operator>(const Monom& other) const;
    bool operator==(const Monom& other) const;
    bool operator!=(const Monom& other) const;
    Monom operator*(const Monom& other) const;

    double calculate(double x, double y, double z) const;
    string toString() const;
};
#endif // __MONOM_H__