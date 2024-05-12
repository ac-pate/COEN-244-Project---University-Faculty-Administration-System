#ifndef PARTTIMEPROFESSOR_H
#define PARTTIMEPROFESSOR_H

#include "Professor.h"
#include "Course.h"
#include "Date.h"

#include <iostream>
using namespace std;

class PartTimeProfessor : public Professor
{
private:
    Course* teaching_courses[3];

public:
    PartTimeProfessor();
    PartTimeProfessor(string, Date, Date);
    virtual ~PartTimeProfessor();

    bool insertCourse(Course&);

    Course* get_teaching_courses() const;

    virtual void print();
};
#endif // PARTTIMEPROFESSOR_H