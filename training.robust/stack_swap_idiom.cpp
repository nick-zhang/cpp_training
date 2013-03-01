
#include "gtest\gtest.h"

namespace {

	template<class T>
	class Stack
	{
	public:
		size_t capacity;
		size_t used;
		T* values;

	public:
		Stack(size_t size): capacity(size), used(0), values(new T[size]) {}
		~Stack(){delete[] values;}

		Stack(const Stack& other)
		{
			values = new T[other.capacity];
			try
			{
				std::copy(other.values, other.values + other.capacity, values);
				capacity = other.capacity;
				used = other.used;
			}
			catch(...)
			{
				delete[] values;
				throw;
			}
		}

		Stack& operator = (const Stack& other)
		{
			Stack newObj(other);
			swap(*this, newObj);
			return *this;
		}
	private:
		void swap(Stack& first, Stack& second)
		{
			std::swap(first.capacity, second.capacity);
			std::swap(first.used, second.used);
			std::swap(first.values, second.values);
		}

	public:
		void push(const T& obj)
		{
			if(used == capacity)
			{
				throw "stack is full";
			}
			values[used] = obj;
			used++;
		}

		void pop()
		{
			if(used == 0)
			{
				throw "stack is empty";
			}
			used--;
		}

		const T& top() const
		{
			if(used == 0)
			{
				throw "stack is empty";
			}
			return values[used - 1];
		}
	};

	TEST(ExceptionSafe, copy_and_swap_idiom)
	{
		Stack<int> first(10), second(20);
		first = second;
		EXPECT_EQ(20, first.capacity);
	}

	TEST(ExceptionSafe, push_should_throw_exception_if_stack_is_full)
	{
		Stack<std::string> stack(0);
		EXPECT_ANY_THROW(stack.push(""));
	}

	TEST(ExceptionSafe, pop_should_throw_exception_if_stack_is_empty)
	{
		Stack<std::string> stack(0);
		EXPECT_ANY_THROW(stack.pop());
	}

	TEST(ExceptionSafe, top_should_throw_exception_if_stack_is_empty)
	{
		Stack<std::string> stack(0);
		EXPECT_ANY_THROW(stack.top());
	}
}