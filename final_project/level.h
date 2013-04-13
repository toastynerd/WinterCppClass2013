//Tyler Morgan	
//Apr-13-2013
//UW winter online c++ class 1st qtr
//final projec
//level.h
//Responsible to drawing and creating the current level. Will also keep track of both
//player and zombie objects.
// #include "point.h"
#include <iostream>

class Level
{
public:
	Level(int difficulty);
	~Level();
	void draw_level(std::ostream& os);
	void udate_leve();

private:
	bool should_be_wall(int x, int y); // check if there should be a wall created at that location, used init
	// GoalLocation my_goal;
	static const int max_x = 64;
	static const int max_y = 32;
	static const int max_zombies = 8;
	static const int max_wall_x = 15;
	static const int max_wall_y = 2;
	static const int wall_chance = 80;
	char my_level_map[max_x][max_y];
};
