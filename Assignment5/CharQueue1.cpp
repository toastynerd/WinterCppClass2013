//Tyler Morgan
//Mar-9-2013
//C++ UW online course Winter
//CharQueue1.h
//Implement a queue class using std::deque
#include <iostream>
#include "CharQueue1.h"

char CharQueue1::dequeue()
{
	if(queue.size() == 0)
	{
		std::cout << "Warning: Nothing in the queue!" << std::endl;
		return ' ';
	}
	char pop_value;
	pop_value = CharQueue1::queue.front();
	CharQueue1::queue.pop_front();
	return pop_value;
}

void CharQueue1::enqueue(char input)
{
	CharQueue1::queue.push_back(input);
}

char CharQueue1::peek()
{
	return CharQueue1::queue.front();
}
char CharQueue1::at(int location)
{
	return CharQueue1::queue.at(location);
}

CharQueue1::CharQueue1()
{

}
CharQueue1::~CharQueue1()
{
	
}
