#ifndef UNDERGRADUATESTUDENT_H
#define UNDERGRADUATESTUDENT_H

#include "Student.h"
#include "Course.h"
#include "Grade.h"
#include "Date.h"
#include <iostream>
using namespace std;

class UndergraduateStudent : public Student {

private:
    Grade* grades[50];

public:
    UndergraduateStudent();
    UndergraduateStudent(string, Date, Date);
    virtual ~UndergraduateStudent();

    bool insertCourse(Course&);
    bool dropCourse(Course&);
    bool setGrade(Course*, string);

    virtual void print() const;

};

#endif


 