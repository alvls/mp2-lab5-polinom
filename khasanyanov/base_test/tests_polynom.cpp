#include "gtest.h"
#include "polynom.h"

TEST(Polynom, can_create_polynom) {
	ASSERT_NO_THROW(Polynom());
}

TEST(Polynom, can_create_polynom_from_string) {
	ASSERT_NO_THROW(Polynom{ "-2x3y + yz2 - 4xyz" });
}

TEST(Polynom, can_copy_polynom) {
	Polynom p("2xy+4y4z2");
	ASSERT_NO_THROW(Polynom{p});
	EXPECT_EQ(p, Polynom{ p });
}

TEST(Polynom, test_multiply_operators) {
	Polynom p("3x2y2z3 + xy");
	Monom p1("xy2z2");
	Polynom res("3x3y4z5+x2y3z2");
	ASSERT_NO_THROW(p * p1);
	p  = p * p1;
	EXPECT_EQ(res, p);
}

TEST(Polynom, test_minus_operators) {
	Polynom p("3x2y2z3 + xy");
	Polynom p1("xy2z2");
	Polynom res("3x2y2z3 + xy - xy2z2");
	ASSERT_NO_THROW(p - p1);
	p -= p1;
	EXPECT_EQ(res, p);
}

TEST(Polynom, test_plus_operators) {
	Polynom p("3x2y2z3 + xy");
	Polynom p1("xy2z2");
	Polynom res("3x2y2z3 + xy + xy2z2");
	ASSERT_NO_THROW(p + p1);
	p += p1;
	EXPECT_EQ(res, p);
}

TEST(Polynom, test_divide_operators) {
	Polynom p("3x2y2z3 + x4y4z5");
	Monom m("xy2z2");
	Polynom res("3xz + x3y2z3");
	ASSERT_NO_THROW(p / m);
	p /= m;
	EXPECT_EQ(res, p);
}