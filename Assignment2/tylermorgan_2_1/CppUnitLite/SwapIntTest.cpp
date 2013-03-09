#include "TestHarness.h"
#include "../swap_int.h"

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
bool swap_ints_pntr(int int_one,int int_two);
bool swap_ints_ref(int& int_one,int& int_two);

TEST(test_pointer_swap, swap_ints_pntr)
{
	int one = 1;
	int two = 2;
	swap_ints_pntr(&one,&two);

	CHECK_EQUAL(1,two);
}

TEST(test_reference_swap, swap_ints_ref)
{
	int one = 1;
	int two = 2;
	swap_ints_ref(one,two);

	CHECK_EQUAL(2,one);
}

