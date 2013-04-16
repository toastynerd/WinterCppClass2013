//Tyler Morgan	
//Apr-13-2013
//UW winter online c++ class 1st qtr
//final projec
//zombie.cpp
//contains the logic and location information for a zombie

// #include "zombie.h"
#include "level.h"

Zombie::Zombie()
	:my_location(0,0)
{

}

Zombie::Zombie(int x, int y)
	:my_location(x,y)
{

}

Zombie::~Zombie()
{

}
void Zombie::set_location(int x, int y)
{
	my_location.set_x(x);
	my_location.set_y(y);
}

void Zombie::move(Player& player, Level * level)
{
	//fixes a wierd bug where zombie would 2x what it should be
	if(my_location.get_x() > level->get_max_x())
	{
		my_location.set_x(my_location.get_x() - level->get_max_x());
	}
	if(my_location.get_y() > level->get_max_y())
	{
		my_location.set_y(my_location.get_y() - level->get_max_y());
	}

	if((distance_to_player_x(player) > distance_to_player_y(player) || distance_to_player_y(player) == 0) && distance_to_player_x(player) != 0 )
	{
		if(player.get_x() < my_location.get_x() && !level->is_there_a_wall(my_location.get_x() - 1, my_location.get_y()))
		{
			my_location.inc_x(-1);
			return;
		}
		if(player.get_x() > my_location.get_x() && !level->is_there_a_wall(my_location.get_x() + 1,my_location.get_y()))
		{
			my_location.inc_x(1);
			return;
		}
		
	}

	
	if(player.get_y() < my_location.get_y() && !level->is_there_a_wall(my_location.get_x(), my_location.get_y() - 1))
	{
		//std::cout << my_location.get_y() << "b" << player.get_y() << std::endl;
		my_location.inc_y(-1);
		return;
	}
	if(player.get_y() > my_location.get_y()  && !level->is_there_a_wall(my_location.get_x(), my_location.get_y() + 1))
	{
		// std::cout << my_location.get_y() << "a" << player.get_y() << std::endl;
		my_location.inc_y(1);
		return;
	}
	//if the zombie has no moves will "jump" up to 2 x and 2 y
	int rand_x = rand() % 4 - 2; 
	int rand_y = rand() % 4 - 2;
	if(my_location.get_y() + rand_y > 0 && my_location.get_y() + rand_y < level->get_max_y())
	{
		my_location.inc_y(rand_y);
	}
	if(my_location.get_x() + rand_x > 0 && my_location.get_x() + rand_x < level->get_max_x())
	{
		my_location.inc_x(rand_x);
	}
	return;
	
	
}

int Zombie::get_x()
{
	return my_location.get_x();
}

int Zombie::get_y()
{
	return my_location.get_y();
}

int Zombie::distance_to_player_x(Player& player)
{
	if(my_location.get_x() > player.get_x())
	{
		return my_location.get_x() - player.get_x();
	}
	else
	{
		return player.get_x() - my_location.get_x();
	}
}

int Zombie::distance_to_player_y(Player& player)
{
	if(my_location.get_y() > player.get_y())
	{
		return my_location.get_y() - player.get_y();
	}
	else
	{
		return player.get_y() - my_location.get_y();
	}
}