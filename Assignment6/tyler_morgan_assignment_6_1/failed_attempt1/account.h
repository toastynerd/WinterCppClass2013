//Tyler Morgan
//Mar-16-2013
//UW online winter c++ course
//Assignment 6.1
//account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "transaction.h"
#include <iostream>

enum AccountType
{
	checking,
	savings
};

class Account
{
public:
	Account(AccountType,int account_number);
	~Account();
	friend void Transaction::process(std::ostream);
private:
	AccountType my_account_type;
	int my_account_number;
	float my_account_balance;
	std::string my_owner_social; //in a real implementation these would probably be salted/hashed except for the last 4 digits
};
#endif ///:~