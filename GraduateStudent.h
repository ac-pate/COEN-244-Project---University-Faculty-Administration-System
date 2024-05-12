#ifndef GRADUATESTUDENT_H
#define GRADUATESTUDENT_H

#include "Student.h"
#include "Person.h"
#include "Course.h"
#include "Grade.h"
#include "Date.h"
#include <iostream>
using namespace std;

class GraduateStudent : public Student {

private:
    string name_supervisor;
    Grade* grades[15];

public:
    GraduateStudent();
    GraduateStudent(string, string, Date, Date);
    virtual ~GraduateStudent();

    bool insertCourse(Course&);
    bool dropCourse(Course&);
    bool setGrade(Course*, string);

    void set_name_of_supervisor(string);
    string get_name_of_supervisor() const;

    virtual void print() const;
};
#endif