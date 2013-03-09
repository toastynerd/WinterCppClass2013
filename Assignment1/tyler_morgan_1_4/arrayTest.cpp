//Tyler Morgan
//Feb-10-2013
//C++ programming introduction
//Assignment 1.4
#include "TestHarness.h"
#include <iostream>
// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
TEST(arrayTest, array)
{
	int* my_array = new int[9];
	int total_int = 0;
	for(int x =0; x < 10;x++)
	{
		my_array[x] = x;
		total_int += my_array[x];
	}	
	CHECK_EQUAL(45,total_int);
	delete[] my_array;
}