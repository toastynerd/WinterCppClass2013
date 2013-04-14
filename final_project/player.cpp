//Tyler Morgan	
//Apr-13-2013
//UW winter online c++ class 1st qtr
//final projec
//player.h
//keeps track of player position and score
#include "player.h"

Player::Player()
	:my_location(0,0),
	my_score(0)
{

}

Player::Player(int x, int y)
	:my_location(x,y),
	my_score(0)
{

}

Player::~Player()
{

}

void Player::set_location(int x, int y)
{
	my_location.set_x(x);
	my_location.set_y(y);
}

void Player::move(int direction)
{
	if(direction == 1)
	{
		my_location.inc_x(-1); //left
	}
	if(direction == 2)
	{
		my_location.inc_x(1); //right
	}
	if(direction == 3)
	{
		my_location.inc_y(-1); // up
	}
	if(direction == 4)
	{
		my_location.inc_y(1); //down
	}
}

void Player::change_score(int amount)
{
	my_score += amount;
}

int Player::get_x()
{
	return my_location.get_x();
}

int Player::get_y()
{
	return my_location.get_y();
}

int Player::get_score()
{
	return my_score;
}