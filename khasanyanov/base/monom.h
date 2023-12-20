#ifndef __MONOM_H__
#define __MONOM_H__


#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

class Monom {
	double k;
	int degX,
	degY,
	degZ;
public:
	Monom();
	Monom(double K, int X, int Y, int Z);
	Monom(const Monom& m);
	double get_coef() const;
	int get_x() const;
	int get_y() const;
	int get_z() const;

	double calculate(double x, double y, double z) const;
	bool equal(const Monom& m)const;

	bool operator<(const Monom& m) const;
	bool operator<=(const Monom& m) const;
	bool operator>(const Monom& m)const;
	bool operator>=(const Monom& m)const;
	bool operator==(const Monom& m)const;
	bool operator!=(const Monom& m)const;
	Monom operator+(const Monom& m)const;
	Monom& operator+=(const Monom& m);
	Monom operator-(const Monom& m)const;
	Monom& operator-=(const Monom& m);
	Monom operator*(const Monom& m)const;
	Monom& operator*=(const Monom& m);
	Monom operator/(const Monom& m)const;
	Monom& operator/=(const Monom& m);
	Monom operator*(const double& k)const;
	Monom& operator*=(const double& k);
	Monom operator/(const double& k)const;
	Monom& operator/=(const double& k);
	friend ostream& operator<<(ostream& os, const Monom& m);
};


#endif
