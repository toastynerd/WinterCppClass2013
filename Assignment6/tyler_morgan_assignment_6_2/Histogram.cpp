//Tyler Morgan
//Mar-17-2013
//UW online C++ class qtr 1
//Assignment 6.2
//Histogram.cpp
#include "Histogram.h"

Histogram::Histogram()
	:my_count(0),
	my_count_name(0)
{

}

Histogram::~Histogram()
{

}

void Histogram::add_count(std::string count_name)
{
	my_count_name.push_back(count_name);
	my_count.push_back(0);
}

bool parse_add(Histogram& histo,std::string parse_string)
{
	for(int x = 0;x <= parse_string.length(); x++)
	{
		if(isalpha(parse_string[x]))
		{
			if(histo.my_count_name[0]=="alpha")
			{
				histo.my_count[0]++;
			}			
		}
		if(isdigit(parse_string[x]))
		{
			if(histo.my_count_name[1]=="digit")
			{
				histo.my_count[1]++;
			}
			
		}
		if(isspace(parse_string[x]))
		{
			if(histo.my_count_name[2]=="white space")
			{
				histo.my_count[2]++;
			}
		}
		if(ispunct(parse_string[x]))
		{
			if(histo.my_count_name[3] == "punctuation")
			{
				histo.my_count[3]++;
			}
		}
	}
	return true;

}

std::ostream& operator<<(std::ostream& os, const Histogram& histo)
{
	for(int x =0;x < histo.my_count_name.size();x++)
	{
		os << histo.my_count_name[x] << ": " << histo.my_count[x] << std::endl;
	}
}