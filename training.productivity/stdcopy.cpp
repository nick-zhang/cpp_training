
#include <vector>
#include <list>
#include <gtest\gtest.h>

using namespace std;

namespace stdcopy_demo {

	TEST(Template, copy_string) {
		char* name = "Tom";
		char new_name[4];
		new_name[3] = 0;

		std::copy(name, name + strlen(name), new_name);

		EXPECT_EQ(string(name), string(new_name));
	}

	TEST(Template, copy_array_to_list) {
		vector<int> ages(3);
		ages[0] = 12;
		ages[1] = 14;
		ages[2] = 52;
		list<int> newAges(3);

		std::copy(ages.cbegin(), ages.cend(), newAges.begin());

		EXPECT_TRUE(std::equal(ages.cbegin(), ages.cend(), newAges.cbegin()));

		//int agesArray[] = {12, 14, 52};
		//int count = sizeof(agesArray) / sizeof(agesArray[52]);
		//vector<int> agesVector(agesArray, agesArray + count);
		//list<int> agesList1(agesArray, agesArray + count);
		//list<int> agesList2(agesVector.cbegin(), agesVector.cend());

		//EXPECT_TRUE(std::equal(agesVector.cbegin(), agesVector.cend(), agesList1.cbegin()));
		//EXPECT_TRUE(std::equal(agesVector.cbegin(), agesVector.cend(), agesList2.cbegin()));
	}

	TEST(Template, print_i_e_copy_to_std_cout) {

		string names[] = {"Zhao", "Qian", "Sun", "Li"};

		std::copy(names, names + sizeof(names)/sizeof(names[0]), ostream_iterator<string>(cout, "\n"));
	}
}