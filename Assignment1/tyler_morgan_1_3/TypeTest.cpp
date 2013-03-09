//Tyler Morgan
//Feb-9-2013
//C++ programming: introduction
//assignment 1.3
#include "TestHarness.h"
#include <iostream>
#include <string>
#include <sstream>

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested

// test for read/write of a double
TEST(writeDouble, double)
{
	double write_double;
	std::stringstream my_sstream("1.5");
	my_sstream >> write_double;
	CHECK_DOUBLES_EQUAL(1.5,write_double,0.001);

}
TEST(readDouble, double)
{
	double read_double;
	std::stringstream my_sstream;
	read_double = 1.5;
	my_sstream << read_double;
	CHECK_EQUAL("1.5",my_sstream.str());
}

// test for read/write of a int
TEST(writeInt, int)
{
	int write_int;
	std::stringstream my_sstream("42");
	my_sstream >> write_int;
	CHECK_EQUAL(42,write_int);
}
TEST(readInt, int)
{
	int read_int;
	read_int = 42;
	std::stringstream my_sstream("");
	my_sstream << read_int;
	CHECK_EQUAL("42",my_sstream.str());
}

//tests for read/write of a char type
TEST(writeChar, char)
{
	char write_char;
	std::stringstream my_sstream("f");
	my_sstream >> write_char;
	CHECK_EQUAL('f',write_char);

}
TEST(readChar, char)
{
	char read_char;
	std::stringstream my_sstream;
	read_char = 'c';
	my_sstream << read_char;
	CHECK_EQUAL("c",my_sstream.str());
}

//test for a bad stringstream conversion

TEST(badStringstream, stringstream)
{
	std::stringstream my_sstream("hello");
	int bad_int;
	my_sstream >> bad_int;
	CHECK_EQUAL("hello", bad_int);

}