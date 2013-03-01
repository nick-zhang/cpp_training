
#include <gtest\gtest.h>

namespace return_value_optimization_demo {
	struct SomeClass {
		static int instances;

		SomeClass() {instances++;}
		SomeClass(const SomeClass&){instances++;}
	};

	int SomeClass::instances = 0;

	SomeClass RVO_version() {
		return SomeClass();
	}

	SomeClass Named_RVO_version() {
		SomeClass obj;
		return obj;
	}

	struct ReturnValueOptimizationTest : ::testing::Test {
		ReturnValueOptimizationTest() {SomeClass::instances = 0;}
	};

	TEST_F(ReturnValueOptimizationTest, rvo_applied_when_return_expression_is_a_call_of_ctor)
	{
		SomeClass obj = RVO_version();
		//EXPECT_EQ(1, SomeClass::instances);
	}

	TEST_F(ReturnValueOptimizationTest, does_vcpp_support_NRVO_eh)
	{
		SomeClass obj = Named_RVO_version();
		//EXPECT_EQ(2, SomeClass::instances);
	}
}