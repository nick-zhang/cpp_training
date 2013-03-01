
#include <gtest\gtest.h>

using namespace std;

namespace find_demo {

	template<class Iterator, class T>
	Iterator find(Iterator begin, Iterator end, const T& value) {
		while(begin != end && *begin != value) {
			++begin;
		}
		return begin;
	}

	TEST(Find, generic_find) {
		char * password = "roys1";
		char* y = find(password, password + strlen(password), 'y');
		EXPECT_EQ('y', *y);

		int ages[] = {10, 20, 30};
		int* twenties = find(ages, ages + sizeof(ages)/sizeof(ages[0]), 20);
		EXPECT_EQ(20, *twenties);

		vector<int> newAges(ages, ages + sizeof(ages)/sizeof(ages[0]));
		vector<int>::const_iterator forties = find(newAges.cbegin(), newAges.cend(), 40);
		EXPECT_EQ(newAges.cend(), forties);
	}
}