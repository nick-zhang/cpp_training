
#include "gtest\gtest.h"

namespace explicit_demo {

	struct MyString {

		explicit MyString(char* original) {
		}
	};

	int print(const MyString& string) {
		return 2;
	}

	TEST(Explicit, one_parameter_ctor_will_be_involved_in_implicit_converting)
	{
		EXPECT_EQ(2, print(MyString("shouldn't be compiled")));
	}
}