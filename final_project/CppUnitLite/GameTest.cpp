#include "TestHarness.h"
#include "../level.h"
#include "../point.h"
#include <sstream>
#include <iostream>


// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
TEST(point_fucntions, Point)
{
	Point point1(0,0);
	point1.set_y(4);
	point1.inc_x(5);
	point1.inc_y(-1);
	CHECK_EQUAL(3, point1.get_y());
	CHECK_EQUAL(5, point1.get_x());
}


TEST(level_draw, Level)
{
	std::stringstream ss;
	Level level1(0);
	level1.draw_level(ss);
	CHECK_EQUAL('*',ss.str().at(0)); //check for a * at location 0,0
	CHECK_EQUAL('*', ss.str().at(8192)); // check for a * at location 128,64
	//I won't check for a ' ' because the walls in the interior of the level 
	// will be generated randomly
}

TEST(goal_location_methods, GoalLocaiton)
{
	GoalLocation goal;
	CHECK_EQUAL(false, goal.check_goal_set());
	goal.set_goal(10,10);
	CHECK_EQUAL(true, goal.check_goal_set());
	goal.set_goal(20,20);
	CHECK_EQUAL(10,goal.get_x());
	CHECK_EQUAL(10,goal.get_y());
	goal.unset_goal();
	goal.set_goal(20,20);
	CHECK_EQUAL(20, goal.get_x());
	CHECK_EQUAL(20, goal.get_y());

}

TEST(level_generation2, Level)
{
	std::stringstream ss;
	Level level1(1);
	level1.draw_level(ss);
	std::cout << ss.str();

}