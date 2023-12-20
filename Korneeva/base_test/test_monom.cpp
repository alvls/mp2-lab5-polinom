#include <gtest.h>
#include "monom.h"

TEST(MonomTest, can_create_monom)
{
	ASSERT_NO_THROW(Monom monom);
}

TEST(MonomTest, can_create_default_monom)
{
	Monom monom;
	EXPECT_EQ(monom.coefficient, 0);
	EXPECT_EQ(monom.degree, 0);
}

TEST(MonomTest, can_create_monom_with_positive_coef)
{
	Monom monom(2.5, 321);
	EXPECT_EQ(monom.coefficient, 2.5);
	EXPECT_EQ(monom.degree, 321);
}

TEST(MonomTest, can_create_monom_with_negative_coef)
{
	Monom monom(-2.5, 321);
	EXPECT_EQ(monom.coefficient, -2.5);
	EXPECT_EQ(monom.degree, 321);
}

TEST(MonomTest, throws_exception_for_monom_with_excessive_degrees)
{
	ASSERT_ANY_THROW(Monom monom(2.5, 3210));
}

TEST(MonomTest, can_create_monom_with_positive_coef_from_string) 
{
	Monom monom("3.7x^2y^3z^1");
	EXPECT_EQ(monom.coefficient, 3.7);
	EXPECT_EQ(monom.degree, 231);
}

TEST(MonomTest, can_create_monom_with_negative_coef_from_string)
{
	Monom monom("-3.7x^2y^3z^1");
	EXPECT_EQ(monom.coefficient, -3.7);
	EXPECT_EQ(monom.degree, 231);
}

TEST(MonomTest, can_create_monom_with_zero_coef_from_string)
{
	Monom monom("0x^2y^3z^1");
	EXPECT_EQ(monom.coefficient, 0);
}

TEST(MonomTest, can_create_monom_with_default_degree)
{
	Monom monom("3.7x^2yz");
	EXPECT_EQ(monom.degree, 211);
}

TEST(MonomTest, can_create_monom_with_default_positive_coefficient)
{
	Monom monom("x^2y^3z^1");
	EXPECT_EQ(monom.coefficient, 1);
	EXPECT_EQ(monom.degree, 231);
}

TEST(MonomTest, can_create_monom_with_default_negative_coefficient)
{
	Monom monom("-x^2y^3z^1");
	EXPECT_EQ(monom.coefficient, -1);
	EXPECT_EQ(monom.degree, 231);
}

TEST(MonomTest, throws_exception_for_monom_from_invalid_string) 
{
	EXPECT_ANY_THROW(Monom monom("invalid_monom"));
}

TEST(MonomTest, throws_exception_for_monom_from_invalid_string_with_invalid_degrees)
{
	EXPECT_ANY_THROW(Monom monom("2x^-1"));
}

TEST(MonomTest, throws_exception_for_monom_from_invalid_string_with_excessive_degrees)
{
	EXPECT_ANY_THROW(Monom monom("2x^10"));
}

TEST(MonomTest, test_operator_less_than) 
{
	Monom monom1("2x^2");
	Monom monom2("3x^3");
	EXPECT_TRUE(monom1 < monom2);
}

TEST(MonomTest, est_operator_greater_than)
{
	Monom monom1("4y^3");
	Monom monom2("2y^2");
	EXPECT_TRUE(monom1 > monom2);
}

TEST(MonomTest, equal_operator_returns_true_for_equal_monoms) 
{
	Monom monom1("2z^1");
	Monom monom2("2z^1");
	ASSERT_TRUE(monom1==monom2);
	ASSERT_FALSE(monom1 != monom2);
}

TEST(MonomTest, equal_operator_returns_true_for_unequal_monoms)
{
	Monom monom1("2z^1");
	Monom monom2("4z^1");
	ASSERT_TRUE(monom1 != monom2);
	ASSERT_FALSE(monom1 == monom2);
}

TEST(MonomTest, test_operator_multiply_for_correct_degrees)
{
	Monom monom1("2x^2y^4");
	Monom monom2("3x^3z^2");
	Monom result = monom1 * monom2;
	EXPECT_EQ(result.coefficient, 6.0);
	EXPECT_EQ(result.degree, 542);
}

TEST(MonomTest, test_operator_multiply_for_uncorrect_degrees)
{
	Monom monom1("2x^9y^4");
	Monom monom2("3x^2z^2");
	
	EXPECT_ANY_THROW(Monom result = monom1 * monom2);
}

TEST(MonomTest, calculates_correct_value_for_monom) 
{
	Monom monom(2.0, 301); // Моном 2x^3z

	double x = 2.5;
	double y = 1.0;
	double z = -3.0;

	double result = monom.calculate(x, y, z);

	// Ожидаемый результат: 2.0 * (2.5)^3 * 1.0 * (-3.0)^1
	double expected = 2.0 * pow(x, 3) * pow(y, 0) * pow(z, 1);

	EXPECT_DOUBLE_EQ(result, expected);
}