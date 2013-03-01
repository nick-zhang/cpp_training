
#include "gtest\gtest.h"

namespace unspecified_demo {

	bool foo(int left, int right)
	{
		return left > right;
	}

	TEST(Unspecified, microsoft_visual_cpp_evaluate_arguments_from_right_to_left)
	{
		int i = 0;

		EXPECT_TRUE(foo(i++, i++));
	}
}