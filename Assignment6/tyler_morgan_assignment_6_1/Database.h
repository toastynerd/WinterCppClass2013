//Tyler Morgan
//mar-17-2013
//UW online c++ course qt 1
//assignment 6.1
//Database place holder
//Database.h
#include "BankAccount.h"

class Database
{
public:
	Database();
	~Database();
	bool write_to_db(const Account& account);
	int get_next_account_num();
	Account& get_account_by_num(int);
private:
	int my_db_size;
	Account* my_account_db;
};