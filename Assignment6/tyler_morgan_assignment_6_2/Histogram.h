//Tyler Morgan
//Mar-17-2013
//UW online C++ class qtr 1
//Assignment 6.2
//Histogram.h
#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#include <iostream>
#include <string>


class Histogram
{
public:
	Histogram();
	~Histogram();
	friend void parse_add(Histogram&, std::string);
	int get_alpha_count();
	void get_alpha_count(std::ostream&);
	int get_digit_count();
	void get_digit_count(std::ostream&);
	int get_whitespace_count();
	void get_whitespace_count(std::ostream&);
	int get_punct_count();
	void get_punct_count(std::ostream&);
	void show_histogram(std::ostream&);
private:
	int my_alpha_count;
	int my_digit_count;
	int my_whitespace_count;
	int my_punct_count;
};
void parse_add(Histogram&, std::string);

#endif