//Tyler Morgan
//Feb-10-2013
//C++ Programming introduction
//Assignment 1.5
#include "TestHarness.h"
#include <vector>

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested

TEST(vectorTest, vector)
{
	std::vector<int> test_vector;
	int vector_total = 0;

	for(int x =0; x < 10; x++)
	{
		test_vector.push_back(x);
		vector_total = vector_total + test_vector[x];
	}
	CHECK_EQUAL(45,vector_total);

}