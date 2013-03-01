
#include "gtest\gtest.h"

namespace const_exercise {
	struct Integer {
		operator bool()
		{
			return true; //return this != 0;
		}
	};

	Integer operator* (const Integer& lhs, const Integer& rhs)
	{
		return Integer();
	}

	TEST(Const, qualify_return_value_with_const_to_avoid_unintentional_assignment)
	{
		Integer a, b, c;
		if( a*b = c){}
	}



	void assign_new_value(const int& n, int newValue) {
		(const_cast<int&>(n)) = newValue;
	}

	const int global = 1;

	TEST(Const, storage_const_and_logical_const)
	{
		const int local = 1;
		int nonConst = 1;

		//assign_new_value(nonConst, 3);
		//EXPECT_EQ(3, nonConst);

		//assign_new_value(local, 3);
		//EXPECT_EQ(3, local);

		//assign_new_value(global, 3);
		//EXPECT_EQ(3, global);
	}


	struct TextBlock {
		TextBlock(){text = new char[10];}
		~TextBlock() {delete text;}

		const char& operator[](std::size_t position) const
		{ 
			return text[position]; 
		}

	    char& operator[](std::size_t position) 
		{ 
			return text[position]; 
		}

	private:
		char* text;
	};

	TEST(Const, bitwise_constness_is_not_enough)
	{
		const TextBlock constTextBlock;
		//jconstTextBlock[3] = 'A';
	}

	TEST(Const, const_qualifier_is_considered_in_overloading_resolving)
	{
		const TextBlock constTextBlock;
		std::cout << constTextBlock[3];

		TextBlock textBlock;
		textBlock[3] = 'A';
	}
}