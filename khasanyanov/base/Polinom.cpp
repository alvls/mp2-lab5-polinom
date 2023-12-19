#include "polinom.h"

Polinom::Polinom(){

}

void Polinom::add(const Monom& m){
	size_t size = monoms.get_size();
	for (size_t i = 0; i < size; i++) {
		if (monoms[i].equal(m)) {
			monoms[i] += m;
			return;
		}
		//}
		//else if (cur > m) {
		//	monoms.insert(i + 1, m);
		//	return;
		//}
	}
	monoms.insert_in_order(m);
	//monoms.push_back(m);
}

const LinkedList<Monom>& Polinom::get_monoms() const { return monoms; }

const map<char, double>& Polinom::get_operands() const { return operands; }

ostream& operator<<(ostream& os, const Polinom& p) {
	//for(size_t i = 0; i < p.list)
	return os;
}