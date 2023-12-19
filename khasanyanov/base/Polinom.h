#ifndef __POLINOM_H__
#define __POLINOM_H__

#include <vector>
#include <regex>
#include "linked_list.h"
#include "monom.h"


using namespace std;

class Polinom {

	LinkedList<Monom> monoms;
	

public:
	Polinom();
	Polinom(string s);
	void add(const Monom& m);
	LinkedList<Monom> get_monoms() const;
	friend ostream& operator<<(ostream& os, const Polinom& p);
};





#endif 


