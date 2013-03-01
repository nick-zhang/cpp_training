
#include <algorithm>
#include <gtest\gtest.h>

using namespace std;

namespace stdfind_demo {

	struct StdFindTest : ::testing::Test {
		vector<int> ages;

		StdFindTest() {
			int agesArray[] = {10, 15, 23, 79, 46, 100}; 
			ages = vector<int>(agesArray, agesArray + sizeof(agesArray) / sizeof(agesArray[0]));
		}
	};

	TEST_F(StdFindTest, find_exact_value)
	{
		EXPECT_EQ(23, *find_if(ages.cbegin(), ages.cend(), bind1st(equal_to<int>(), 23)));
	}

	TEST_F(StdFindTest, find_first_greater_than_80)
	{
		//EXPECT_EQ(100, ???);
	}

	TEST_F(StdFindTest, find_first_odd)
	{
		//EXPECT_EQ(15, ???);
	}

	TEST_F(StdFindTest, find_last_odd)
	{
		//EXPECT_EQ(79, ???);
	}
}