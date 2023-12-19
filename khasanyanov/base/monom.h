#ifndef __MONOM_H__
#define __MONOM_H__


#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

class Monom {
	double k;
	size_t degX,
	degY,
	degZ;
public:
	Monom();
	Monom(double K, size_t X, size_t Y, size_t Z);
	size_t get_koef() const;
	size_t get_x() const;
	size_t get_y() const;
	size_t get_z() const;

	bool equal(const Monom& m);
	bool operator<(const Monom& m);
	bool operator<=(const Monom& m);
	bool operator>(const Monom& m);
	bool operator>=(const Monom& m);
	bool operator==(const Monom& m);
	bool operator!=(const Monom& m);
	Monom operator+(const Monom& m);
	Monom& operator+=(const Monom& m);
	Monom operator-(const Monom& m);
	Monom& operator-=(const Monom& m);
	Monom operator*(const Monom& m);
	Monom& operator*=(const Monom& m);
	Monom operator/(const Monom& m);
	Monom& operator/=(const Monom& m);

	friend ostream& operator<<(ostream& os, const Monom& m);
};


#endif
