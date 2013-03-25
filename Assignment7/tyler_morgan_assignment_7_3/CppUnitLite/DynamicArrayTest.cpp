#include "TestHarness.h"
#include "../dynamic_array.h"

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
TEST(write_at, DynamicArray)
{
	DynamicArray array1;
	array1.write_at(4, 5);
	//CHECK_EQUAL(0, array1.get_at(2));
	CHECK_EQUAL(5, array1.get_at(4));
}

TEST(something, something_else)
{
	CHECK_EQUAL(0,0);
	CHECK_EQUAL(1,1);
}