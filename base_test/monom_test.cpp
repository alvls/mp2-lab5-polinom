#include "monom.h"
#include "monom.cpp"
#include <gtest.h>

TEST(Monom, can_create_monom) {
	ASSERT_NO_THROW(Monom("x5y6z7"));
}

TEST(Monom, monom_create_correctly_1) {
	Monom m(2.5, 105);
	ASSERT_EQ(m.coef, 2.5);
	ASSERT_EQ(m.pows, 105);
}

TEST(Monom, monom_create_correctly_2) {
	Monom m("-y5");
	ASSERT_EQ(m.coef, -1.0);
	ASSERT_EQ(m.pows, 50);
}

TEST(Monom, can_get_val) {
	Monom polynom("-2.8x3y6z9");
	ASSERT_EQ(polynom.get_val(1.1, 2.2, 3.3), -19610904.764678996);
}