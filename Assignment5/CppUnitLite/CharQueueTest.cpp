#include "TestHarness.h"
#include "../CharQueue1.h"
#include "../CharQueue2.h"
#include <iostream>


// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
TEST(CharQueue1_test, CharQueue1)
{
	CharQueue1 myQueue;
	myQueue.enqueue('a');
	myQueue.enqueue('b');
	myQueue.enqueue('c');
	myQueue.dequeue();
	myQueue.dequeue();
	CHECK_EQUAL('c',myQueue.dequeue());
}

TEST(CharQueue2_test, CharQueue2)
{
	CharQueue2 myQueue;
	myQueue.enqueue('b');
	myQueue.enqueue('c');
	myQueue.dequeue();
	CHECK_EQUAL('c',myQueue.peek());
}

TEST(Nothing_in_CharQueue1, CharQueue1)
{
	CharQueue1 myQueue;
	CHECK_EQUAL(' ',myQueue.dequeue());

}

TEST(Nothing_in_CharQueue2, CharQueue2)
{
	CharQueue2 myQueue;
	CHECK_EQUAL(' ', myQueue.dequeue());
}