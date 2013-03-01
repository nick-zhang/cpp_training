
#include <gtest\gtest.h>
#include "AutoTrace.h"

namespace prefix_postfix_demo {
	const int count = 100000000;
	int* range;

	void prefix_version()
	{
		for (int i = 0; i < count - 1;)
		{
			range[++i] = 1;
		}
	}

	void postfix_version()
	{
		for (int i = 0; i < count - 1;)
		{
			range[i++] = 2;
		}
	}

	TEST(IncrementTest, compare_prefix_and_postfix) 
	{
		range = new int[count];
		{
			AutoTrace autoTrace;
			postfix_version();
		}
		{
			AutoTrace autoTrace;
			prefix_version();
		}
		delete[] range;
	}
}