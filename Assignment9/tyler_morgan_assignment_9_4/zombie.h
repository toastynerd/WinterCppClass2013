//Tyler Morgan
//April-8-2013
//UW Winter online c++ class 1st qtr
//final project
//zombie.h
#include "point.h"

class Zombie
{
public:
	Zombie(Point);
	~Zimbie();
	void move_toward_player(Player&);
	Point get_location();
private:
	Point my_locaiton;
};
