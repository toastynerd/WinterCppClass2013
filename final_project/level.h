//Tyler Morgan	
//Apr-13-2013
//UW winter online c++ class 1st qtr
//final projec
//level.h
//Responsible to drawing and creating the current level. Will also keep track of both
//player and zombie objects.
// #include "point.h"
#pragma once
#include <iostream>
#include "player.h"
#include "zombie.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

class Level
{
public:
	Level(int difficulty);
	~Level();
	void draw_level(std::ostream& os);
	virtual void update_level(); // makes it possible to create multiple players or internet based game
	bool level_end();
	bool did_player_win();
	bool is_there_a_wall(int x, int y);
	int get_max_x();
	int get_max_y();
	void set_player_location(int x,int y);
	void set_zombie_location(int zombie_num, int x, int y);
	int get_goal_location_x();
	int get_goal_location_y();

private:
	bool should_be_wall(int x, int y); // check if there should be a wall created at that location, used init
	bool check_for_goal();
	bool check_for_zombies();
	static const int max_x = 64;
	static const int max_y = 24;
	static const int max_zombies = 8;
	static const int max_wall_x = 12;
	static const int max_wall_y = 2;
	static const int wall_chance = 80;
	char my_level_map[max_x][max_y];
	Player player1;
	GoalLocation my_goal;
	Zombie zombies[max_zombies];
	int zombie_count;
	bool level_over;
	bool player_won;

};


