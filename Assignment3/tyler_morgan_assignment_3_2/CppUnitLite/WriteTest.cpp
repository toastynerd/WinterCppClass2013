#include "TestHarness.h"
#include "../write.h"
#include <string>
#include <sstream>

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
void write(std::ostream&,int);
void write(std::ostream&,float);
void write(std::ostream&,std::string);
TEST(stream_pointer_int, write_int)
{
	std::stringstream ss;
	int my_int = 12;
	write(ss, my_int);
	CHECK_EQUAL("12",ss.str());
}

TEST(stream_pointer_float, write_float)
{
	std::stringstream ss;
	float my_float = 1.2;
	write(ss, my_float);
	CHECK_EQUAL("1.2",ss.str());
}

TEST(stream_pointer_string, write_string)
{
	std::stringstream ss;
	std::string my_string = "12";
	write(ss, my_string);
	CHECK_EQUAL("12",ss.str());
}
