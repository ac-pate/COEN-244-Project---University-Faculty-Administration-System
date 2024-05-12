#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() {

	this->month = 6;
	this->day = 3;
	this->year = 2023;
}

Date::Date(int month, int day, int year) {

	this->month = month;
	this->day = day;
	this->year = year;
}

Date::~Date() {
	//cout << "Date object deleted." << endl;

}

ostream& operator<<(ostream& output, const Date& date)
{
	output << date.month << " " << date.day << " " << date.year ;
	return output;
}
void Date::printDate() const {

	
	cout << month << "/" << day << "/" << year << endl;
}