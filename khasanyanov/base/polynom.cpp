#include "polynom.h"

Polynom::Polynom() {}

Polynom::Polynom(const Polynom& p) : monoms(p.monoms), operands(p.operands) {}

map<string, function<Polynom(const Polynom&, const Polynom&)> > Polynom::binary_operations = { 
	
	{"+", [](const Polynom& a, const Polynom& b) {return a + b; }},
	{"-", [](const Polynom& a, const Polynom& b) {return a - b; }},
	{"*", [](const Polynom& a, const Polynom& b) {return a * b; }},
	{"/", [](const Polynom& a, const Polynom& b) {return a / b; }}
};

Polynom Polynom::differential(char variable){
	Polynom res(*this);
	switch (variable) {
	case 'x':

	}
}

double Polynom::calculate(double x, double y, double z){
	if (monoms.empty()) throw logic_error("empty Polynom");
	double res = 0.0;
	for (const auto& m : monoms)
		res += m.calculate(x,y,z);
	return res;
}

void Polynom::add(const Monom& m){
	size_t size = monoms.get_size();
	for (size_t i = 0; i < size; i++) {
		if (monoms[i].equal(m)) {
			monoms[i] += m;
			return;
		}
	}
	monoms.insert_in_order(m, [](Monom x, Monom y) {return x > y; });
}

const LinkedList<Monom>& Polynom::get_monoms() const { return monoms; }

const map<char, double>& Polynom::get_operands() const { return operands; }

Polynom Polynom::operator*(const double& k) const {
	Polynom res(*this);
	for (auto& m : res.monoms)
		m *= k;
	return res;
}

Polynom& Polynom::operator*=(const double& k) {
	for (auto& m : monoms)
		m *= k;
	return *this;
}

Polynom Polynom::operator+(const Polynom& p)const {
	Polynom res(*this);
	for (const auto& m : p.monoms)
		res.add(m);
	return res;
}

Polynom& Polynom::operator+=(const Polynom& p) {
	for (const auto& m : p.monoms)
		this->add(m);
	return *this;
}

Polynom Polynom::operator-(const Polynom& p) const {
	return Polynom{*this + (p * (-1.0))};
}

Polynom& Polynom::operator-=(const Polynom& p) {
	for (const auto& m : p.monoms)
		this->add(m * (-1.0));
	return *this;
}

Polynom Polynom::operator+(const Monom& m)const {
	Polynom res(*this);
	res.add(m);
	return res;
}

Polynom& Polynom::operator+=(const Monom& m) {
	add(m);
	return *this;
}

Polynom Polynom::operator-(const Monom& m)const {
	Polynom res(*this);
	for (auto& m1 : res.monoms)
		if (m1.equal(m))
			m1 -= m;
	return res;
}

Polynom& Polynom::operator-=(const Monom& m) {
	*this = *this - m;
	return *this;
}

Polynom Polynom::operator*(const Polynom& p) const {
	Polynom res;
	for (auto& m1 : monoms)
		for(auto& m2 : p.monoms)
			res.add(m1 * m2);
	return res;
}

Polynom& Polynom::operator*=(const Polynom& p) {
	Polynom res;
	for (auto& m1 : monoms)
		for (auto& m2 : p.monoms)
			res.add(m1 * m2);
	*this = res;
	return *this;
}

Polynom Polynom::operator*(const Monom& m) const {
	Polynom res;
	for (auto& m1: res.monoms)
		res.add(m1 * m);
	return res;
}

Polynom& Polynom::operator*=(const Monom& m) {
	*this = *this * m;
	return *this;
}

Polynom Polynom::operator/(const Polynom& p) const {
	if (p.monoms.get_size() == 0) throw logic_error("divide by zero");
	Polynom a(*this), b(p), res;
	Monom cur;
	while (monoms.get_front() >= p.monoms.get_front()) {
		cur = monoms.get_front() / p.monoms.get_front();
		res.add(cur);
		b *= cur;
		a -= cur;
	}
	return res;
}

Polynom& Polynom::operator/=(const Polynom& p) {
	*this = *this / p;
	return *this;
}

bool Polynom::operator==(const Polynom& p) const {
	for (auto& m1 : monoms)
		for (auto& m2 : monoms)
			if (m1 != m2) return false;
	return true;
}

bool Polynom::operator!=(const Polynom& p) const {	return !(*this == p); }

bool Polynom::operator>(const Polynom& p) const { return monoms.get_front() > p.get_monoms().get_front(); }

bool Polynom::operator>=(const Polynom& p) const { return monoms.get_front() >= p.get_monoms().get_front(); }

bool Polynom::operator<(const Polynom& p) const { return monoms.get_front() < p.get_monoms().get_front(); }

bool Polynom::operator<=(const Polynom& p) const { return monoms.get_front() <= p.get_monoms().get_front(); }

ostream& operator<<(ostream& os, const Polynom& p) {
	os << p.monoms.get_front();
	for (auto it = ++p.monoms.cbegin(); it != p.monoms.cend(); ++it) 
		os << "+" << *it;
	return os;
}