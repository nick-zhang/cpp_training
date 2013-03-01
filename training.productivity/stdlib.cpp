
#include <gtest\gtest.h>

namespace std_lib_demo {

	std::string int_to_string(int depth) {
		std::ostringstream output;
		output << std::hex << std::showbase << std::uppercase << depth;
		return output.str();
	}
	
	std::string double_to_string(double depth, int precesion) {
		std::ostringstream output;
		output << std::setprecision(precesion) << depth;
		return output.str();
	}

	int string_to_number(const std::string& depth) {
		int returnValue;
		std::istringstream input(depth);
		input >> returnValue;
		return returnValue;
	}

	TEST(StdLibDemo, itoa)
	{
		EXPECT_EQ("0XFF", int_to_string(255));
		EXPECT_EQ(255, string_to_number("255"));

		EXPECT_EQ("4321.57", double_to_string(4321.5678, 6));
	}
}