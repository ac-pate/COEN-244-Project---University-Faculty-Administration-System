#ifndef GRADE_H
#define GRADE_H
#include "course.h"

#include <iostream>
using namespace std;

class Grade {
private:
    int courseNumber;
    string courseName;
    string courseGrade;

    Course course1;

public:

    
    Grade(Course&);
    
    ~Grade();

    void setCourseGrade(string);
    string getCourseGrade() const;


    void print() const;

};

#endif