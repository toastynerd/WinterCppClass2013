//Tyler Morgan
//Mar 24, 2013
//UW online c++ class qtr 1
//Assignment 6.3
//dynamic_array.h
#include "dynamic_array.h"
#include <iostream>

DynamicArray::DynamicArray()
	:my_size(0)
{
	int* my_array = new int[my_size];
}

DynamicArray::~DynamicArray()
{
	//delete[] my_array; getting error "pointer being freed was not allocated and I'm not sure why."
}

void DynamicArray::put_at(int index, int value)
{
	if(index > my_size)
	{
		int* new_array = new int[index];
		new_array = my_array;
		for(int x = my_size; x < index; x++)
		{
			new_array[x] = 0;
		}
		my_size = index;
		new_array[index] = value;
		my_array = new_array;
		delete[] new_array;
	}
	else
	{
		int* new_array = new int[my_size-1];
		for(int x = 0; x < index;x++)
		{
			new_array[x] = my_array[x];
		}
		for(int x = index; x <= my_size;x++)
		{
			new_array[x+1] = my_array[x];
		}
		new_array[index] = value;
		my_array = new_array;
		my_size++;
		delete[] new_array;
	}
}

void DynamicArray::write_at(int index, int value)
{
	
	if(index > my_size)
	{
		int* new_array = new int[index];
		new_array = my_array;
		for(int x = my_size+1; x < index; x++)
		{
			new_array[x] = 0;
		}
		my_size = index;
		new_array[index] = value;
		my_array = new_array;
		//delete[] new_array; getting error "pointer being freed was not allocated and I'm not sure why."
	}
	else
	{
		my_array[index] = value;
	}
	
}

const int DynamicArray::get_at(int index)
{
	if(index > my_size)
	{
		std::cout << "No value for that index!" << std::endl;
		return 0;
	}
	return my_array[index];
}

void DynamicArray::remove_at(int index)
{
	if(index > my_size)
	{
		std::cout << "No value for that index!" << std::endl;
		return;
	}
	my_size--;
	int* new_array =  new int[my_size];
	for(int x=0;x < index;x++)
	{
		new_array[x] = my_array[x];
	}
	for(int x=index;x<=my_size;x++)
	{
		new_array[x] = my_array[x+1];
	}
	my_array = new_array;
	delete[] new_array;
}

int DynamicArray::size()
{
	return my_size;
}

int& DynamicArray::operator[](int index)
{
	return my_array[index];
}