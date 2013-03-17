//Tyler Morgan
//Mar-16-2013
//UW online c++ class quarter 1
//Assignment 6.1
//transaction.cpp

#include "transaction.h"


Transaction::Transaction(TransactionType transaction_type, Account& account,CustomerAccount& customer_account)
	:my_amount(0.0),
	my_customer_account(customer_account),
	my_account(account),
	my_transaction_type(transaction_type),
	has_been_processed(false)
{
	my_date = time(0);
}

Transaction::Transaction(TransactionType type,Account& account, CustomerAccount& customer_account, float amount)
	:my_amount(amount),
	my_customer_account(customer_account),
	my_account(account),
	my_transaction_type(type),
	has_been_processed(false)
{
	my_date = time(0);
}

void Transaction::process(std::ostream os)
{
	if(my_transaction_type == balance_check)
	{
		os << "This account has a balance of $" << my_account->my_account_balance << std::endl;
	}
}