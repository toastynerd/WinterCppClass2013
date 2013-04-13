//Tyler Morgan
//April-8-2013
//UW Winter online c++ class 1st qtr
//final project
//point.h
//Keeps track of point locations for players, zombies, etc
//The GoalLoation keeps track of the end point of the game and
//also keeps track of whether or not it has been initialzed
//that way, there's an easy to check to make sure there's only
//1 goal in the level.
#include "point.h"
#include <iostream>

Point::Point(int x, int y)
	:my_x(x), my_y(y)
{

}
Point::~Point()
{

}

int Point::get_x()
{
	return my_x;
}

int Point::get_y()
{
	return my_y;
}

void Point::set_x(int x)
{
	my_x = x;
	return;
}

void Point::set_y(int y)
{
	my_y = y;
	return;
}

void Point::inc_x(int x)
{
	my_x += x;
	return;
}

void Point::inc_y(int y)
{
	my_y += y;
	return;
}

GoalLocation::GoalLocation()
	:Point(0,0),
	 has_been_set(false)
{

}

GoalLocation::~GoalLocation()
{

}

void GoalLocation::set_goal(int x, int y)
{
	if(has_been_set == true)
	{
		std::cout << "goal location is current set, can't set again" << std::endl;
		return;
	}
	set_x(x);
	set_y(y);
	has_been_set = true;
	return;
}

void GoalLocation::unset_goal()
{
	if(has_been_set == false)
	{
		std::cout << "goal is not set yet" << std::endl;
		return;
	}
	set_x(-1);
	set_y(-1);
	has_been_set = false;
}

bool GoalLocation::check_goal_set()
{
	return has_been_set;
}