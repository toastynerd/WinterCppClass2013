#include "TestHarness.h"
#include "../test_class.h"
#include <sstream>

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
void test_func(std::stringstream& ss)
{
	TestClass test2;
	ss<<test2.probe;
}

void another_func(std::ostream& os)
{
	static Probe probe;
	probe.increase();
	os << probe;
}

TEST(test_class_creation, TestClass)
{
	std::stringstream ss;
	TestClass test1;
	TestClass test2;
	TestClass test3;
	ss << test3.probe;
	CHECK_EQUAL("3", ss.str());
	ss << test2.probe;
	CHECK_EQUAL("33", ss.str());
}

TEST(test_class_destructor, TestClass)
{
	std::stringstream ss;
	TestClass test1;
	test_func(ss);
	ss << test1.probe;
	CHECK_EQUAL("21", ss.str()); //probe will be equal to 2 while in the function test_func and equal to 1 after
}

TEST(func_probe_test, Probe)
{
	std::stringstream ss;
	another_func(ss);
	another_func(ss);
	another_func(ss);
	CHECK_EQUAL("123",ss.str());
}