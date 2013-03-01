
#include "gtest\gtest.h"

namespace parameters {

	template<class T>
	void swap(T& first, T& second)
	{
		T temp = first;
		first = second;
		second = temp;
	}

	TEST(parameters, swap_by_reference)
	{
		std::string first("first"), second("second");
		parameters::swap(first, second);

		EXPECT_EQ("first", second);
		EXPECT_EQ("second", first);
	}
}