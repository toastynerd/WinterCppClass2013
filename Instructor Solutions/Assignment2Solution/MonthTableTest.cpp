
#include "TestHarness.h"

namespace
{
    const char* months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
}

TEST(TwoArrays, MonthTable)
{
    CHECK_EQUAL("January", months[0]);
    CHECK_EQUAL(31, daysPerMonth[0]);
    CHECK_EQUAL("February", months[1]);
    CHECK_EQUAL(28, daysPerMonth[1]);
    CHECK_EQUAL("March", months[2]);
    CHECK_EQUAL(31, daysPerMonth[2]);
    CHECK_EQUAL("April", months[3]);
    CHECK_EQUAL(30, daysPerMonth[3]);
    CHECK_EQUAL("May", months[4]);
    CHECK_EQUAL(31, daysPerMonth[4]);
    CHECK_EQUAL("June", months[5]);
    CHECK_EQUAL(30, daysPerMonth[5]);
    CHECK_EQUAL("July", months[6]);
    CHECK_EQUAL(31, daysPerMonth[6]);
    CHECK_EQUAL("August", months[7]);
    CHECK_EQUAL(31, daysPerMonth[7]);
    CHECK_EQUAL("September", months[8]);
    CHECK_EQUAL(30, daysPerMonth[8]);
    CHECK_EQUAL("October", months[9]);
    CHECK_EQUAL(31, daysPerMonth[9]);
    CHECK_EQUAL("November", months[10]);
    CHECK_EQUAL(30, daysPerMonth[10]);
    CHECK_EQUAL("December", months[11]);
    CHECK_EQUAL(31, daysPerMonth[11]);
}

#define NELEMENTS(array) (sizeof(array) / sizeof(array[0]))

std::string monthsToString()
{
    int size = NELEMENTS(months);

    std::stringstream ss;
    for (int i = 0; i < size; ++i)
    {
        ss << months[i] << " " << daysPerMonth[i];
        if (i != size -1)
        {
            ss << " ";
        }
    }

    return ss.str();
}

std::string getExpectedMonthsDayString()
{
    return std::string("January 31 February 28 March 31 April 30 May 31 June 30 July 31 August 31 September 30 October 31 November 30 December 31");
}

TEST(TwoArraysToString, MonthTable)
{
    CHECK_EQUAL(getExpectedMonthsDayString(), monthsToString());
}

struct Month
{
    std::string monthName;
    int days;
};

TEST(Struct, MonthTable)
{
    const Month months[] =
    {
        { "January", 31 },
        { "February", 28 },
        { "March", 31 },
        { "April", 30 },
        { "May", 31 },
        { "June", 30 },
        { "July", 31 },
        { "August", 31 },
        { "September", 30 },
        { "October", 31 },
        { "November", 30 },
        { "December", 31 },
    };

    CHECK_EQUAL("January", months[0].monthName);
    CHECK_EQUAL(31, months[0].days);
    CHECK_EQUAL("February", months[1].monthName);
    CHECK_EQUAL(28, months[1].days);
    CHECK_EQUAL("March", months[2].monthName);
    CHECK_EQUAL(31, months[2].days);
    CHECK_EQUAL("April", months[3].monthName);
    CHECK_EQUAL(30, months[3].days);
    CHECK_EQUAL("May", months[4].monthName);
    CHECK_EQUAL(31, months[4].days);
    CHECK_EQUAL("June", months[5].monthName);
    CHECK_EQUAL(30, months[5].days);
    CHECK_EQUAL("July", months[6].monthName);
    CHECK_EQUAL(31, months[6].days);
    CHECK_EQUAL("August", months[7].monthName);
    CHECK_EQUAL(31, months[7].days);
    CHECK_EQUAL("September", months[8].monthName);
    CHECK_EQUAL(30, months[8].days);
    CHECK_EQUAL("October", months[9].monthName);
    CHECK_EQUAL(31, months[9].days);
    CHECK_EQUAL("November", months[10].monthName);
    CHECK_EQUAL(30, months[10].days);
    CHECK_EQUAL("December", months[11].monthName);
    CHECK_EQUAL(31, months[11].days);
}

std::string structMonthsToString()
{
    const Month months[] =
    {
        { "January", 31 },
        { "February", 28 },
        { "March", 31 },
        { "April", 30 },
        { "May", 31 },
        { "June", 30 },
        { "July", 31 },
        { "August", 31 },
        { "September", 30 },
        { "October", 31 },
        { "November", 30 },
        { "December", 31 },
    };

    int size = NELEMENTS(months);

    std::stringstream ss;
    for (int i = 0; i < size; ++i)
    {
        ss << months[i].monthName << " " << months[i].days;
        if (i != size -1)
        {
            ss << " ";
        }
    }

    return ss.str();
}

TEST(StuctToString, MonthTable)
{
    CHECK_EQUAL(getExpectedMonthsDayString(), structMonthsToString());
}