
#include "gtest\gtest.h"

namespace {
	bool locked = false;

	void lock(){locked = true;}

	void unlock(){locked =false;}

	void do_something_may_fail(){throw "";}

	struct Lock {
		Lock(){lock();}
		~Lock(){unlock();}
	};

	void multi_thread_op()
	{
		Lock();		
		do_something_may_fail();
	}

	TEST(RAII, should_unlock_anyway)
	{
		try{
			multi_thread_op();
		} catch (...) {
		}

		EXPECT_FALSE(locked);
	}
}

namespace autoptr_demo {

	struct Resource {};

	TEST(RAII, copy_auto_ptr_will_transfer_the_ownership)
	{
		std::auto_ptr<Resource> pointer1(new Resource());
		Resource* rawPointer = pointer1.get();

		std::auto_ptr<Resource> pointer2(pointer1);

		EXPECT_NE(pointer1.get(), pointer2.get());

		EXPECT_EQ(rawPointer, pointer2.get());
		EXPECT_EQ((void*)NULL, pointer1.get());
	}
}