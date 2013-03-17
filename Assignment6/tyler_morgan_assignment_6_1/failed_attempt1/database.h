//Tyler Morgan
//Mar-16-2013
//UW online c++ class
//assignment 6.1
//database placeholder
//database.h
#ifndef DATABASE_H
#define DATABASE_H
#include "bank.h"

class Database
{
public:
	void upsert(Account&);
	void upsert(CustomerAccount&);
	void upsert(Transaction&);

	//if this were a real database these would have a better way of searching for the various classes 
	//but I'm not going to do anything with them for this project since they would not return any documents
	//so these are just place holders
	void find(Account&);
	void find(CustomerAccount&);
	void find(Transaction&);

};

#endif