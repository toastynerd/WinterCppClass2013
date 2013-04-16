//Tyler Morgan	
//Apr-13-2013
//UW winter online c++ class 1st qtr
//final projec
//level.cpp
//Responsible to drawing and creating the current level. Will also keep track of both
//player and zombie objects.
#include "level.h"


Level::Level(int difficulty)
	:my_goal(),
	level_over(false),
	player_won(false),
	zombie_count(0)
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
	int temp_rand;
	while(true)
	{
		temp_rand = std::rand() % max_x;
		if(my_level_map[temp_rand][max_y-2] != '*' && my_level_map[temp_rand][max_y-3]!='*')
		{
			break;
		}
	}
	my_goal.set_goal(temp_rand,max_y-2);
	my_level_map[my_goal.get_x()][my_goal.get_y()] = 'X';
	player1.set_location(max_x/2,1);
	my_level_map[player1.get_x()][player1.get_y()] = 'P';
	if(difficulty < max_zombies)
	{
		zombie_count = difficulty;
		for(int x =0; x<zombie_count;x++)
		{
			zombies[x].set_location(std::rand() % max_x, std::rand() % max_x);
			my_level_map[zombies[x].get_x()][zombies[x].get_y()] = 'Z';
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
void Level::update_level()
{
	//check for both win and loss before getting player input
	if(check_for_goal())
	{
		level_over = true;
		player_won = true;
		return;
	}
	for(int i = 0; i <= zombie_count;i++)
	{
		if(zombies[i].get_y() == player1.get_y() && zombies[i].get_x() == player1.get_x())
		{
			//check if player has lost
			level_over = true;
			player_won = false;
			return;
		}
	}

	
	char input;
	std::cout << "which way(w for up,a for left,s for down,d for right,x to quit)? ";
	std::cin >> input;
	std::cout << std::endl;


	if(input == 'a' || input == 'A')
	{
		if(is_there_a_wall(player1.get_x() -1,player1.get_y()))
		{
			if(player1.get_x() - 1 != 0) //allow a player to destroy a wall 
			{
				my_level_map[player1.get_x() -1][player1.get_y()] = ' ';
			}
			else
			{
				return;
			}
		}
		
		else
		{
			my_level_map[player1.get_x()][player1.get_y()] = ' ';
			player1.move(1);
		}
	}

	if(input == 'd' || input == 'D')
	{
		if(is_there_a_wall(player1.get_x() +1,player1.get_y())) //allow player to destroy a wall
		{
			if(player1.get_x() + 2 != max_x)
			{
				my_level_map[player1.get_x() +1][player1.get_y()] = ' ';
			}
			else
			{
				return;
			}
		}
		else
		{
			my_level_map[player1.get_x()][player1.get_y()] = ' ';
			player1.move(2);
		}	
		
	}

if(input == 'w' || input == 'W')
	{
		if(is_there_a_wall(player1.get_x(), player1.get_y() - 1))
		{
			if(player1.get_y() - 1 != 0)
			{
				my_level_map[player1.get_x()][player1.get_y() -1] = ' ';
			}
			else
			{
				return;
			}
		}
		else
		{
			my_level_map[player1.get_x()][player1.get_y()] = ' ';
			player1.move(3);
		}

	}

	if(input == 's' || input == 'S')
	{
		if(is_there_a_wall(player1.get_x(), player1.get_y() + 1))
		{
			if(player1.get_y() + 2 != max_y)
			{
				my_level_map[player1.get_x()][player1.get_y() +1] = ' ';
			}
			else
			{
				return;
			}
		}
		else
		{
			my_level_map[player1.get_x()][player1.get_y()] = ' ';
			player1.move(4);
		}

	}

	if(input == 'x'||input == 'X')
	{
		level_over = true;
	}
	
	my_level_map[player1.get_x()][player1.get_y()] = 'P';
	my_level_map[my_goal.get_x()][my_goal.get_y()] = 'X';
	for(int i = 0;i < zombie_count;i++)
	{
		my_level_map[zombies[i].get_x()][zombies[i].get_y()] = ' ';
		zombies[i].move(player1,this);
		my_level_map[zombies[i].get_x()][zombies[i].get_y()] = 'Z';
		
	}


}

bool Level::level_end()
{
	return level_over;
}

bool Level::did_player_win()
{
	return player_won;
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
	//random number generator debug
	// std::cout << rand_num << std::endl;
	if(rand_num >= wall_chance)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Level::is_there_a_wall(int x, int y)
{
	if(my_level_map[x][y] == '*')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Level::check_for_goal()
{
	if(player1.get_x() == my_goal.get_x() && player1.get_y() == my_goal.get_y())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Level::get_max_x()
{
	return max_x;
}

int Level::get_max_y()
{
	return max_y;
}

void Level::set_player_location(int x,int y)
{
	player1.set_location(x,y);
}

void Level::set_zombie_location(int zombie_num, int x, int y)
{
	zombies[zombie_num].set_location(x,y);
}

int Level::get_goal_location_x()
{
	return my_goal.get_x();
}

int Level::get_goal_location_y()
{
	return my_goal.get_y();
}