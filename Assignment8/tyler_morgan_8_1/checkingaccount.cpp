//Tyler Morgan
//Mar-29-2013
//UW online c++ class 1st qtr
//Assignment 8.1
//checkingaccount.cpp

#include "bank.h"

CheckingAccount::CheckingAccount(int account_num)
	:Account(account_num),
	my_checks_cashed(0)
{

}

CheckingAccount::~CheckingAccount()
{

}

bool CheckingAccount::cash_check(float amount, int check_num)
{
	if(withdraw(amount))
	{
		for(int x =0;x < my_checks_cashed.size(); x++)
		{
			if(check_num == my_checks_cashed[x])
			{
				//if that check has already been cashed
				deposit(amount); //put the money back into the account.
				return false;
			}
		}
		my_checks_cashed.push_back(check_num);
		return true;
	}
	else
	{
		return false;
	}
}