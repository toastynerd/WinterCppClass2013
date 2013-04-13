//Tyler Morgan
//April-8-2013
//UW Winter online c++ class 1st qtr
//final project
//level.h
#include "player.h"
#include "zombie.h"
#include <vector>

class Level
{
public:
	Level(int difficulty, Player&);
	~Level();
	void draw_level();
	void update_level(); // code for moving zombies/players
private:
	const int max_x = 128;
	const int max_y = 64;
	int my_level_map[max_y][max_x];
	vector<Zombie> my_zombies;
	Player* my_player;
}