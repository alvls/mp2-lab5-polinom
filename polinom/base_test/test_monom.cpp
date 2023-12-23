#include "Monom.h"
#include <gtest.h>

TEST(Monom, can_create_monom)
{
    ASSERT_NO_THROW(monom m);
}

TEST(Monom, can_get_vars)
{
    monom m("x^2");

    ASSERT_NO_THROW(m.getVars());
}

TEST(Monom, can_is_equal)
{
    monom m("x^2");
    monom m1("x^2");

    EXPECT_TRUE(m == m1);
}

TEST(Monom, can_mult)
{
    monom m("x^2");
    monom m1("2x^2");

    ASSERT_NO_THROW(m * m1);
}