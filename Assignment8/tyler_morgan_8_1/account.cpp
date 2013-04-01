//Tyler Morgan
//Mar-29-2013
//UW online c++ class 1st qtr
//Assignment 8.1
//account.cpp
#include "bank.h"
#include <iostream>

Account::Account(int account_num)
	:my_balance(0),
	my_account_num(account_num)
{

}

Account::~Account()
{

}

bool Account::deposit(float amount)
{
	my_balance += amount;
	return true;
}

bool Account::withdraw(float amount)
{
	if(my_balance - amount > 0)
	{
		my_balance -= amount;
		return true;
	}
	else
	{
		std::cout << "not enough money in accout#" << my_account_num << std::endl;
		return false;
	}
}

bool Account::transfer_to(float amount, Account& account_to)
{
	//having a bool for withdraw prevents the need to check if there's enough money in the account
	if(withdraw(amount))
	{
		if(account_to.deposit(amount))
		{
			return true;
		}
	}	
	else
	{
		return false;
	}
}
float Account::get_balance()
{
	return my_balance;
}