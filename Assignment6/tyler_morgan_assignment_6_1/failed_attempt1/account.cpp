//Tyler Morgan
//Mar-16-2013
//UW online winter c++ course
//Assignment 6.1
//account.cpp
#include "account.h"

Account::Account(AccountType type,int account_number)
	:my_account_balance(0)
{
	my_account_number = account_number;
	my_account_type = type;
}

Account::~Account()
{

}

