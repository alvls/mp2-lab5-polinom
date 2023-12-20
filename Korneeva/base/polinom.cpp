#include "polinom.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

Polinom::Polinom(const string& polynom) 
{
	size_t pos = 0;
	size_t len = polynom.length();

	while (pos < len) 
	{
		size_t startPos = pos;

		if (polynom[pos] == '-') 
		{
			pos++;
		}

		while (pos < len && polynom[pos] != '+' && polynom[pos] != '-') 
		{
			pos++;
		}

		string monomStr = polynom.substr(startPos, pos - startPos);
		Monom monom(monomStr);

		if (startPos > 0 && polynom[startPos - 1] == '-') 
		{
			monom.coefficient = -monom.coefficient;
		}

		addMonom(monom);

		if (pos < len) 
		{
			pos++;
		}
	}

	removeZeroCoefficients();
}

Polinom::Polinom(const Polinom& other) 
{
	monomList = other.monomList;
}

void Polinom::removeZeroCoefficients()
{
	size_t index = 0;
	while (index < monomList.size())
	{
		if (monomList[index].coefficient == 0.0)
		{
			monomList.remove(index);
		}
		else
		{
			index++;
		}
	}
}

void Polinom::addMonom(const Monom& monom) 
{
	if (monom.coefficient == 0.0)
	{
		return;
	}
	for (auto& existingMonom : monomList) 
	{
		if (existingMonom.degree == monom.degree) 
		{
			existingMonom.coefficient += monom.coefficient;
			return;
		}
	}
	monomList.push_back(monom);
}

double Polinom::calculate(double x, double y, double z) const 
{
	double result = 0.0;
	for (size_t i = 0; i < monomList.size(); i++)
	{
		result += monomList[i].calculate(x, y, z);
	}
	return result;
}

Polinom& Polinom::operator=(const Polinom& other) 
{
	if (this != &other) 
	{
		monomList = other.monomList;
	}
	return *this;
}

string Polinom::toString() const
{
	if (monomList.empty())
	{
		return "0";
	}

	string result;
	for (size_t i = 0; i < monomList.size(); i++)
	{
		result += monomList[i].toString();
		if (i < monomList.size() - 1)
		{
			if (monomList[i + 1].coefficient >= 0)
			{
				result += " + ";
			}
			else
			{
				result += " ";
			}
		}
	}

	return result;
}

Polinom Polinom::operator+(const Polinom& other) const 
{
	Polinom result(*this);
	result += other;
	return result;
}

Polinom& Polinom::operator+=(const Polinom& other) 
{
	for (const Monom& monom : other.monomList)
	{
		addMonom(monom);
	}
	removeZeroCoefficients();
	return *this;
}

Polinom& Polinom::operator*=(double constant) 
{
	if (constant == 0.0)
	{
		monomList = TLinkedList<Monom>();
	}
	for (Monom& monom : monomList) 
	{
		monom.coefficient *= constant; 
	}
	return *this;
}

Polinom Polinom::operator*(double constant) const 
{
	Polinom result(*this);
	result *= constant;

	return result;
}

Polinom Polinom::operator-(const Polinom& other) const 
{
	Polinom result(*this);
	result -= other;

	return result;
}

Polinom& Polinom::operator-=(const Polinom& other) 
{
	Polinom invertedOther = other;
	invertedOther *= -1;
	(*this) += invertedOther;

	return *this;
}

Polinom Polinom::operator*(const Polinom& other) const {
	Polinom result;

	for (const Monom& monom1 : monomList) 
	{
		for (const Monom& monom2 : other.monomList) 
		{
			Monom multipliedMonom = monom1 * monom2; 
			result.addMonom(multipliedMonom);  
		}
	}

	result.removeZeroCoefficients();
	return result;
}

Polinom& Polinom::operator*=(const Polinom& other) 
{
	Polinom result = (*this) * other;
	(*this) = result;

	return *this;
}

bool Polinom::operator==(const Polinom& other) const
{
	return monomList == other.monomList;
}

bool Polinom::operator!=(const Polinom& other) const
{
	return !(*this == other);
}