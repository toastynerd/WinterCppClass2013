//Tyler Morgan
//Mar-9-2013
//C++ UW online course Winter
//CharQueue1.h
//Implement a queue class using std::deque
#include <deque>

class CharQueue1
{
public:
	CharQueue1();
	~CharQueue1();
	void enqueue(char);
	char dequeue();
	char peek();
	char at(int);
private:
	std::deque<char> queue;
};
