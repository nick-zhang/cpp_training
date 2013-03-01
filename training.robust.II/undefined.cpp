
#include "gtest\gtest.h"

namespace undefined_demo {

	TEST(Undefined, modify_string_literal_is_undefined)
	{
		//char* name = "Joy";
		//name[0] = 'Z';
		//EXPECT_STREQ("Zoy", name);
	}

	TEST(Undefined, modify_const_value_is_undefined)
	{
		const int* ciq = new const int (3);
		int* iq = const_cast<int*>(ciq);
		*iq = 4;
		EXPECT_EQ(4, *ciq);
	}

	TEST(Undefined, shift_negative_right_operand_is_undefined)
	{
		int n = 3 << -2;
		EXPECT_EQ(0, n);
	}
}