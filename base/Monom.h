#ifndef __MONOM_H__
#define __MONOM_H__

#include <iostream>
#include <cmath>

using namespace std;

struct Monom {
    double coefficient; 
    unsigned int degree; 
    Monom(double coef = 0.0, unsigned int deg = 0) : coefficient(coef), degree(deg) {}
    bool operator<(const Monom& other) const;
    bool operator==(const Monom& other) const;
    double evaluate(double x, double y, double z) const;
    void print() const;
};


#endif //__MONOM_H__
