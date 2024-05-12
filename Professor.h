#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Person.h"
#include "Date.h"

#include <iostream>
using namespace std;


class Professor : public Person
{
private:
  
    int employee_id;
    Date employment_date;

public:
    Professor();
    Professor(const string, const Date, const Date);
    virtual ~Professor();

    void set_employment_date(Date);
    Date get_employment_date() const;

    int getId() const;

    virtual void print() const;
   
};
#endif // !PROFESSOR_H