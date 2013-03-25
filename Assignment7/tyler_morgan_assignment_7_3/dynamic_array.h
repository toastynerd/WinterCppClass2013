//Tyler Morgan
//Mar 24, 2013
//UW online c++ class qtr 1
//Assignment 6.3
//dynamic_array.h

class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();
	void put_at(int index,int value);
	void write_at(int index, int value);
	const int get_at(int index);
	void remove_at(int index);
	int size();
private:
	int my_size;
	int* my_array;
};