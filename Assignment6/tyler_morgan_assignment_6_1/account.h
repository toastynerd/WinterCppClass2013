//Tyler Morgan
//Mar-16-2013
//UW online winter c++ course
//Assignment 6
//account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

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
	float get_balance();
	//friend void Transaction::withdraw(Account*,float);
	//friend void Transaction::depost(Account*,float);

private:
	AccountType my_account_type;
	int my_account_number;
	float my_account_balance;
};
#endif // ACCOUNT_H ///:~