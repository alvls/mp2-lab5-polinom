#ifndef __POLINOM_H__
#define __POLINOM_H__

#include <vector>
#include <regex>
#include <map>
#include "linked_list.h"
#include "monom.h"


using namespace std;

class Polinom {

	LinkedList<Monom> monoms;
	map<char, double> operands;

public:
	Polinom();
	Polinom(string s);
	void add(const Monom& m);
	const LinkedList<Monom>& get_monoms() const;
	const map<char, double>& get_operands() const;
	friend ostream& operator<<(ostream& os, const Polinom& p);
};





#endif 


