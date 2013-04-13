//Tyler Morgan
//April-8-2013
//UW Winter online c++ class 1st qtr
//final project
//player.h
#include "point.h"

class Player
{
public:
	Player(Point location);
	~Player();
	void move(int direction);
	void change_score(int amount);
	Point get_location();
private:
	Point my_location;
	int score;

}