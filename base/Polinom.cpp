#include "Polinom.h"

#include <regex>
#include <string>
#include <iostream>
#include <stdexcept>


// конструктор из строки (на регул€рном выражении).
Polinom::Polinom(const string& polinomStr) {
	regex monomRegex(R"(\s*([-+]?\d*\.?\d*)\s*(x(\^\d+)?)?\s*(y(\^\d+)?)?\s*(z(\^\d+)?)\s*)");
	auto monomsBegin = sregex_iterator(polinomStr.begin(), polinomStr.end(), monomRegex);
	auto monomsEnd = sregex_iterator();

	for (sregex_iterator i = monomsBegin; i != monomsEnd; ++i) {
		smatch match = *i;
		if (match[1].str().empty() && !match[2].matched && !match[4].matched && !match[6].matched) continue;

		double coefficient = match[1].str().empty() ? 1.0 : stod(match[1].str());
		int xDegree = match[3].str().empty() ? (match[2].matched ? 1 : 0) : stoi(match[3].str().substr(1));
		int yDegree = match[5].str().empty() ? (match[4].matched ? 1 : 0) : stoi(match[5].str().substr(1));
		int zDegree = match[7].str().empty() ? (match[6].matched ? 1 : 0) : stoi(match[7].str().substr(1));

		unsigned int combinedDegree = xDegree * 100 + yDegree * 10 + zDegree;
		addMonom(Monom(coefficient, combinedDegree));
	}
	simplify();
}

Polinom& Polinom::operator=(const Polinom& other) {
	if (this == &other) {
		return *this;
	}
	this->monoms.Clear();
	for (size_t i = 0; i < other.monoms.Size(); ++i) {
		this->addMonom(other.monoms.At(i));
	}
	return *this;
}


Polinom::Polinom(const Polinom& other) {
	for (size_t i = 0; i < other.monoms.Size(); ++i) {
		this->addMonom(other.monoms.At(i));
	}
}

void Polinom::addMonom(const Monom& monom) {
	if (monom.coefficient == 0) return;
	monoms.PushBack(monom);
}

// ”прощение (приведение подобных + сортировка по степени)
void Polinom::simplify() {
	vector<Monom> monomVector;
	while (!monoms.IsEmpty()) {
		monomVector.push_back(monoms.Front());
		monoms.PopFront();
	}
	sort(monomVector.begin(), monomVector.end(), [](const Monom& a, const Monom& b) { return a.degree > b.degree; });
	for (size_t i = 0; i < monomVector.size(); i++) {
		if (i < monomVector.size() - 1 && monomVector[i].degree == monomVector[i + 1].degree) {
			monomVector[i + 1].coefficient += monomVector[i].coefficient;
			monomVector[i].coefficient = 0;
		}
	}
	monomVector.erase(remove_if(monomVector.begin(), monomVector.end(), [](const Monom& m) { return m.coefficient == 0; }), monomVector.end());
	for (const auto& m : monomVector) {
		monoms.PushBack(m);
	}
}

Polinom Polinom::operator+(const Polinom& other) const {
	Polinom result = *this;
	for (size_t i = 0; i < other.monoms.Size(); ++i) {
		result.addMonom(other.monoms.At(i));
	}
	result.simplify();
	return result;
}

Polinom Polinom::operator-(const Polinom& other) const {
	Polinom result = *this;
	for (size_t i = 0; i < other.monoms.Size(); ++i) {
		result.addMonom(Monom(-other.monoms.At(i).coefficient, other.monoms.At(i).degree));
	}
	result.simplify();
	return result;
}

Polinom Polinom::operator*(const Polinom& other) const {
	Polinom result;
	for (size_t i = 0; i < this->monoms.Size(); ++i) {
		for (size_t j = 0; j < other.monoms.Size(); ++j) {
			double newCoef = this->monoms.At(i).coefficient * other.monoms.At(j).coefficient;
			unsigned int newDeg = this->monoms.At(i).degree + other.monoms.At(j).degree;
			result.addMonom(Monom(newCoef, newDeg));
		}
	}
	result.simplify();
	return result;
}

pair<Polinom, Polinom> Polinom::divide(const Polinom& divisor) const {
	if (divisor.monoms.IsEmpty()) {
		throw runtime_error("Division by zero");
	}

	Polinom quotient, remainder = *this;
	Monom divisorLeadMonom = divisor.monoms.At(divisor.monoms.Size() - 1); // —тарший моном делител€

	while (!remainder.monoms.IsEmpty() &&
		remainder.monoms.At(remainder.monoms.Size() - 1).degree >= divisorLeadMonom.degree) {
		Monom remainderLeadMonom = remainder.monoms.At(remainder.monoms.Size() - 1); // —тарший моном делимого
		Monom quotientMonom = Monom(remainderLeadMonom.coefficient / divisorLeadMonom.coefficient, remainderLeadMonom.degree - divisorLeadMonom.degree);
		quotient.addMonom(quotientMonom);
		Polinom temp;
		temp.addMonom(quotientMonom);
		remainder = remainder - (temp * divisor);
		remainder.simplify();
	}
	return make_pair(quotient, remainder);
}

Polinom Polinom::multiplyByConstant(int constant) const {
	Polinom result;
	for (size_t i = 0; i < monoms.Size(); ++i) {
		Monom current = monoms.At(i);
		double newCoefficient = current.coefficient * constant;
		result.addMonom(Monom(newCoefficient, current.degree));
	}
	return result;
}


double Polinom::evaluate(double x, double y, double z) const {
	double sum = 0.0;
	for (size_t i = 0; i < monoms.Size(); ++i) {
		sum += monoms.At(i).evaluate(x, y, z);
	}
	return sum;
}

// ¬ывод полинома
void Polinom::print() const {
	for (size_t i = 0; i < monoms.Size(); ++i) {
		monoms.At(i).print();
		if (i < monoms.Size() - 1) cout << " + ";
	}
	cout << endl;
}

bool Polinom::isEmpty() {
	return monoms.IsEmpty();
}