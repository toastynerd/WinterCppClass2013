//Tyler Morgan
//mar-17-2013
//UW online c++ course qt 1
//assignment 6.1
//Database place holder
//Database.cpp
#include "Database.h"

Database::Database()
	:my_db_size(0)
{

	my_account_db = new Account[100];
}

Database::~Database()
{
	delete[] my_account_db;
}

bool Database::write_to_db(const Account& account)
{
	my_account_db[my_db_size] = account;
	my_db_size++;
}

int Database::get_next_account_num()
{
	return my_db_size;
}

Account& Database::get_account_by_num(int num)
{
	return my_account_db[num];
}