//Tyler Morgan	
//Apr-13-2013
//UW winter online c++ class 1st qtr
//final projec
//player.h
//keeps track of player position and score
// #pragma once
#include "point.h"

class Player
{

public:
	Player();
	Player(int x, int y);
	~Player();
	void set_location(int x, int y);
	void move(int direction);
	void change_score(int amount);
	int get_x();
	int get_y();
	int get_score();
private:
	Point my_location;
	int my_score;
};