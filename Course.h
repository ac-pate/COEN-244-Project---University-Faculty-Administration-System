#ifndef COURSE_H
#define COURSE_H


#include <string>
#include <iostream>
using namespace std;

class Course
{
private:
    int courseNumber;
    string courseName;
    string instructorName;

public:
    Course();
    Course(int, string, string);
    ~Course();

    void setCourseNumber(int);
    void setCourseName(string);
    void setInstructorName(string);

    int getCourseNumber() const ;
    string getCourseName() const;
    string getInstructorName() const;

    void print();
};


#endif