//Tyler Morgan
//Mar 24, 2013
//UW online c++ class qtr 1
//Assignment 6.3
//dynamic_array.h
#include "dynamic_array.h"

DynamicArray::DynamicArray()
	:my_size(0)
{
	int* my_array = new int[my_size];
}

DynamicArray::~DynamicArray()
{

}

void DynamicArray::put_at(int index, int value)
{

}

void DynamicArray::write_at(int index, int value)
{
	if(index > my_size)
	{
		int* new_array = new int[index];
		new_array = my_array;
		for(int x = my_size; x < index; x++)
		{
			new_array[x] = 0;
		}
		new_array[index] = value;
		//delete[] my_array;
		my_array = new_array;
		//delete[] new_array;
	}

}

const int DynamicArray::get_at(int index)
{
	return my_array[index];
}

void DynamicArray::remove_at(int index)
{

}