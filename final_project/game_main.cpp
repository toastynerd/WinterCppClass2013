//Tyler Morgan	
//Apr-13-2013
//UW winter online c++ class 1st qtr
//final projec
//game_main.cpp
//contains the main loop for the game
#include "level.h"
#include <iostream>

int main()
{
	Level level1(2);
	while(true)
	{
		level1.draw_level(std::cout);
		level1.update_level();
		if(level1.level_end())
		{
			//only had time to implement a simple 1 level game with 2 zombies rather than a 
			//continuing game.
			if(level1.did_player_win())
			{
				std::cout << "Congrats! you won!" << std::endl;
			}
			else
			{
				std::cout << "Ahhhhhh, you got eaten by zombies!" << std::endl;
			}
			break;
		}
	}
}