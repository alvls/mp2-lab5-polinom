#include "gtest.h"
#include <Polynom.h>

TEST(TPolynom, can_create_polynom_using_default_constructor)
{
	ASSERT_NO_THROW(TPolynom polynom);
}

TEST(TPolynom, can_create_polynom_by_passing_arguments)
{
	TPolynom polynom("2x^3+4y^2-5z^7");
}

TEST(TPolynom, can_correctly_create_polynom_from_string)
{
	EXPECT_EQ("2x^3 + 4y^2 - 5z^7", TPolynom("2x^3+4y^2-5z^7").to_string());
}

TEST(TPolynom, cant_create_polynom_with_degree_that_exceeds_allowed_value)
{
	ASSERT_ANY_THROW(TPolynom("x^3+xy^12-4z^10"));
}

TEST(TPolynom, cant_create_polynom_with_too_large_degree)
{
	ASSERT_ANY_THROW(TPolynom("x^9999+xy^4-xyz^1001"));
}

TEST(TPolynom, cant_create_polynom_with_negative_degree)
{
	ASSERT_ANY_THROW(TPolynom("2x^3-y^-5+4z^7"));
}

TEST(TPolynom, can_copy_polynom)
{
	TPolynom p("2x^3+4y^2-5z^7");
	TPolynom copie(p);
	EXPECT_EQ(p, copie);
}

TEST(TPolynom, can_add_monom_to_polynom)
{
	TPolynom p("x^5+y^3-2z^7");
	p.add_monom(TMonom("5z^7"));
	EXPECT_EQ("x^5 + y^3 + 3z^7", p.to_string());
}

TEST(TPolynom, can_calculate_polynom_at_point)
{
	TPolynom p("2x^3+4y^2-5z^7");
	EXPECT_EQ(-574, p.calculate(1, 4, 2));
}

TEST(TPolynom, assignment_operator_works_correctly)
{
	TPolynom p("2x^3+4y^2-5z^7");
	TPolynom p2 = p;
	EXPECT_EQ(p, p2);
}

TEST(TPolynom, addition_operator_works_correctly)
{
	TPolynom p("3x^2-4y^3+5z^3");
	TPolynom p2("5x^2+3y^3-2z^3");
	EXPECT_EQ("8x^2 - y^3 + 3z^3", (p + p2).to_string());
}

TEST(TPolynom, addition_assignment_operator_works_correctly)
{
	TPolynom p("2x^3+4y^2-5z^7");
	p += TPolynom("x^3+2xy^3");
	EXPECT_EQ(TPolynom("3x^3 + 4y^2 - 5z^7 + 2xy^3"), p);
}

TEST(TPolynom, subtraction_operator_works_correctly)
{
	TPolynom p("8x^2-y^3+3z^3");
	TPolynom p2("5x^2+3y^3-2z^3");
	EXPECT_EQ("3x^2 - 4y^3 + 5z^3", (p - p2).to_string());
}

TEST(TPolynom, subtraction_assignment_operator_works_correctly)
{
	TPolynom p("3x^3+4y^2-5z^7+2xy^3");
	p -= TPolynom("x^3+2xy^3");
	EXPECT_EQ(TPolynom("2x^3 + 4y^2 - 5z^7"), p);
}

TEST(TPolynom, multiply_operator_works_correctly)
{
	TPolynom p("3x^2-4y^3+5z^3");
	TPolynom product = p * 2.5;
	TPolynom product2 = p * TPolynom("2x^4");
	EXPECT_EQ(TPolynom("7.5x^2 - 10y^3 + 12.5z^3"), product);
	EXPECT_EQ(TPolynom("6x^6 - 8x^4y^3 + 10x^4z^3"), product2);
}

TEST(TPolynom, multiply_operator_works_correctly_v2)
{
	TPolynom p("3x^2-4y^3+5z^3");

	p *= TPolynom("2x^4");
	EXPECT_EQ(TPolynom("6x^6 - 8x^4y^3 + 10x^4z^3"), p);

	p *= 2.5;
	EXPECT_EQ(TPolynom("15x^6 - 20x^4y^3 + 25x^4z^3"), p);
}

TEST(TPolynom, operator_equal_return_correct_value)
{
	TPolynom p("x^7-3xy^4+5z^2");
	TPolynom p2("x^5+2x-3z^5");
	EXPECT_EQ(false, p == p2);
}

TEST(TPolynom, operator_not_equal_return_correct_value)
{
	TPolynom p("x^7-3xy^4+5z^2");
	TPolynom p2("x^5+2x-3z^5");
	EXPECT_EQ(true, p != p2);
}