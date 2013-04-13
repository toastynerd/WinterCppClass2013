//Tyler Morgan	
//Apr-13-2013
//UW winter online c++ class 1st qtr
//final projec
//level.cpp
//Responsible to drawing and creating the current level. Will also keep track of both
//player and zombie objects.
#include "level.h"
#include <cstdlib>
#include <ctime>

Level::Level(int difficulty)
{
	std::srand(std::time(0)); //get a random seed
	for(int y = 0; y < max_y; y++)
	{
		for(int x = 0; x < max_x; x++)
		{
			if(y == 0 | y == max_y-1)
			{
				my_level_map[x][y] = '*';
			}
			else if(x == 0 | x == max_x-1)
			{
				my_level_map[x][y] = '*';
			}
			else
			{
				if(should_be_wall(x,y))
				{
					my_level_map[x][y] = '*';
				}
				else
				{
					my_level_map[x][y] = ' ';
				}
			}
		}
	}
}
Level::~Level()
{

}

void Level::draw_level(std::ostream& os)
{
	for(int y = 0; y < max_y; y++)
	{
		for(int x = 0; x < max_x; x++)
		{
			os << my_level_map[x][y];
		}
		os << std::endl;
	}
}

bool Level::should_be_wall(int x, int y)
{
	//This is method to check if a certain location should be a wall '*'
	//this is going to get messy
	int total_wall_x = 0; //check for a max sized wall in x direction
	int total_wall_y = 0; //check for a max sized wall in y direction
	for(int check_x = 0; x + check_x < max_x; check_x++)
	{
		if(my_level_map[x+check_x][y]=='*')
		{
			total_wall_x++;
		}
	}
	for(int check_x = 0; x + check_x > 0; check_x--)
	{
		if(my_level_map[x+check_x][y]=='*')
		{
			total_wall_x++;
		}
	}
	for(int check_y = 0; y + check_y < max_y; check_y++)
	{
		if(my_level_map[x][y+check_y]=='*')
		{
			total_wall_y++;
		}
	}
	for(int check_y = 0; y + check_y > 0; check_y--)
	{
		if(my_level_map[x][y+check_y]=='*')
		{
			total_wall_y++;
		}
	}
	if(total_wall_y > max_wall_y || total_wall_x > max_wall_x) //check to see if a max wall size has been reached
	{
		return false;
	}
	
	int rand_num = std::rand() % 100;
	
	
	if(my_level_map[x+1][y] == '*' && my_level_map[x+2][y] == '*')
	{
		//greater chance to continue a wall
		rand_num += 40;
	}
	if(my_level_map[x-1][y] == '*' && my_level_map[x-2][y] == '*')
	{
		//greater chance to continue a wall
		rand_num += 40;
	}

	if(my_level_map[x+1][y] == '*')
	{
		//greater chance to continue a wall
		rand_num += 60;
	}
	if(my_level_map[x-1][y] == '*')
	{
		//greater chance to continue a wall
		rand_num += 60;
	}
	std::cout << rand_num << std::endl;
	if(rand_num >= wall_chance)
	{
		return true;
	}
	else
	{
		return false;
	}

}