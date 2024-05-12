#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "Date.h"
#include "Course.h"
#include <iostream>
using namespace std;


class Student : public Person {
private:
    int student_id;
    Date enrollment_date;   // date opj named enrollment_date

public:
    Student();
    Student(const string, const Date, const Date);
    virtual ~Student();

    void setEnrollmentDate(Date enrollment_date);

    int getId() const;
    string getStudentName () const;
    int getEnrolledSubjects() const; // give number of enrolled subjects
    Date getEnrollmentDate() const;

    // to use in dataManager 
    virtual bool insertCourse(Course&) = 0;
    virtual bool dropCourse(Course&) = 0;
    
    friend ostream& operator<<(ostream&,  Student&);
    virtual void print() const;

};

#endif