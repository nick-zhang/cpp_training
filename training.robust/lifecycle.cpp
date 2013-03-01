
#include <string>
#include "gtest\gtest.h"

namespace{

	struct Base
	{
		int intValue;
		bool boolValue;
		char* pointerValue;
		int theArray[10];
		std::string stringObject;

		void foo(){}
		void virtual bar(){}
	};

	struct SomeClass : Base
	{
		int memberInSub;
	};

	TEST(Lifecycle, POD_members_WONT_be_initialized_to_0_by_default)
	{
		SomeClass classWithPOD;
		EXPECT_NE(0, classWithPOD.intValue);
		EXPECT_NE(false, classWithPOD.boolValue);
		EXPECT_NE((char*)NULL, classWithPOD.pointerValue);
		EXPECT_NE(0, classWithPOD.theArray[0]);
		EXPECT_NE(0, classWithPOD.memberInSub);
	}

	TEST(Lifecycle, members_with_default_ctor_will_be_initialized_by_calling_default_ctor)
	{
		SomeClass classWithObject;
		EXPECT_EQ("", classWithObject.stringObject);
	}

	TEST(Lifecycle, default_copy_ctor_initialize_members_memberwisely)
	{
		SomeClass first;
		first.stringObject = "some string object";
		first.theArray[3] = 9527;

		SomeClass second(first);

		EXPECT_EQ(second.boolValue, first.boolValue);
		EXPECT_EQ(second.intValue, first.intValue);
		EXPECT_EQ(second.pointerValue, first.pointerValue);
		EXPECT_EQ(second.stringObject, first.stringObject);
		EXPECT_EQ(second.theArray[3], first.theArray[3]);
		EXPECT_EQ(second.memberInSub, first.memberInSub);
	}

	TEST(Lifecycle, memberwise_copying_for_array_means_copying_content)
	{
		SomeClass first;
		first.theArray[0] = 9527;
		SomeClass second(first);

		EXPECT_EQ(second.theArray[0], first.theArray[0]);

		first.theArray[0] = 123;
		EXPECT_NE(second.theArray[0], first.theArray[0]);
	}

	TEST(Lifecycle, memberwise_copying_for_poniter_means_copying_pointer_itself_NOT_content)
	{
		char name[10] = {0};

		SomeClass first;
		first.pointerValue = name;
		first.pointerValue[0] = 's';
		SomeClass second(first);

		EXPECT_EQ(second.pointerValue, first.pointerValue);
		EXPECT_EQ(second.pointerValue[0], first.pointerValue[0]);

		first.pointerValue[0] = 't';
		EXPECT_EQ(second.pointerValue[0], first.pointerValue[0]);
	}

	struct InitOrderTest
	{
		int i;
		int j;

		InitOrderTest() : j(3), i(j){}
	};

	TEST(Lifecycle, initialized_by_declaration_order)
	{
		InitOrderTest obj;

		EXPECT_EQ(3, obj.j);
		EXPECT_NE(obj.i, obj.j);
	}

	struct MemoryLeaks
	{
		char* name;
		MemoryLeaks() : name(new char[10]) {
			throw ""; //Exception Happened 
		}
	};

}