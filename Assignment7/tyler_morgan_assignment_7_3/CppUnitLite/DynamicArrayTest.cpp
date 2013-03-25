#include "TestHarness.h"
#include "../dynamic_array.h"
#include <iostream>

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
TEST(write_at, DynamicArray)
{
	DynamicArray array1;
	array1.write_at(4, 5);
	array1.get_at(2);
	CHECK_EQUAL(5, array1.get_at(4));
}

TEST(put_at, DynamicArray)
{
	DynamicArray array1;
	for(int x = 0;x<10;x++)
	{
		array1.write_at(x,x);
	}
	array1.put_at(4,10);
	CHECK_EQUAL(9, array1.get_at(10));
}

TEST(size, DynamicArray)
{
	DynamicArray array1;
	for(int x = 0;x<=10;x++)
	{
		array1.write_at(x,x);
	}
	array1.put_at(4,10);
	CHECK_EQUAL(11, array1.size());	
}

TEST(newone, DynamicArray)
{
	DynamicArray array1;
	array1.write_at(5,0);
	array1.write_at(6,1);
	array1.write_at(7,2);
	CHECK_EQUAL(7, array1.get_at(2));
}