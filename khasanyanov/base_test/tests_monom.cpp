#include "gtest.h"
#include "monom.h"

TEST(Monom, cam_create_monom) {
	ASSERT_NO_THROW(Monom m (1,1,1,1));
}

TEST(Monom, cam_copy_monom) {
	Monom c(1,2,3,4);
	ASSERT_NO_THROW(Monom m(c));
	EXPECT_EQ(c, Monom{ c });
}

TEST(Monom, can_create_monom_from_string) {
	ASSERT_NO_THROW(Monom{ "-2xz4" });
}

TEST(Monom, test_divide_operators) {
	Monom c(1, 2, 3, 4);
	Monom m(2, 1, 2, 4);
	Monom res(0.5, 1, 1, 0);
	ASSERT_NO_THROW(c / m);
	c /= m; 
	EXPECT_EQ(res, c);
}