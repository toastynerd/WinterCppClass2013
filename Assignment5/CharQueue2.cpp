//Tyler Morgan
//Mar-9-2013
//C++ UW Online Course Winter
//Charque2.h
//Create a char queue using a standard array
#include <iostream>
#include "CharQueue2.h"

char CharQueue2::dequeue()
{
	if(queue_size == 0)
	{
		std::cout << "Warning: Nothing in the queue!" << std::endl;
		return ' ';
	}
	char pop_value;
	pop_value = queue[0];
	for(int x = 0; x < (queue_size -1); x++)
	{
		queue[x] = queue[x+1];
	}
	queue_size--;
	return pop_value;
}

void CharQueue2::enqueue(char input)
{
	queue[queue_size] = input;
	queue_size++;
	return;
}

char CharQueue2::peek()
{
	return queue[0];
}

char CharQueue2::at(int position)
{
	return queue[position];
}

CharQueue2::CharQueue2()
:queue_size(0)
{
	queue = new char[queue_size];
}

CharQueue2::~CharQueue2()
{
	delete[] queue;
}