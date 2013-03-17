#include "TestHarness.h"
#include "../Histogram.h"
#include <string>
#include <sstream>

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
TEST(HistogramInit, Histogram)
{
	Histogram histo;
	CHECK_EQUAL(0,histo.get_alpha_count())
}

TEST(HistogramParse, Histogram)
{
	Histogram histo;
	std::string parse_string = "Hello, and welcome999!";

	parse_add(histo, parse_string);

	CHECK_EQUAL(3,histo.get_digit_count());
}

TEST(HistogramOutput, Histogram)
{
	std::stringstream ss;
	Histogram histo;
	std::string parse_string = "Hello 1234, how are you? That's cool.";

	parse_add(histo, parse_string);

	histo.get_punct_count(ss);
	CHECK_EQUAL("4", ss.str());
}