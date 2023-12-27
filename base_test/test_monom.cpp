#include "gtest.h"
#include <Monom.h>

TEST(TMonom, can_create_monom_using_default_constructor)
{
	ASSERT_NO_THROW(TMonom monom);
}

TEST(TMonom, can_create_monom_by_passing_arguments)
{
	TMonom monom(-2.0, 0);
	EXPECT_EQ(-2.0, monom.coefficient);
	EXPECT_EQ(0, monom.degree);
}

TEST(TMonom, can_create_monom_from_string)
{
	ASSERT_NO_THROW(TMonom("-2x^5y^3"));
}

TEST(TMonom, can_create_monom_with_positive_coefficient)
{
	TMonom monom("5.2x^3y^4");
	EXPECT_EQ(5.2, monom.coefficient);
	EXPECT_EQ(340, monom.degree);
}

TEST(TMonom, can_create_monom_with_positive_coefficient_v2)
{
	TMonom monom(5.2, 340);
	EXPECT_EQ(5.2, monom.coefficient);
	EXPECT_EQ(340, monom.degree);
}

TEST(TMonom, can_create_monom_with_negative_coefficient)
{
	TMonom monom("-3.6x^4y^2z^5");
	EXPECT_EQ(-3.6, monom.coefficient);
	EXPECT_EQ(425, monom.degree);
}

TEST(TMonom, can_create_monom_with_negative_coefficient_v2)
{
	TMonom monom(-3.6, 425);
	EXPECT_EQ(-3.6, monom.coefficient);
	EXPECT_EQ(425, monom.degree);
}

TEST(TMonom, can_create_monom_with_explicit_degree_input)
{
	TMonom monom(5, 700);
	EXPECT_EQ(700, monom.degree);
	EXPECT_EQ(5.0, monom.coefficient);
}

TEST(TMonom, can_create_monom_with_explicit_degree_input_v2)
{
	TMonom monom("5x^7y^3z^2");
	EXPECT_EQ(732, monom.degree);
	EXPECT_EQ(5.0, monom.coefficient);
}

TEST(TMonom, can_create_monom_without_explicit_degree_input)
{
	TMonom monom(4);
	EXPECT_EQ(0, monom.degree);
	EXPECT_EQ(4.0, monom.coefficient);
}

TEST(TMonom, can_create_monom_without_explicit_degree_input_v2)
{
	TMonom monom("4xyz");
	EXPECT_EQ(111, monom.degree);
	EXPECT_EQ(4.0, monom.coefficient);
}

TEST(TMonom, cant_create_monom_with_negative_degree)
{
	ASSERT_ANY_THROW(TMonom("2x^-4"));
}

TEST(TMonom, cant_create_monom_with_degree_that_exceeds_allowed_value)
{
	ASSERT_ANY_THROW(TMonom("3x^10"));
}

TEST(TMonom, cant_create_monom_with_too_large_degree)
{
	ASSERT_ANY_THROW(TMonom("3x^9999"));
}

TEST(TMonom, cant_create_monom_with_invalid_string_source)
{
	ASSERT_ANY_THROW(TMonom("4ab^2c^3"));
}

TEST(TMonom, operator_less_than_return_correct_value)
{
	EXPECT_EQ(true, TMonom("1.5x^2") < TMonom("2x^2"));
}

TEST(TMonom, operator_greater_than_return_correct_value)
{
	EXPECT_EQ(true, TMonom("3x^5") > TMonom("2x^3"));
}

TEST(TMonom, operator_equal_return_correct_value)
{
	EXPECT_EQ(true, TMonom("3.5x^4y^3") == TMonom("3.5x^4y^3"));
	EXPECT_EQ(false, TMonom("1.8x^2") == TMonom("1.9x^2"));
}

TEST(TMonom, operator_not_equal_than_return_correct_value)
{
	EXPECT_EQ(true, TMonom("1.8x^2") != TMonom("1.9x^2"));
	EXPECT_EQ(false, TMonom("3.5x^4y^3") != TMonom("3.5x^4y^3"));
}

TEST(TMonom, operator_multiply_works_correctly)
{
	TMonom product = TMonom("2x^3y^3z^2") * TMonom("4x^2y^2z^3");
	EXPECT_EQ(8, product.coefficient);
	EXPECT_EQ(555, product.degree);
}

TEST(TMonom, can_calculate_monom_at_point)
{
	TMonom monom("2x^3y^5");
	EXPECT_EQ(64, monom.calculate(1, 2, 3));
}