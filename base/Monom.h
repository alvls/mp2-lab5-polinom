#ifndef __MONOM_H__
#define __MONOM_H__

#include <cmath>
#include <iostream>

using namespace std;

class Monom {
public:

   double coef;   // коэффициент монома
   int degree;     // степень монома

   Monom(double c, int d) : coef(c), degree(d) {}

   double СalculationMonomial(double x, double y, double z) const {
      int exponents[3] = { degree / 100, (degree / 10) % 10, degree % 10 };
      double result = coef;

      for (int i = 0; i < 3; ++i) {
         result *= std::pow((i == 0 ? x : (i == 1 ? y : z)), exponents[i]);
      }

      return result;
   }

   void PrintMonomial() const {
      int xDeg = degree / 100;
      int yDeg = (degree / 10) % 10;
      int zDeg = degree % 10;

      cout << coef;

      if (xDeg > 0) {
         cout << "x";
         if (xDeg > 1) {
            cout << "^" << xDeg;
         }
      }

      if (yDeg > 0) {
         if (xDeg > 0) {
            cout << "";
         }
         cout << "y";
         if (yDeg > 1) {
            cout << "^" << yDeg;
         }
      }

      if (zDeg > 0) {
         if (xDeg > 0 || yDeg > 0) {
            cout << "";
         }
         cout << "z";
         if (zDeg > 1) {
            cout << "^" << zDeg;
         }
      }
   }

   bool operator==(const Monom& other) const {
      return degree == other.degree && abs(coef - other.coef) < 1e-10;
   }

   Monom operator+(const Monom& other) const {
      return Monom(coef + other.coef, degree);
   }

   Monom operator-(const Monom& other) const {
      return Monom(coef - other.coef, degree);
   }

   Monom operator*(const Monom& other) const {
      return Monom(coef * other.coef, degree + other.degree);
   }

   bool operator<(const Monom& other) const {
      return degree < other.degree;
   }
};
#endif
