#include "monom.h"


Monom::Monom() : k(0), degX(0), degY(0), degZ(0) {}

Monom::Monom(double K, size_t X, size_t Y, size_t Z) : k(K), degX(X), degY(Y), degZ(Z) {
	if (X < 0 || Y < 0 || Z < 0) throw invalid_argument("negative degree");
}

Monom::Monom(const Monom& m) : k(m.k), degX(m.degX), degY(m.degY), degZ(m.degZ) {}

bool Monom::equal(const Monom& m) {
	return (degX == m.degX && degY == m.degY && degZ == m.degZ);
}

bool Monom::operator<(const Monom& m){
	if (equal(m)) return k < m.k;
	return ((degX * 100 + degY * 10 + degZ) < (m.degX * 100 + m.degY * 10 + m.degZ));
}

bool Monom::operator<=(const Monom& m){
	if (equal(m)) return k < m.k;
	return ((degX * 100 + degY * 10 + degZ) <= (m.degX * 100 + m.degY * 10 + m.degZ));
}

bool Monom::operator>(const Monom& m){
	return !(*this <= m);
}

bool Monom::operator>=(const Monom& m){
	return !(*this < m);
}

bool Monom::operator==(const Monom& m){
	return (k == m.k && degX == m.degX && degY == m.degY && degZ == m.degZ);
}

bool Monom::operator!=(const Monom& m){
	return !(*this == m);
}

Monom Monom::operator+(const Monom& m){
	if (!equal(m)) throw logic_error("monoms arent equal");
	return (Monom {k+m.k,degX, degY, degZ});
}

Monom& Monom::operator+=(const Monom& m) {
	if (!equal(m)) throw logic_error("monoms arent equal");
	k += m.k;
	return (*this);
}

Monom Monom::operator-(const Monom& m) {
	if (!equal(m)) throw logic_error("monoms arent equal");
	return (Monom{ k - m.k,degX, degY, degZ });
}

Monom& Monom::operator-=(const Monom& m) {
	if (!equal(m)) throw logic_error("monoms arent equal");
	k -= m.k;
	return (*this);
}

Monom Monom::operator*(const Monom& m) {
	return (Monom{ k * m.k,degX + m.degX, degY + m.degY, degZ + m.degZ });
}

Monom& Monom::operator*=(const Monom& m) {
	k *= m.k;
	degX += m.degX;
	degY += m.degY;
	degZ += m.degZ;
	return (*this);
}

Monom Monom::operator/(const Monom& m) {
	return (Monom{ k / m.k,degX + m.degX, degY + m.degY, degZ + m.degZ });
}

Monom& Monom::operator/=(const Monom& m) {
	k /= m.k;
	degX += m.degX;
	degY += m.degY;
	degZ += m.degZ;
	return (*this);
}

Monom Monom::operator*(const double& k){
	return Monom{this->k*k, degX, degY, degZ};
}

Monom& Monom::operator*=(const double& k) {
	this->k *= k;
	return *this;
}

Monom Monom::operator/(const double& k) {
	return Monom{ this->k / k, degX, degY, degZ };
}

Monom& Monom::operator/=(const double& k) {
	this->k /= k;
	return *this;
}

ostream& operator<<(ostream& os, const Monom& m) {
	if (m.k == 0) return os;
	else if (m.k == 1) os << "";
	else if (m.k == -1) os << "-";
	else os << m.k;
	m.degX == 0 ? os << "" : os << "x" << m.degX;
	m.degY == 0 ? os << "" : os << "y" << m.degY;
	m.degZ == 0 ? os << "" : os << "z" << m.degZ;
	return os;
}

double Monom::calculate(double x, double y, double z) const {
	return k == 0.0 ? 0.0 : static_cast<double>(k) * powf(x, degX) * powf(y, degY) * powf(z, degZ);
}

size_t Monom::get_koef() const { return k; }

size_t Monom::get_x() const { return degX; }

size_t Monom::get_y() const { return degY; }

size_t Monom::get_z() const { return degZ; }
