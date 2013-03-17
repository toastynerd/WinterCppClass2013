//Tyler Morgan
//Mar-16-2013
//UW online c++ class quarter 1
//Assignment 6.1
//transaction.h

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "account.h"
#include "customer_account.h"
#include <iostream>
#include <ctime>

enum TransactionType
{
	balance_check,
	withdraw,
	deposit,
	add_account
};

class Transaction
{
public:
	Transaction(TransactionType,Account&,CustomerAccount&); //balance check
	Transaction(TransactionType,Account&,CustomerAccount&,float amount); //deposit or withdraw
	~Transaction();
	void process(std::ostream);
private:
	TransactionType my_transaction_type;
	Account& my_account;
	CustomerAccount& my_customer_account;
	time_t my_date;
	bool has_been_processed;

	float my_amount;
};

#endif ///:~