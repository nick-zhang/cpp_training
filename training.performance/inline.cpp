
#include <algorithm>
#include <gtest\gtest.h>
#include "AutoTrace.h"

namespace inline_demo {

	int pow(int n) {
		return n * n;
	}

	inline int pow_inline_version(int n) {
		return n * n;
	}

	TEST(Inline, test_diff_of_inline)
	{
		const int loops = 10000000;
		{
			AutoTrace autoTrace;
			for(int i = 0; i < loops; i ++) {
				pow(i);
			}
		}
		{
			AutoTrace autoTrace;
			for(int i = 0; i < loops; i ++) {
				pow_inline_version(i);
			}
		}
	}
}