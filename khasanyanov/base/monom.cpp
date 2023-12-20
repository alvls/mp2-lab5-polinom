#include "monom.h"


Monom::Monom() : k(0), degX(0), degY(0), degZ(0) {}

Monom::Monom(double K, int X, int Y, int Z) : k(K), degX(X), degY(Y), degZ(Z) {}

Monom::Monom(const Monom& m) : k(m.k), degX(m.degX), degY(m.degY), degZ(m.degZ) {}

bool Monom::equal(const Monom& m) const {
	return (degX == m.degX && degY == m.degY && degZ == m.degZ);
}

bool Monom::operator<(const Monom& m)const {
	if (equal(m)) return k < m.k;
	return ((degX * 100 + degY * 10 + degZ) < (m.degX * 100 + m.degY * 10 + m.degZ));
}

bool Monom::operator<=(const Monom& m)const {
	if (equal(m)) return k < m.k;
	return ((degX * 100 + degY * 10 + degZ) <= (m.degX * 100 + m.degY * 10 + m.degZ));
}

bool Monom::operator>(const Monom& m)const {
	return !(*this <= m);
}

bool Monom::operator>=(const Monom& m)const {
	return !(*this < m);
}

bool Monom::operator==(const Monom& m)const {
	return (k == m.k && degX == m.degX && degY == m.degY && degZ == m.degZ);
}

bool Monom::operator!=(const Monom& m)const {
	return !(*this == m);
}

Monom Monom::operator+(const Monom& m)const {
	if (!equal(m)) throw logic_error("monoms arent equal");
	return (Monom {k+m.k,degX, degY, degZ});
}

Monom& Monom::operator+=(const Monom& m) {
	if (!equal(m)) throw logic_error("monoms arent equal");
	k += m.k;
	return (*this);
}

Monom Monom::operator-(const Monom& m) const {
	if (!equal(m)) throw logic_error("monoms arent equal");
	return (Monom{ k - m.k,degX, degY, degZ });
}

Monom& Monom::operator-=(const Monom& m) {
	if (!equal(m)) throw logic_error("monoms arent equal");
	k -= m.k;
	return (*this);
}

Monom Monom::operator*(const Monom& m) const {
	return (Monom{ k * m.k,degX + m.degX, degY + m.degY, degZ + m.degZ });
}

Monom& Monom::operator*=(const Monom& m) {
	k *= m.k;
	degX += m.degX;
	degY += m.degY;
	degZ += m.degZ;
	return (*this);
}

Monom Monom::operator/(const Monom& m) const {
	return (Monom{ k / m.k,degX - m.degX, degY - m.degY, degZ - m.degZ });
}

Monom& Monom::operator/=(const Monom& m) {
	k /= m.k;
	degX -= m.degX;
	degY -= m.degY;
	degZ -= m.degZ;
	return (*this);
}

Monom Monom::operator*(const double& k)const {
	return Monom{this->k*k, degX, degY, degZ};
}

Monom& Monom::operator*=(const double& k) {
	this->k *= k;
	return *this;
}

Monom Monom::operator/(const double& k)const {
	return Monom{ this->k / k, degX, degY, degZ };
}

Monom& Monom::operator/=(const double& k) {
	this->k /= k;
	return *this;
}

ostream& operator<<(ostream& os, const Monom& m) {
	if (m.k == 0) return os;
	else if (m.k == 1) os << '{';
	else if (m.k == -1) os << "{-";
	else os << '{' << m.k;
	m.degX == 0 ? os << "" : os << "x" << m.degX;
	m.degY == 0 ? os << "" : os << "y" << m.degY;
	m.degZ == 0 ? os << "" : os << "z" << m.degZ;
	os << '}';
	return os;
}

double Monom::calculate(double x, double y, double z) const {
	return k == 0.0 ? 0.0 : static_cast<double>(k) * powf(x, degX) * powf(y, degY) * powf(z, degZ);
}

double Monom::get_coef() const { return k; }

int Monom::get_x() const { return degX; }

int Monom::get_y() const { return degY; }

int Monom::get_z() const { return degZ; }
