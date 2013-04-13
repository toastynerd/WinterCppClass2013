//Tyler Morgan
//April-8-2013
//UW Winter online c++ class 1st qtr
//final project
//game.h
#include "level.h"
#include "player.h"

class Game
{
public:
	Game();
	~Game();
	void main_menu();
	void start_loop();
	void end_game();
private:
	Level* my_current_level;
	int difficulty_level;
	Player player1;
}