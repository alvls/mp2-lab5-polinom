#include <gtest.h>
#include "Monom.h"
#include "Monom.cpp"

TEST(MonomTest, CreateMonom) {
	Monom m(5, 212);
	ASSERT_EQ(m.coefficient, 5);
	ASSERT_EQ(m.degree, 212);
}

TEST(MonomTest, EvaluateMonom) {
	Monom m(2, 111);
	ASSERT_DOUBLE_EQ(m.evaluate(2, 3, 4), 2 * pow(2, 1) * pow(3, 1) * pow(4, 1));
}

TEST(MonomTest, LessThanOperator) {
	Monom m1(1, 212);
	Monom m2(1, 213);
	ASSERT_TRUE(m1 < m2);
}

TEST(MonomTest, EqualityOperator) {
	Monom m1(2, 212);
	Monom m2(2, 212);
	ASSERT_TRUE(m1 == m2);
}