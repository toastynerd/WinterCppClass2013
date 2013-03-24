//Tyler Morgan
//Mar-16-2013
//UW online C++ 1st quarter
//Assignment 6.1
//BankAccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>

enum AccountType
{
	checking,
	savings
};

class Account
{
public:
	Account();
	Account(AccountType type,std::string holder_name,int account_number,int pin_number);
	~Account();
	float get_balance(int pin_number);
	int get_account_number();
	void withdraw(float amount,int pin_number);
	void deposit(float amount);
	void deposit(float amount,int pin_number); //only display the final balance if pin number is entered.
	void transfer(float amount, Account& transfer_to, int pin_number);
	friend std::ostream& operator<<(std::ostream&, const Account&);

private:
	AccountType my_type;
	std::string my_holder_name;
	int my_account_number;
	int my_pin_number; //in a real application this would be salted and hashed
	float my_balance;
};

#endif