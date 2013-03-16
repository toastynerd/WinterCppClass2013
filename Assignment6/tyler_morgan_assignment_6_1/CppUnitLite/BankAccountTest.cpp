#include "TestHarness.h"
#include "../account.h"


// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested


TEST(Account_Constructor, Account)
{
	Account a_account(checking, 1);
	CHECK_EQUAL(0.0,a_account.get_balance());

}

