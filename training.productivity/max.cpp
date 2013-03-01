
#include <gtest\gtest.h>

namespace max_demo {

	int max(int a, int b) {
		return a > b ? a : b;
	}

	TEST(GenericMax, generic_max)
	{
		EXPECT_EQ(3, max(2,3));
		//EXPECT_EQ("zoo", max("zoo", "foo"));
		//EXPECT_EQ(1.5, max(0.3, 1.5));
	}
}