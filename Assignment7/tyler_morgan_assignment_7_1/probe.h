#include <iostream>

class Probe
{
public:
	Probe();
	~Probe();
	void increase();
	void decrease();
	friend std::ostream& operator<<(std::ostream&, const Probe&);
private:
	int my_count;
};