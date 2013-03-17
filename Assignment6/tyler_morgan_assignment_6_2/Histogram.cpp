//Tyler Morgan
//Mar-17-2013
//UW online C++ class qtr 1
//Assignment 6.2
//Histogram.cpp
#include "Histogram.h"

void parse_add(Histogram& histo,std::string parse_string)
{
	for(int x = 0;x <= parse_string.length(); x++)
	{
		if(isalpha(parse_string[x]))
		{
			histo.my_alpha_count++;
		}
		if(isdigit(parse_string[x]))
		{
			histo.my_digit_count++;
		}
		if(isspace(parse_string[x]))
		{
			histo.my_whitespace_count++;
		}
		if(ispunct(parse_string[x]))
		{
			histo.my_punct_count++;
		}
	}

}

Histogram::Histogram()
	:my_alpha_count(0),
	my_digit_count(0),
	my_whitespace_count(0),
	my_punct_count(0)
{

}

Histogram::~Histogram()
{

}

int Histogram::get_alpha_count()
{
	return my_alpha_count;
}

void Histogram::get_alpha_count(std::ostream& os)
{
	os << my_alpha_count;
	return;
}

int Histogram::get_digit_count()
{
	return my_digit_count;
}

void Histogram::get_digit_count(std::ostream& os)
{
	os << my_digit_count;
	return;
}

int Histogram::get_whitespace_count()
{
	return my_whitespace_count;
}

void Histogram::get_whitespace_count(std::ostream& os)
{
	os << my_whitespace_count;
	return;
}

int Histogram::get_punct_count()
{
	return my_punct_count;
}

void Histogram::get_punct_count(std::ostream& os)
{
	os << my_punct_count;
	return;
}

void Histogram::show_histogram(std::ostream& os)
{
	os << "alphas: " << my_alpha_count << std::endl;
	os << "digits: " << my_digit_count << std::endl;
	os << "white space: " << my_digit_count << std::endl;
	os << "punctuation: " << my_punct_count << std::endl;
}