#include "MyList.cpp"
#include <string>
#include <vector>
using namespace std;
class Polinom {
	MyList expression;
	Monom CreateMonom(string exp) {
		Monom tmp;
		string coeff;
		size_t deg = 0;
		int i = 0;

		while (exp[i] != 'x') {
			coeff += exp[i];
			i += 1;
		}
		tmp.coef = stoi(coeff);
		i += 1;
		deg += (exp[i] - '0') * 100;
		i += 2;
		deg += (exp[i] - '0') * 10;
		i += 2;
		deg += (exp[i] - '0');
		tmp.deg = deg;
		return tmp;
	}
public:
	Polinom(string exp) {
		string monom = "";
		monom += exp[0];
		for (int i = 1; i < exp.size(); i++) {
			if ((exp[i] != '+') && (exp[i] != '-')) {
				monom += exp[i];
			}
			else {
				expression.Push(CreateMonom(monom));
				if (exp[i] == '-')
					monom = "-";
				else
					monom = "";
			}
		}
		expression.Push(CreateMonom(monom));
	}
	string prPolinom() {
		string prPolinom = "";
		Node* iter = expression.GetpFirst();
		for (iter; iter != nullptr; iter = iter->pNext) {
			prPolinom += to_string(iter->date.coef) + "x" + to_string(iter->date.deg / 100) + "y" + to_string(iter->date.deg % 100 / 10) + "z" + to_string(iter->date.deg % 10);
			if ((iter->pNext != nullptr) && (iter->pNext->date.coef > 0))
				prPolinom += "+";
		}
		return prPolinom;
	}
	int Calculate(int x, int y, int z) {
		int ans = 0;
		Node* iter = expression.GetpFirst();
		for (iter; iter != nullptr; iter = iter->pNext) {
			int deg_x = iter->date.deg / 100;
			int deg_y = iter->date.deg % 100 / 10;
			int deg_z = iter->date.deg % 10;
			ans += iter->date.coef * pow(x, deg_x) * pow(y, deg_y) * pow(z, deg_z);
		}
		return ans;
	}
	void BringSimular() {
		vector<Monom> Mvector;
		Node* iter1 = expression.GetpFirst();
		Node* iter2;
		for (iter1; iter1 != nullptr; iter1 = iter1->pNext) {
			Mvector.push_back(iter1->date);
		}
		for (int i = 0; i < Mvector.size(); i++) {
			for (int j = i + 1; j < Mvector.size(); j++) {
				if (Mvector[i].deg > Mvector[j].deg) {
					Monom tmp = Mvector[i];
					Mvector[i] = Mvector[j];
					Mvector[j] = tmp;
				}
			}
		}
		vector <Monom> newMVector;
		newMVector.push_back(Mvector[0]);
		for (int i = 1; i < Mvector.size(); i++) {
			int last = newMVector.size() - 1;
			if (newMVector[last].deg == Mvector[i].deg) {
				newMVector[last].coef += Mvector[i].coef;
			}
			else {
				newMVector.push_back(Mvector[i]);
			}
		}
		MyList newexpression;
		for (int i = 0; i < newMVector.size(); i++) {
			newexpression.Push(newMVector[i]);
		}
		expression = newexpression;
	}
	void aditional(Polinom pl) {
		Node* ind = pl.expression.GetpFirst();
		for (ind; ind != nullptr; ind = ind->pNext) {
			expression.Push(ind->date);
		}
		BringSimular();
	}
	void Multiplication(Polinom pl) {
		MyList newexpresion;
		Node* ind1 = expression.GetpFirst();
		Node* ind2;
		for (ind1; ind1 != nullptr; ind1 = ind1->pNext) {
			Monom tmp = ind1->date;
			for (ind2 = pl.expression.GetpFirst(); ind2 != nullptr; ind2 = ind2->pNext) {
				Monom tmp2 = tmp;
				tmp2.coef *= ind2->date.coef;
				tmp2.deg += ind2->date.deg;
				newexpresion.Push(tmp2);
			}
		}
		expression = newexpresion;
		BringSimular();
	}
};
