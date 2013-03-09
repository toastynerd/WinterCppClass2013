#include <cstring>
#include <iostream>
#include <sstream>
#include "TestHarness.h"
//#include "../MonthsDays.h"
// #include "../MonthsDays.h"

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
struct month_days
	{
		char month[15];
		int days;
	};

TEST(months_days_array, array)
{
	
	std::stringstream sstream;
	char months[12][15];
	int days[12];
	int total_days = 0;

	strcpy(months[0],"January");
	days[0] = 31;
	strcpy(months[1],"February");
	days[1] = 28;
	strcpy(months[2],"March");
	days[2] = 31;
	strcpy(months[3],"April");
	days[3] = 30;
	strcpy(months[4],"May");
	days[4] = 31;
	strcpy(months[5],"June");
	days[5] = 30;
	strcpy(months[6],"July");
	days[6] = 31;
	strcpy(months[7],"August");
	days[7] = 31;
	strcpy(months[8],"Semptember");
	days[8] = 30;
	strcpy(months[9],"October");
	days[9] = 31;
	strcpy(months[10],"November");
	days[10] = 30;
	strcpy(months[11],"December");
	days[11] = 31;

	for(int x =0;x<12;x++)
	{
		total_days += days[x];
		sstream << months[x] << ":" << days[x] << std::endl;
	}
	std::cout << sstream.str();
	CHECK_EQUAL(365, total_days);

}

TEST(months_days_struc, month_days)
{
	
	std::stringstream sstream;
	month_days my_month_days[12];
	int total_days = 0;

	strcpy(my_month_days[0].month,"January");
	my_month_days[0].days = 31;
	strcpy(my_month_days[1].month,"February");
	my_month_days[1].days = 28;
	strcpy(my_month_days[2].month,"March");
	my_month_days[2].days = 31;
	strcpy(my_month_days[3].month,"April");
	my_month_days[3].days = 30;
	strcpy(my_month_days[4].month,"May");
	my_month_days[4].days = 31;
	strcpy(my_month_days[5].month,"June");
	my_month_days[5].days = 30;
	strcpy(my_month_days[6].month,"July");
	my_month_days[6].days = 31;
	strcpy(my_month_days[7].month,"August");
	my_month_days[7].days= 31;
	strcpy(my_month_days[8].month,"Semptember");
	my_month_days[8].days = 30;
	strcpy(my_month_days[9].month,"October");
	my_month_days[9].days = 31;
	strcpy(my_month_days[10].month,"November");
	my_month_days[10].days = 30;
	strcpy(my_month_days[11].month,"December");
	my_month_days[11]. days = 31;

	for(int x =0;x<12;x++)
	{
		total_days += my_month_days[x].days;
		sstream << my_month_days[x].month << ":" << my_month_days[x].days << std::endl;
	}
	std::cout << sstream.str();
	CHECK_EQUAL(365, total_days);

}
