#ifndef COURSEREGISTRATION_H
#define COURSEREGISTRATION_H

#include "Course.h"

#include <iostream>
using namespace std;

class CourseRegistration
{
private:
    Course course;
    int* student_ids;
    int no_of_enrolled_students;

public:
    CourseRegistration(Course);
    ~CourseRegistration();

    
    bool insertStudent(int);
    bool dropStudent(int);

    void setCourse(Course course);
    Course getCourse() const;

    int getCourseNum() const;
    string getCourseInstructor() const;

    int operator+ (int);
    //Course operator + (Course&);
    void print();
};

#endif