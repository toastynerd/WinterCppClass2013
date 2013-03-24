//Tyler Morgan
//Mar-16-2013
//UW online C++ 1st quarter
//Assignment 6.1
//BankAccount.cpp

#include "BankAccount.h"
#include <iostream>

//first two constructors needed to be able to create place holders in database.
Account::Account()
	:my_type(savings),
	my_holder_name(""),
	my_account_number(0),
	my_pin_number(0),
	my_balance(0)
{

}

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

int Account::get_account_number()
{
	return my_account_number;
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

std::ostream& operator<<(std::ostream& os, const Account& account)
{
	os << "Account Type: ";
	if(account.my_type == checking)
	{
		os << "checking" << std::endl;
	}
	else if(account.my_type == savings)
	{
		os << "savings" << std::endl;
	}
	os << "Account Number: " << account.my_account_number << std::endl;
	os << "Account Holder: " << account.my_holder_name << std::endl;
	os << "Account Balance: " << account.my_balance << std::endl;
}