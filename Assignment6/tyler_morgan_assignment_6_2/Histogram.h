//Tyler Morgan
//Mar-17-2013
//UW online C++ class qtr 1
//Assignment 6.2
//Histogram.h
#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#include <iostream>
#include <string>
#include <vector>

class Histogram
{
public:
	Histogram();
	~Histogram();
	void add_count(std::string);
	friend bool parse_add(Histogram&, std::string);
	friend std::ostream& operator<<(std::ostream&,const Histogram&);
private:
	std::vector<std::string> my_count_name;
	std::vector<int> my_count;
};

#endif