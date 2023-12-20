#include <gtest.h>
#include "polinom.h"

TEST(MonomTest, can_create_polinom)
{
	ASSERT_NO_THROW(Polinom polinom);
}

TEST(PolinomTest, can_create_polinom_from_correct_string)
{
	Polinom polinom("2x^2 + 3xy - 4yz^2");

	EXPECT_EQ(polinom.toString(), "2x^2 + 3xy - 4yz^2");
}

TEST(PolinomTest, throws_exception_for_polinom_with_excessive_degrees)
{
	ASSERT_ANY_THROW(Polinom polinom("2x^10 + 3xy - 4yz^2"));
}

TEST(PolinomTest, throws_exception_for_polinom_with_invalid_degrees)
{
	ASSERT_ANY_THROW(Polinom polinom("2x^-3 + 3xy - 4yz^2"));
}

TEST(PolinomTest, can_copy_polinom) 
{
	Polinom original("2x^2 + 3xy - 4yz^2");
	Polinom copy(original);

	EXPECT_EQ(original, copy);
}

TEST(PolinomTest, copied_polinom_is_independent)
{
	Polinom original("2x^2 + 3y^3 - 4z");
	Polinom copy(original);

	copy+= original;

	EXPECT_NE(original, copy);
}

TEST(PolinomTest, can_assign_polinom_to_another)
{
	Polinom original("2x^2 + 3xy - 4yz^2");
	Polinom copy;
	copy = original;

	EXPECT_EQ(original, copy);
}

TEST(PolinomTest, assign_polinom_is_independent)
{
	Polinom original("2x^2 + 3y^3 - 4z");
	Polinom copy = original;

	copy += original;

	EXPECT_NE(original, copy);
}

TEST(PolinomTest, can_assign_polinom_to_itself)
{
	Polinom polinom1("2x^2 + 3y^3 - 4z");
	ASSERT_NO_THROW(polinom1 = polinom1);
	Polinom polinom2(polinom1);
	polinom1 = polinom1;

	EXPECT_EQ(polinom1, polinom2);
}

TEST(PolinomTest, equal_operator_returns_true_for_equal_polinoms)
{
	Polinom polinom1("2x^2 + 3xy - 4yz^2");
	Polinom polinom2("2x^2 + 3xy - 4yz^2");
	ASSERT_TRUE(polinom1 == polinom2);
	ASSERT_FALSE(polinom1 != polinom2);
}

TEST(PolinomTest, equal_operator_returns_true_for_unequal_polinoms)
{
	Polinom polinom1("2x^2 + 3xy - 4yz^2");
	Polinom polinom2("4yz^2");
	ASSERT_TRUE(polinom1 != polinom2);
	ASSERT_FALSE(polinom1 == polinom2);
}

TEST(PolinomTest, test_addition_operator)
{
	Polinom polinom1("2x^2 + 3y - z");
	Polinom polinom2("4x^2 - y^2 + z");

	Polinom result = polinom1 + polinom2;
	Polinom expected_result("6x^2 + 3y - y^2");

	EXPECT_EQ(result, expected_result);
}

TEST(PolinomTest, test_addition_plus_operator)
{
	Polinom polinom1("2x^2 + 3y - z");
	Polinom polinom2("4x^2 - y^2 + z");
	polinom1 += polinom2;

	Polinom expected_result("6x^2 + 3y - y^2");
	EXPECT_EQ(polinom1, expected_result);
}

TEST(PolinomTest, test_subtraction_operator) 
{
	Polinom polinom1("2x^2 + 3xy");
	Polinom polinom2("x^2 + 4yz");

	Polinom result = polinom1 - polinom2;

	EXPECT_EQ(result.toString(), "x^2 + 3xy - 4yz");
}

TEST(PolinomTest, test_subtraction_assign_operator) 
{
	Polinom polinom1("2x^2 + 3xy");
	Polinom polinom2("x^2 + 4yz");

	polinom1 -= polinom2;

	EXPECT_EQ(polinom1.toString(), "x^2 + 3xy - 4yz");
}

TEST(PolinomTest, test_subtraction_assign_operator_with_negatives) 
{
	Polinom polinom1("x^2 + y^2");
	Polinom polinom2("x^2 - y^2");

	polinom1 -= polinom2;

	EXPECT_EQ(polinom1.toString(), "2y^2");
}

TEST(PolinomTest, test_multiplication_by_positive_constant)
{
	Polinom polinom("2x^2 + 3xy - 4yz^2");

	double constant = 2.0;
	polinom *= constant;

	EXPECT_EQ(polinom.toString(), "4x^2 + 6xy - 8yz^2");
}

TEST(PolinomTest, test_multiplication_by_negative_constant)
{
	Polinom polinom("2x^2 + 3xy - 4yz^2");

	double constant = -3.0;
	polinom *= constant;

	EXPECT_EQ(polinom.toString(), "- 6x^2 - 9xy + 12yz^2");
}

TEST(PolinomTest, test_multiplication_zero)
{
	Polinom polinom("2x^2 + 3xy - 4yz^2");

	double constant = 0.0;
	polinom *= constant;

	EXPECT_EQ(polinom.toString(), "0");
}

TEST(PolinomTest, test_multiplication_operator_with_zero_polinom)
{
	Polinom polinom1("2x^2 + 3xy");
	Polinom polinom2;

	Polinom result = polinom1 * polinom2;

	EXPECT_EQ(result.toString(), "0");
}

TEST(PolinomTest, test_multiplication_operator) 
{
	Polinom polinom1("2x^2 + 3xy");
	Polinom polinom2("-x^2 + 4yz");

	Polinom result = polinom1 * polinom2;

	EXPECT_EQ(result.toString(), "- 2x^4 + 8x^2yz - 3x^3y + 12xy^2z");
}