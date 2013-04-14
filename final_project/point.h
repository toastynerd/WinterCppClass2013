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
// #pragma once
class Point
{
	
public:
	Point(int x, int y);
	~Point();
	int get_x();
	int get_y();
	void set_x(int);
	void set_y(int);
	void inc_x(int);
	void inc_y(int);
private:
	int my_x;
	int my_y;
};

class GoalLocation : public Point
{
public:
	GoalLocation();
	~GoalLocation();
	void set_goal(int x, int y);
	void unset_goal();
	bool check_goal_set();
private:
	bool has_been_set;
};
