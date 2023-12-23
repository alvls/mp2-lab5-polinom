#include "Polinom.h"
#include <gtest.h>

TEST(Polinom, can_create_polinom)
{
    ASSERT_NO_THROW(polinom p("x^2+z^2"));
}

TEST(Polinom, can_create_polinom_with_space)
{
    ASSERT_NO_THROW(polinom p("x^2 + z  ^2"));
}

TEST(Polinom, can_create_polinom_with_dif_reg)
{
    ASSERT_NO_THROW(polinom p("X^2 + z^2 - xY"));
}

TEST(Polinom, can_create_polinom_with_signs)
{
    ASSERT_NO_THROW(polinom p("4*x^2+z^2*y"));
}

TEST(Polinom, can_bringingSimilar)
{
    ASSERT_NO_THROW(polinom p("4*x^2+x^2"));
}

TEST(Polinom, can_get_in_point)
{
    polinom p("2x^2z^3-z^4+2x^5");

    EXPECT_EQ(p.inPoint(1, 0, 2), 2);
}

TEST(Polinom, can_sum)
{
    polinom p("2x^2 + z^3x - 3zx");
    polinom p1("x^2 + 3zx");

    ASSERT_NO_THROW(p.sum(p1));
}

TEST(Polinom, can_mult)
{
    polinom p("2x^2 + y^2");
    polinom p1("y^2 + 2x^2");

    ASSERT_NO_THROW(p.mult(p1));
}