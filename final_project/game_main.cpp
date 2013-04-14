//Tyler Morgan	
//Apr-13-2013
//UW winter online c++ class 1st qtr
//final projec
//game_main.cpp
//contains the main loop for the game
#pragma ocne
#include "level.h"
#include <iostream>

int main()
{
	Level level1(1);
	while(true)
	{
		level1.draw_level(std::cout);
		level1.update_level();
		if(level1.level_end())
		{
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