#include "pyl.h"
#include <iostream>
#include <sstream>
#include "monom.h"
#include <regex>
#include <string>
#include <stdexcept>

void Polinom::simplify() 
{
    vector<monom> monomVector;
    while (!monoms.isEmpty()) 
    {
        monomVector.push_back(monoms.Front());
        monoms.popFront();
    }
    sort(monomVector.begin(), monomVector.end(), [](const monom& a, const monom& b) { return a.sumdeg > b.sumdeg; });
    for (size_t i = 0; i < monomVector.size(); i++)
    {
        if (i < monomVector.size() - 1 && monomVector[i].sumdeg == monomVector[i + 1].sumdeg)
        {
            monomVector[i + 1].coef += monomVector[i].coef;
            monomVector[i].coef = 0;
        }
    }
    monomVector.erase(remove_if(monomVector.begin(), monomVector.end(), [](const monom& m) { return m.coef == 0; }), monomVector.end());
    for (const auto& m : monomVector) 
    {
        monoms.pushBack(m);
    }
}
void Polinom::addMonom(const monom& monom)
{
    if (monom.coef == 0) return;
    monoms.pushBack(monom);
}

Polinom::Polinom(const string& polinomStr) 
{
    std::istringstream iss(polinomStr);
    string token;
    while (getline(iss, token, '+')) 
    {
        if (token.empty()) continue; 

        double coefficient = 1.0;
        int xDegree = 0;
        int yDegree = 0;
        int zDegree = 0;
        size_t pos = 0;
        if (token[pos] == '-' || token[pos] == '+')
        {
            ++pos;
        }
        coefficient = stod(token.substr(pos));
        while (pos < token.length())
        {
            if (token[pos] == 'x')
            {
                xDegree = (pos + 1 < token.length() && token[pos + 1] == '^') ? stoi(token.substr(pos + 2)) : 1;
            }
            else if (token[pos] == 'y') 
            {
                yDegree = (pos + 1 < token.length() && token[pos + 1] == '^') ? stoi(token.substr(pos + 2)) : 1;
            }
            else if (token[pos] == 'z') 
            {
                zDegree = (pos + 1 < token.length() && token[pos + 1] == '^') ? stoi(token.substr(pos + 2)) : 1;
            }
            ++pos;
        }

        unsigned int combinedDegree = xDegree * 100 + yDegree * 10 + zDegree;
        addMonom(monom(coefficient, combinedDegree));
    }

    simplify();
}
bool Polinom::isEmpty() 
{
    return monoms.isEmpty();
}

Polinom& Polinom::operator=(const Polinom& other)
{
    if (this == &other)
    {
        return *this;
    }
    this->monoms.clear();
    for (size_t i = 0; i < other.monoms.getSize(); ++i)
    {
        this->addMonom(other.monoms.At(i));
    }
    return *this;
}

Polinom::Polinom(const Polinom& other) 
{
    for (size_t i = 0; i < other.monoms.getSize(); ++i)
    {
        this->addMonom(other.monoms.At(i));
    }
}


Polinom Polinom::operator+(const Polinom& other) const 
{
    Polinom result = *this;
    for (size_t i = 0; i < other.monoms.getSize(); ++i) 
    {
        result.addMonom(other.monoms.At(i));
    }
    result.simplify();
    return result;
}

Polinom Polinom::operator-(const Polinom& other) const 
{
    Polinom result = *this;
    for (size_t i = 0; i < other.monoms.getSize(); ++i) 
    {
        result.addMonom(monom(-other.monoms.At(i).coef, other.monoms.At(i).sumdeg));
    }
    result.simplify();
    return result;
}
Polinom Polinom::operator*(const Polinom& other) const
{
    Polinom result;
    for (size_t i = 0; i < this->monoms.getSize(); ++i) 
    {
        for (size_t j = 0; j < other.monoms.getSize(); ++j) 
        {
            double newCoef = this->monoms.At(i).coef * other.monoms.At(j).coef;
            unsigned int newDeg = this->monoms.At(i).sumdeg + other.monoms.At(j).sumdeg;
            result.addMonom(monom(newCoef, newDeg));
        }
    }
    result.simplify();
    return result;
}
double Polinom::evaluate(double x, double y, double z) const 
{
    double sum = 0.0;
    for (size_t i = 0; i < monoms.getSize(); ++i) 
    {
        sum += monoms.At(i).evaluate(x, y, z);
    }
    return sum;
}
void Polinom::print() const 
{
    for (size_t i = 0; i < monoms.getSize(); ++i) 
    {
        monoms.At(i).print();
        if (i < monoms.getSize() - 1) cout << " + ";
    }
    cout << endl;
}



