//Tyler Morgan
//feb-16-2013
//UW C++ online course
//Assignment 2.1
#include <iostream>

bool swap_ints_pntr(int* int_1, int* int_2)
{
	int buffer = 1;
	buffer = *int_1;
	*int_1 = *int_2;
	*int_2 = buffer;

	return true;
}

bool swap_ints_ref(int& int_1, int& int_2)
{
	int buffer = 1;
	buffer = int_1;
	int_1 = int_2;
	int_2 = buffer;

	return true;
}