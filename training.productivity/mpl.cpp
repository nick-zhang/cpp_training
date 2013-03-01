
#include <gtest\gtest.h>

namespace fibonacci_demo {

	template<unsigned long long N>
	struct fibonacci {
		static const unsigned long long value = fibonacci<N-1>::value + fibonacci<N-2>::value;
	};

	template<>
	struct fibonacci<1> {
		static const unsigned long long value = 1;
	};

	template<>
	struct fibonacci<2> {
		static const unsigned long long value = 1;
	};

	TEST(TemplateMetaProgramming, fibonacci_in_compile_time)
	{
		EXPECT_EQ(8, fibonacci<6>::value);
		EXPECT_EQ(12200160415121876738, fibonacci<93>::value);
	}

}
	
namespace factorial_demo {
	template<unsigned long long N>
	struct factorial {
		static const unsigned long long value = N * factorial<N-1>::value;
	};

	template<>
	struct factorial<0> {
		static const unsigned long long value = 1;
	};

	TEST(TemplateMetaProgramming, factorial_in_compile_time)
	{
		EXPECT_EQ(24, factorial<4>::value);
	}

	template<class T, unsigned int N>
	struct Permutation {
		T permutations[factorial<N>::value];
	};

	TEST(TemplateMetaProgramming, calculate_array_size_at_compile_time)
	{
		Permutation<std::string, 5> gambling;
		EXPECT_EQ(120, sizeof(gambling.permutations) / sizeof(gambling.permutations[0]));
	}
}


namespace binary_literal_demo {
	template <unsigned long N>
	struct binary
	{
		static unsigned const value 
			= binary<N/10>::value << 1   // prepend higher bits
			| N%10;                    // to lowest bit
	};

	template <>                           // specialization
	struct binary<0>                      // terminates recursion
	{
		static unsigned const value = 0;
	};

	TEST(TemplateMetaProgramming, use_literal_binary_nuumber)
	{
		EXPECT_EQ(15, binary<1111>::value);
		EXPECT_EQ(149, binary<10010101>::value);
	}
}

namespace type_traits_demo {

	template <class ForwardIterator>
	void iter_swap(ForwardIterator i1, ForwardIterator i2)
	{
		//T tmp = *i1;
		//*i1 = *i2;
		//*i2 = tmp;
	}

	TEST(TemplateMetaProgramming, type_traits)
	{
		//std::vector<int> a, b;
		//a.push_back(3);
		//b.push_back(4);
		//
		//iter_swap(a.begin(), b.begin());

		//EXPECT_EQ(4, *a.begin());
		//EXPECT_EQ(3, *b.begin());

		//int ages[] = {3,4};

		//iter_swap(&ages[0], &ages[1]);

		//EXPECT_EQ(4, ages[0]);
		//EXPECT_EQ(3, ages[1]);
	}

}