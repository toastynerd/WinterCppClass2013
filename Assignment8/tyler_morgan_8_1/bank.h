//Tyler Morgan
//Mar-29-2013
//UW online c++ class 1st qtr
//Assignment 8.1
//bank.h
#include <vector>

class Account
{
public:
	Account(int);
	~Account();
	bool deposit(float);
	bool withdraw(float);
	bool transfer_to(float amount, Account& account_to);
	float get_balance();

protected:
	float my_balance;
private:
	int my_account_num;
};

class CheckingAccount : public Account
{
public:
	CheckingAccount(int);
	~CheckingAccount();
	bool cash_check(float amount, int check_num);
private:
	std::vector<int> my_checks_cashed;
};

class SavingsAccount : public Account
{
public:
	SavingsAccount(int,float);
	~SavingsAccount();
	void change_interest_rate(float);
	void add_interest();
private:
	float my_interest;
};