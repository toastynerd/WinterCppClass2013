#include <sstream>
#include <string>
#include "TestHarness.h"
#include "../cat.h"

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
TEST(c_style, cat)
{
	std::stringstream ss;
	char string_one[] = "hello ";
	char string_two[] = "world";
	char *final_string;
	final_string = cat(string_one,string_two);
	ss << final_string;
	CHECK_EQUAL("hello world", ss.str());
}

TEST(cpp_style, cat_string)
{
	std::string string_one = "hello ";
	std::string string_two= "world";
	std::string final_string = cat_string(string_one,string_two);
	CHECK_EQUAL("hello world",final_string);
}