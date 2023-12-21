#include "list.h"
#include "list.cpp"
#include <gtest.h>

TEST(Polynom, can_create_polinom) {
	Polynom polynom;
	ASSERT_NO_THROW(polynom.construct_polynom("-2xyz+2x2y3z4"));
}

TEST(Polynom, can_get_val) {
	Polynom polynom;
	polynom.construct_polynom("-2xyz+2x2y3z4");
	ASSERT_EQ(polynom.get_val(1, 1, 1), 0);
}

TEST(Polynom, can_add) {
	Polynom pol1, pol2;
	pol1.construct_polynom("2x2z3-1.13z5");
	pol2.construct_polynom("2.13z5+xyz");
	Polynom res = pol1.add(pol2);
	std::vector<double> true_coefs = { 2.0, 1.0, 1.0 };
	std::vector<int> true_pows = { 203, 111, 5 };
	std::vector<double> coefs;
	std::vector<int> pows;
	for (Monom* p = res.head; p != nullptr; p = p->next) {
		coefs.push_back(p->coef);
		pows.push_back(p->pows);
	}
	ASSERT_EQ(coefs[0], true_coefs[0]);
	ASSERT_EQ(coefs[1], true_coefs[1]);
	ASSERT_EQ(coefs[2], true_coefs[2]);
}

TEST(Polynom, can_sub) {
	Polynom pol1, pol2;
	pol1.construct_polynom("2x2z3-1.13z5");
	pol2.construct_polynom("2.13z5+xyz");
	Polynom res = pol1.sub(pol2);
	std::vector<double> true_coefs = { 2.0, -1.0, -3.26 };
	std::vector<int> true_pows = { 203, 111, 5 };
	std::vector<double> coefs;
	std::vector<int> pows;
	for (Monom* p = res.head; p != nullptr; p = p->next) {
		coefs.push_back(p->coef);
		pows.push_back(p->pows);
	}
	for (int i = 0; i < coefs.size(); i++)
		ASSERT_EQ(coefs[i], true_coefs[i]);
}

TEST(Polynom, can_mul) {
	Polynom pol1, pol2;
	pol1.construct_polynom("-x5z4+2.2y3z4-2.2x6");
	pol2.construct_polynom("2.13z5+xz");
	Polynom res = pol1.mul(pol2);
	std::vector<double> true_coefs = { -2.2, -5.686, -2.13, 2.2, 4.686 };
	std::vector<int> true_pows = { 701, 605, 509, 135, 39 };
	std::vector<double> coefs;
	std::vector<int> pows;
	for (Monom* p = res.head; p != nullptr; p = p->next) {
		coefs.push_back(p->coef);
		pows.push_back(p->pows);
	}
	for (int i = 0; i < coefs.size(); i++)
		ASSERT_EQ(coefs[i], true_coefs[i]);
}

TEST(Polynom, can_der) {
	Polynom pol1;
	pol1.construct_polynom("-x5z4+2.2y3z4-2x6");
	Polynom res = pol1.get_derivative('x');
	std::vector<double> true_coefs = { -12.0, -5.0 };
	std::vector<int> true_pows = { 500, 404 };
	std::vector<double> coefs;
	std::vector<int> pows;
	for (Monom* p = res.head; p != nullptr; p = p->next) {
		coefs.push_back(p->coef);
		pows.push_back(p->pows);
	}
	for (int i = 0; i < coefs.size(); i++)
		ASSERT_EQ(coefs[i], true_coefs[i]);
}

TEST(Polynom, can_antiDer) {
	Polynom pol1;
	pol1.construct_polynom("-x5z4+2.2y3z4-2x6");
	Polynom res = pol1.get_antiderivative('y');
	std::vector<double> true_coefs = { -2.0, -1.0, 0.55 };
	std::vector<int> true_pows = { 601, 514, 44 };
	std::vector<double> coefs;
	std::vector<int> pows;
	for (Monom* p = res.head; p != nullptr; p = p->next) {
		coefs.push_back(p->coef);
		pows.push_back(p->pows);
	}
	for (int i = 0; i < coefs.size(); i++)
		ASSERT_EQ(coefs[i], true_coefs[i]);
}