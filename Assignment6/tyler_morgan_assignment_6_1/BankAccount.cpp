//Tyler Morgan
//Mar-16-2013
//UW online C++ 1st quarter
//Assignment 6.1
//BankAccount.cpp

#include "BankAccount.h"
#include <iostream>

Account::Account(AccountType type,std::string holder_name,int account_number,int pin_number)
	:my_type(type),
	my_holder_name(holder_name),
	my_account_number(account_number),
	my_pin_number(pin_number),
	my_balance(0.0)
{

}

Account::~Account()
{

}

float Account::get_balance(int pin_number)
{
	if(my_pin_number != pin_number)
	{
		std::cout << "Sorry, incorrect pin!" << std::endl;
		return 0.0;
	}
	else
	{
		return my_balance;
	}
}

void Account::get_balance(std::ostream& os, int pin_number)
{
	if(my_pin_number != pin_number)
	{
		std::cout << "Sorry, incorrect pin!" << std::endl;
		os << "error";
		return;
	}
	else
	{
		os << my_balance;
		return;
	}
}

int Account::get_account_number()
{
	return my_account_number;
}

void Account::get_account_number(std::ostream& os)
{
	os << my_account_number;
	return;
}

std::string Account::get_name()
{
	return my_holder_name;
}

void Account::get_name(std::ostream& os)
{
	os << my_holder_name;
	return;
}

AccountType Account::get_type()
{
	return my_type;
}

void Account::get_type(std::ostream& os)
{
	if(my_type == checking)
	{
		os << "checking";
	}
	else if (my_type == savings)
	{
		os << "savings";
	}
	return;
}

void Account::withdraw(float amount, int pin_number)
{
	if(my_pin_number != pin_number)
	{
		std::cout << "Sorry, incorrect pin!" << std::endl;
		return;
	}
	else
	{
		if(my_balance - amount < 0)
		{
			std::cout << "Not enough funds." << std::endl;
			return;
		}
		else
		{
			my_balance -= amount;
			std::cout << "Withdraw from account #" << my_account_number << " successful, your new balance is: $" << my_balance << std::endl;
			return;
		}
	}
}

void Account::deposit(float amount)
{
	my_balance += amount;
	std::cout << "$" << amount << " successfully deposited to account #" << my_account_number << "." << std::endl;
	return;
}

void Account::deposit(float amount, int pin_number)
{
	my_balance += amount;
		std::cout << "$" << amount << " successfully deposited to account #" << my_account_number << "." << std::endl;
	if(my_pin_number == pin_number) //only output the new balance if the pin is correct
	{
		std::cout << "Your new balance is $" << my_balance << std::endl;
	}
	return;
}

void Account::transfer(float amount, Account& account_to, int pin_number)
{
	std::cout << "Starting transfer--------------------------------------------" << std::endl;
	if(my_pin_number != pin_number)
	{
		std::cout << "Sorry, incorrect pin!" << std::endl;
		return;
	}
	else
	{
		if(my_balance - amount < 0)
		{
			std::cout << "Not enough funds." << std::endl;
		}
		else
		{
			this->withdraw(amount, pin_number);
			account_to.deposit(amount);
			std::cout << "$" << amount << " transferred to account #" << account_to.get_account_number() << std::endl;
		}
		std::cout << "transfer complete--------------------------------------------" << std::endl;
	}
}