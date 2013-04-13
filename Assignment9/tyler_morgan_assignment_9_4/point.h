//Tyler Morgan
//April-8-2013
//UW Winter online c++ class 1st qtr
//final project
//point.h

class Point
{
	// data is left public so it is essentially a struct but with the ability to more easily add methods
	// such as transform() if necessary
public:
	Point(int x, int y);
	~Point();
	int x;
	int y;
}