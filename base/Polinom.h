#ifndef __POLINOM_H__
#define __POLINOM_H__

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cmath> 
#include <regex>
#include "Monom.h"
#include "TList.h"


class Polinom {
private:
   TList<Monom> monoms;

public:
   Polinom() {}
   Polinom(const string& polinomStr);
   Polinom(const Polinom& other);
   Polinom& operator=(const Polinom& other);

   void AddMonom(const Monom& monom);
   bool isEmpty();
   void CombineLikeTerms();

   Polinom operator-(const Polinom& other) const;
   Polinom operator+(const Polinom& other) const;
   Polinom operator*(const Polinom& other) const;
   Polinom MultiplyByConst(int constant) const;
   pair<Polinom, Polinom> Divide(const Polinom& divisor) const;
   double Ñalculation(double x, double y, double z) const;

   void Display() const;
};


#endif