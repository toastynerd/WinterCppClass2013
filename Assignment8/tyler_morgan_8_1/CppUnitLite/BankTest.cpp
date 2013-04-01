#include "TestHarness.h"
#include "../bank.h"

// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
TEST(BasicAccount,Account)
{
	Account account1(1);
	Account account2(2);

	account1.deposit(10.0);
	account2.deposit(15.5);

	account2.transfer_to(5.5,account1);

	CHECK_EQUAL(15.5,account1.get_balance());

}

TEST(Checking, CheckingAccount)
{
	CheckingAccount account1(1);
	
	account1.deposit(100.0);
	account1.cash_check(30, 1234);
	CHECK_EQUAL(false, account1.cash_check(30,1234)); //make sure you can't cash the same check twice
}

TEST(interest, SavingsAccount)
{
	SavingsAccount account1(1,0.1);
	account1.deposit(10.0);
	account1.add_interest();
	CHECK_EQUAL(11,account1.get_balance());
}