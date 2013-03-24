#include "TestHarness.h"
#include "../Histogram.h"
#include <string>
#include <sstream>
#include <iostream>

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
TEST(SOMETHING,SHOMETI)
{
	std::stringstream ss;
	std::string parse_string("123this is a string to parse!");
	Histogram histo;
	histo.add_count("alpha");
	histo.add_count("digit");
	histo.add_count("white space");
	histo.add_count("punctuation");
	parse_add(histo,parse_string);
	ss << histo;
	CHECK_EQUAL(49,ss.str().length());
}