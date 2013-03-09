//Tyler Morgan
//feb-16-2013
//UW c++ online course
//Assignment 2.3
#include "TestHarness.h"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested

TEST(stringstream_unsorted,stringstream)
{
	std::stringstream ss("Hello World Quit");
	std::string buffer;
	std::stringstream ss2;


	while(buffer != "Quit")
	{
		ss >> buffer;
		if(buffer != "Quit") // prevent the new string stream from including "Quit"
		{	
			ss2 << buffer << " ";
		}
	}
	
	CHECK_EQUAL("Hello World ", ss2.str());
}

TEST(stringstream_sorted,stringstream)
{
	std::stringstream ss("beta alpha magic gamma Quit");
	std::stringstream ss2;
	std::string buffer;
	std::vector<std::string> words;
	int word_count;
	while(buffer != "Quit")
	{
		ss >> buffer;
		if(buffer != "Quit")
		{
			words.push_back(buffer);
			word_count++;
		}
	}
	std::sort(words.begin(),words.end());
	for(int x =0;x<words.size();x++)
	{
		ss2 << words[x] << " ";
	}
	CHECK_EQUAL("alpha beta gamma magic ",ss2.str());
}