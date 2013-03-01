
#include "gtest\gtest.h"

using namespace std;

namespace A {
	struct X{};
	string bar(X x) {return "A";}
}

namespace name_lookup_demo {
	
	//string bar(A::X x) {return bar(x);}

	TEST(NameLookup, koenig_lookup)
	{
		EXPECT_EQ("A", bar(A::X()));
	}

	struct Base {
		virtual string bar() {return "Base bar";}
		void for_overload() {}
	};

	struct Sub : Base{
		virtual string bar() {return "Sub bar";}
		void for_overload(int) {}
	};

	string foo(Base& obj) { return "Base foo " + obj.bar();} 
	string foo(Sub& obj) { return "Sub foo " + obj.bar();} 

	TEST(NameLookup, overload_is_resolved_by_static_type)
	{
		Sub sub;
		Base& base = sub;

//		EXPECT_EQ("??? foo ??? bar", foo(base));
//		EXPECT_EQ("??? foo ??? bar", foo(sub));
	}

	TEST(NameLookup, redefine_function_in_sub_class_will_hide_definition_in_base_class)
	{
		Sub sub;
//		sub.for_overload();
		sub.for_overload(3);
	}

	struct DefaultParameterDemo {
		int validate(string email, bool casesensitive = true) {
			return casesensitive ? 1 : -1;
		}
	};

	TEST(NameLookup, default_parameter_considered_harmful)
	{
		EXPECT_EQ(1, DefaultParameterDemo().validate("er"));
	}

	struct PrivateVirtualBase {
		string foo() {return bar();}
	private:
		virtual string bar() {return "Base";}
	};

	struct PrivateVirtualSub : PrivateVirtualBase {
	private:
		virtual string bar() {return "Sub";}
	};

	TEST(NameLookup, will_invoke_private_vitual_method_defined_in_subclass)
	{
		//EXPECT_EQ(???, PrivateVirtualSub().foo());
	}
}