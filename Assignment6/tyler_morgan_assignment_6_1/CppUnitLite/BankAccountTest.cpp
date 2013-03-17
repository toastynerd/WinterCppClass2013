#include "TestHarness.h"
#include "../BankAccount.h"
#include "../Database.h"
#include <sstream>

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested


TEST(AccountCreation, Account)
{
	Account account_1(checking, "Tyler Morgan", 12345, 1234);
	CHECK_EQUAL(0.0, account_1.get_balance(1234));
}

TEST(AccountDeposit, Account)
{
	Account account_1(checking, "Tyler Morgan", 12345, 1234);
	account_1.deposit(10.0);
	account_1.deposit(10.0,1234);
	CHECK_EQUAL(20.0, account_1.get_balance(1234));
}

TEST(Withdraw, Account)
{
	Account account_1(checking, "Tyler Morgan", 12345, 1234);
	account_1.deposit(10.0);
	account_1.deposit(10.0,1234);
	account_1.withdraw(10.0, 5678); //make sure it doesn't withdraw with wrong pin
	CHECK_EQUAL(20.0, account_1.get_balance(1234));
	account_1.withdraw(10.0,1234);
	CHECK_EQUAL(10.0, account_1.get_balance(1234));
}

TEST(GetInfoMethods, Account)
{
	CHECK_EQUAL(1,1);
}

TEST(Transfer, Account)
{
	Account account_1(checking, "Tyler Morgan", 12345, 1234);
	Account account_2(checking, "Philip J. Fry", 12346, 1077);
	account_1.deposit(50.0);
	account_1.transfer(20.0, account_2, 1234);
	CHECK_EQUAL(20.0, account_2.get_balance(1077));
}

TEST(DatabaseReadWrite, Database)
{
	Database db;
	Account account_1(checking, "Tyler Morgan",db.get_next_account_num(),1234);
	Account account_2(checking, "Phil",db.get_next_account_num(), 1234);
	db.write_to_db(account_1);
	db.write_to_db(account_2);
	Account& account_1_ref = db.get_account_by_num(0);
	account_1_ref.deposit(15.0);
	Account& account_2_ref = db.get_account_by_num(1);
	account_1_ref.transfer(5.0,account_2_ref,1234);
	CHECK_EQUAL(5.0, account_2_ref.get_balance(1234));
}