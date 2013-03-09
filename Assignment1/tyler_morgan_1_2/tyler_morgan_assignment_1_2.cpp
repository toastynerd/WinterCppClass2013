//Tyler Morgan
//Feb-8-2013
//C++ Programming Winter 2013
//Assignment1.2
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int user_int;
	double user_double;
	string user_string;
	cout << "enter an integer:";
	cin >> user_int;
	cout << "enter a double:";
	cin >> user_double;
	cout << "enter a string:";
	cin >> user_string;

	cout << "Int:\t" << user_int << "\n";
	cout << "Double:\t" << user_double << "\n";
	cout << "String:\t" << user_string << "\n";
	return 1;

}