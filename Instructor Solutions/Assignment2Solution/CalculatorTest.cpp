#include "TestHarness.h"

#include "Calculator.h"

#include <sstream>

TEST(Addition, Calculator)
{
    std::stringstream ss("pi + 5");
    std::string results = Calculator(ss);
    CHECK_EQUAL("8.14159", results);
}

TEST(Subtraction, Calculator)
{
    std::stringstream ss("99.43 - 55");
    std::string results = Calculator(ss);
    CHECK_EQUAL("44.43", results);
}

TEST(Multiplication, Calculator)
{
    std::stringstream ss("4.5 * 6.6");
    std::string results = Calculator(ss);
    CHECK_EQUAL("29.7", results);
}

TEST(Division, Calculator)
{
    std::stringstream ss("15 / 3");
    std::string results = Calculator(ss);
    CHECK_EQUAL("5", results);
}

TEST(MultipleEquations, Calculator)
{
    std::stringstream ss;
    ss << "15 / 3";
    ss << std::endl;
    ss << "4 * 4";
    std::string results = Calculator(ss);

    std::stringstream actual;
    actual << "5" << std::endl << "16";

    CHECK_EQUAL(actual.str(), results);
}