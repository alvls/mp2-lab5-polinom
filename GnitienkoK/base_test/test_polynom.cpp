#include "Polynom.cpp"
#include <gtest.h>

TEST(Polynom, can_create_polynom_from_string) {
	string str = "xy2+12,1yz3-4x2y3z5";
	Polynom p;
	ASSERT_NO_THROW(p.parseAndAddMonoms(str));
}

TEST(Polynom, can_calculate_polynom) {
	string str = "xy2+12,1yz3-4x2y3z5";
	Polynom p;
	ASSERT_NO_THROW(p.calcPolynom(0.1, 0.2, 3));
}

TEST(Polynom, can_add_polynom) {
	string str = "xy2+12,1yz3-4x2y3z5";
	string str2 = "1-12yz3+6x4yz6";
	Polynom p, p2;
	p.parseAndAddMonoms(str);
	p2.parseAndAddMonoms(str2); 
	ASSERT_NO_THROW(p.addPolynom(p2));
}

TEST(Polynom, can_multiply_two_polynoms) {
	string str = "xy2+12,1yz3-4x2y3z5";
	string str2 = "1-12yz3+6x4yz6";
	Polynom p, p2;
	p.parseAndAddMonoms(str);
	p2.parseAndAddMonoms(str2);
	ASSERT_NO_THROW(p.multiplyPolynom(p2));
}

TEST(Polynom, can_multiply_polynom_by_a_number) {
	string str = "xy2+12,1yz3-4x2y3z5";
	Polynom p, p2;
	p2.parseAndAddMonoms("5");
	p.parseAndAddMonoms(str);
	ASSERT_NO_THROW(p.multiplyPolynom(p2));
}

TEST(Polynom, can_cast_monoms) {
	string str = "xy2-xy2+3x2y3z4-3x2y3z4";
	Polynom p;
	p.parseAndAddMonoms(str);
	Node<Monom>* node = p.getPolyFrontNode();
	EXPECT_EQ(0, node->data.coef);
}