#include "TestHarness.h"
#include "../Date.h"
#include <string>
#include <sstream>

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested

bool set_day(Date&, int);
bool set_month(Date&, int);
bool set_year(Date&, int);

std::string get_day_of_week(const Date&);
Date get_next_monday(const Date&);

TEST(set_the_day, set_day)
{
	Date date;
	set_day(date, 11);
	CHECK_EQUAL(11, date.day);
}

TEST(set_the_month, set_month)
{
	Date date;
	set_month(date, 10);
	CHECK_EQUAL(10, date.month);
}

TEST(set_the_year, set_year)
{
	Date date;
	set_year(date, 1982);
	CHECK_EQUAL(1982, date.year);
}

TEST(set_day_then_month, set_something_else)
{
	Date date2;
	if(set_day(date2, 31))
	{	
		set_month(date2, 2);
	}
	else
	{
		std::cout <<"could not set date";
	}
	CHECK_EQUAL(28,date2.day);
}

TEST(set_month_then_day, set_day)
{
	Date date;
	set_month(date,2);
	set_day(date, 31);
	CHECK_EQUAL(28,date.day);
}

TEST(leap_year,check_leap_year)
{
	Date date;
	set_year(date, 2000);
	set_month(date, 2);
	set_day(date, 29);
	CHECK_EQUAL(29,date.day);
}

TEST(day_of_the_week, get_day_of_week)
{
	Date date;
	if(set_year(date, 2013)) // set year first or it could potentially miss a leap year
	{
		if(set_month(date, 2))
		{
			if(set_day(date,23))
			{
				CHECK_EQUAL("Saturday", get_day_of_week(date));
			}
		}
	}
}

TEST(find_next_monday, get_next_monday)
{
	Date date;
	Date next_monday;
	std::stringstream ss;
	if(set_year(date, 2013))
	{
		if(set_month(date, 2))
		{
			if(set_day(date, 20))
			{
				next_monday = get_next_monday(date);
			}
		}
	}
	ss << next_monday.month << " " << next_monday.day << " " << next_monday.year;

	CHECK_EQUAL("2 25 2013", ss.str());
}