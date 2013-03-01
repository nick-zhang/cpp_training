
#include "gtest\gtest.h"

namespace sequence_point {

	TEST(SequencePoint, modify_stored_value_more_than_once_in_same_expression_is_unspecified)
	{
		int i = 0;
		int values[] = {100, 200, 300};

		i = values[i++];

		EXPECT_EQ(101, i);

		i = 0;
		i = i++ + 2;
		
		EXPECT_EQ(3, i);
	}

	struct Name{
		static int n;
		Name()
		{
			if(n++ % 2 == 0) throw "";
		}
	};

	int Name::n = 0;

	void foo(Name* first_name, Name* last_name)
	{
	}

	TEST(SequencePoint, make_this_call_exceptional_safe)
	{
		Name name1;
		Name name2;
		foo(&name1, &name2);
		//How many ways can you imagine?
	}

	struct ClassManagingMultiResources
	{
		ClassManagingMultiResources() : first(new Name), last(new Name){}
		~ClassManagingMultiResources() {delete first; delete last;}
	private:
		Name *first, *last;
	};
}