#ifndef PERSON_H
#define PERSON_H

#include "Date.h"
#include <iostream>
using namespace std;

class Person {
private:

    string person_name;
    Date birth_date;

public:
    Person();
    Person(const string, const Date);
    virtual ~Person();

    // Getter and Setter functions


    string getPersonName() const;
    Date getBirthDate() const;

    friend ostream& operator<<(ostream&,  const Person&);
    

     virtual int getId() const = 0;
     virtual void print() const;


};

#endif
