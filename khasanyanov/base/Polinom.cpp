#include "polinom.h"

Polinom::Polinom(){

}

Polinom::Polinom(const Polinom& p) : monoms(p.monoms), operands(p.operands) {}

double Polinom::calculate(double x, double y, double z){
	if (monoms.empty()) throw logic_error("empty polinom");
	double res = 0.0;
	for (const auto& m : monoms)
		res += m.calculate(x,y,z);
	return res;
}

void Polinom::add(const Monom& m){
	size_t size = monoms.get_size();
	for (size_t i = 0; i < size; i++) {
		if (monoms[i].equal(m)) {
			monoms[i] += m;
			return;
		}
	}
	monoms.insert_in_order(m, [](Monom x, Monom y) {return x > y; });
}

const LinkedList<Monom>& Polinom::get_monoms() const { return monoms; }

const map<char, double>& Polinom::get_operands() const { return operands; }

Polinom Polinom::operator*(const double& k) {
	Polinom res(*this);
	for (auto& m : res.monoms)
		m *= k;
	return res;
}

Polinom& Polinom::operator*=(const double& k) {
	for (auto& m : monoms)
		m *= k;
	return *this;
}

Polinom Polinom::operator*(const Polinom& p) {
	Polinom res;
	for (auto& m1 : monoms)
		for(auto& m2 : p.monoms)
			res.add(m1 * m2);
	return res;
}

Polinom Polinom::operator+(const Polinom& p){
	Polinom res(*this);
	for (const auto& m : p.monoms)
		res.add(m);
	return res;
}

Polinom& Polinom::operator+=(const Polinom& p) {
	for (const auto& m : p.monoms)
		this->add(m);
	return *this;
}








ostream& operator<<(ostream& os, const Polinom& p) {
	//for(size_t i = 0; i < p.list)
	return os;
}