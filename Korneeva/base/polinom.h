#ifndef __POLINOM_H__
#define __POLINOM_H__

#include "linkedlist.h"
#include "monom.h"
#include <string>
using namespace std;

class Polinom
{
private:
	TLinkedList<Monom> monomList;

	void removeZeroCoefficients();
public:
	Polinom() {};                           // Конструктор по умолчанию
	Polinom(const string& polynom);         // Конструктор, который принимает строку и формирует полином из этой строки
	Polinom(const Polinom& other);          // Конструктор копирования

	void addMonom(const Monom& monom);                    // Метод для добавления монома к полиному
	double calculate(double x, double y, double z) const; // Метод для вычисления значения полинома в заданной точке
	string toString() const;                              // Метод для представления полинома в виде строки

	Polinom& operator=(const Polinom& other);             // Оператор присваивания
	Polinom operator+(const Polinom& other) const;        // Оператор сложения
	Polinom operator-(const Polinom& other) const;        // Оператор вычитания
	Polinom operator*(double constant) const;             // Оператор умножения на константу
	Polinom operator*(const Polinom& other) const;        // Оператор перемножения полиномов

	Polinom& operator+=(const Polinom& other);
	Polinom& operator-=(const Polinom& other);
	Polinom& operator*=(double constant);
	Polinom& operator*=(const Polinom& other);

	bool operator==(const Polinom& other) const;
	bool operator!=(const Polinom& other) const;
};

#endif // __POLYNOM_H__
