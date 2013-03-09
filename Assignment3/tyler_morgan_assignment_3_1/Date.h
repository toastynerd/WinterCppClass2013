//Tyler Morgan
//12-23-2013
//UW online C++ course
//asignment 3.1
#include <iostream>
#include <string>


const int days_per_month[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // add a zero to start at month 1
const std::string days_of_the_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

struct Date{
	//set year first when using included set_ functions or it could miss a leap year
	int day;
	int month;
	int year;
};

bool check_leap_year(int year)
{
	if(year > 100000)  //not a very good check to see if year has been set yet
	{
		return false;
	}
	if(year %4 == 0)
	{
		if(year % 100 == 0)
		{
			if(year % 400 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool set_day(Date& date,int day_to_set)
{
	
	if(day_to_set <= 31 && day_to_set > 0)
	{
		if(date.month > 0 && date.month <= 12)
		{	
			if(day_to_set > days_per_month[date.month])
			{
				if(date.month == 2) // make sure the year is not a leap year
				{
					if(check_leap_year(date.year))
					{
						date.day = 29;
						return true;
					}
					else
					{
						date.day = 28;
						return true;
					}
				}
				else
				{	
					date.day = days_per_month[date.month];
					return true;
				}				
			}
			else
			{
				date.day = day_to_set;
				return true;
			}
		}
		else
		{	
			date.day = day_to_set;
			return true;
		}
	}
	else
	{
		std::cout << "day should be between 1 and 31 but was: " << day_to_set << std::endl;
		return false;
	} 
}

bool set_month(Date& date, int month_to_set)
{
	if(month_to_set <= 12 && month_to_set > 0)
	{	
		
		if(date.day > days_per_month[month_to_set] && date.day <= 31)
		{
			if(month_to_set == 2)
			{
				if(check_leap_year(date.year))
				{
					date.day = 29;
					date.month = month_to_set;
					return true;
				}
				else
				{
					date.day = 28;
					date.month = month_to_set;
					return true;
				}
			
			}
			else
			{
				date.day = days_per_month[month_to_set];
				date.month = month_to_set;
				return true;
			}
		}
		else
		{
			
			date.month = month_to_set;
			return true;
		}
	}
	else if(month_to_set > 12)
	{
		month_to_set = month_to_set % 12;
		set_month(date,month_to_set); // call recursively to do max days of month check
		std::cout << "warning: month was greater than 12, set to: " << month_to_set << std::endl;
		return true;
	}
	else
	{
		std::cout << "invalid month" << std::endl;
		return false;
	}
}

bool set_year(Date& date, int year_to_set)
{
	if(year_to_set > 0)
	{
		date.year = year_to_set;
		return true;
	}
	else
	{
		std::cout << "Sorry we only deal with the Common Era " << std::endl;
		return false;
	}
}


void inc_year(Date& date)
{
	date.year += 1;
	return;
}

void inc_month(Date& date)
{
	if(date.month + 1 > 12)
	{
		inc_year(date);
		set_month(date, date.month +1);
		return;
	}
	else
	{
		set_month(date, date.month +1);
		return;
	}
}

void inc_day(Date& date)
{
	if(date.day + 1 > days_per_month[date.month])
	{
		
		date.day = (date.day + 1 ) - days_per_month[date.month];
		inc_month(date);
		return;
	}
	else
	{
		date.day += 1;
		return;
	}
}

std::string get_day_of_week(const Date& date)
{
	int a = (14-date.month) / 12;
	int y = date.year - a;
	int m = date.month + 12*a-2;
	int d = ((date.day + y +(y/4)) - (y/100) + (y/400) + (31*m)/12) % 7;
	return days_of_the_week[d];
}

Date get_next_monday(const Date& date)
{
	Date next_monday;
	set_day(next_monday, date.day);
	set_month(next_monday, date.month);
	set_year(next_monday, date.year);
	for(int x =0; x <7; x++)
	{
		inc_day(next_monday);
		if(get_day_of_week(next_monday) == "Monday")
		{
			return next_monday;
		}
	}
}