#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{

private:
	int month;
	int day;
	int year;

public:
	Date();
	Date(int month, int day, int year);

	~Date();
	friend ostream& operator<< (ostream&, const Date&);

	void printDate() const ;

};


#endif