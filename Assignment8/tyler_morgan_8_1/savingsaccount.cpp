//Tyler Morgan
//Mar-29-2013
//UW online c++ class 1st qtr
//Assignment 8.1
//savingsaccount.cpp

#include "bank.h"

SavingsAccount::SavingsAccount(int account_num,float interest_rate)
	:Accout(account_num),
	my_interest(interest_rate)
{

}

SavingsAccount::~SavingsAccount()
{

}

void SavingsAccount::change_interest_rate(float new_rate)
{
	my_interest = new_rate;
}

void SavingsAccount::add_interest()
{
	my_balance += my_balance*my_interest;
}