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