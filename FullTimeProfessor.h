#ifndef FULLTIMEPROFESSOR_H
#define FULLTIMEPROFESSOR_H

#include "Professor.h"
#include "GraduateStudent.h"
#include "Course.h"
#include <iostream>
using namespace std;

class FullTimeProfessor : public Professor {

private:
    GraduateStudent* supervised_students[10];
    int no_of_supervised_students = 0;
    Course* teaching_courses[2];

public:
    FullTimeProfessor();
    FullTimeProfessor(string name, Date birthdate, Date employment_date);
    virtual ~FullTimeProfessor();

    bool insertSupervisedStudent(GraduateStudent& student);
    bool insertCourse(Course&);

    int get_no_of_supervised_students();

    virtual void print() ;
};

#endif