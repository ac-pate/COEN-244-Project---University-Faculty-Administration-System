#include "Person.h"
#include "Date.h"
#include <iostream>
using namespace std;

Person::Person() : person_name() {}

Person::Person(const string person_name, const Date birth_date)  {

    this->person_name = person_name;
    this->birth_date = birth_date;

}

string Person::getPersonName() const {

    return this->person_name;
}

Date Person::getBirthDate() const {

    return this->birth_date;
}

ostream& operator<<(ostream& output, const Person& p1)
{

    output << p1.person_name << " " << p1.birth_date;
    return output;
}
void Person::print() const {
    cout << "Name: " << person_name << "DOB:";
    birth_date.printDate();
    cout << endl;

}

Person::~Person() {
    cout << "Person object deleted." << endl;
}
