//Tyler Morgan
//Mar-9-2013
//C++ UW Online Course Winter
//Charque2.h
//Create a char queue using a standard array

class CharQueue2
{
public:
	CharQueue2();
	~CharQueue2();
	void enqueue(char);
	char dequeue();
	char peek();
	char at(int);
private:
	int queue_size;
	char* queue;

};

