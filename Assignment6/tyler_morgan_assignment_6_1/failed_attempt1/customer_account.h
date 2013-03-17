//Tyler Morgan
//Mar-16-2013
//UW online c++ class winter
//Assignment 6.1
//customer_account.h
#ifndef CUSTOMER_ACCCOUNT_H
#define CUSTOMER_ACCCOUNT_H
#include <string>
#include "transaction.h"

class CustomerAccount
{
public:
	CustomerAccount(std::string name,std::string social);
	~CustomerAccount();

private:
	std::string my_name;
	std::string my_social;
};

#endif 
