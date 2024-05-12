#include "Course.h"
#include <string>
#include <iostream>
using namespace std;

Course::Course() {
    courseNumber = 0;
}

Course::Course(int courseNumber, string courseName, string instructorName) {

    this->courseNumber = courseNumber;
    this->courseName = courseName;
    this->instructorName = instructorName;
}

Course::~Course() {

    cout << "Course object destroyed." << endl;
}
void Course::setCourseNumber(int courseNumber) {

    this->courseNumber = courseNumber;
}

void Course::setCourseName(string courseName) {

    this->courseName = courseName;
}

void Course::setInstructorName(string instructorName) {

    this->instructorName = instructorName;
}

int Course::getCourseNumber() const {

    return courseNumber;
}

string Course::getCourseName() const {

    return this->courseName;
}

string Course::getInstructorName() const {

    return instructorName;
}

void Course::print() {

    cout << "Course: " << this->getCourseNumber() << "  " << this->getCourseName()
         << "--->" << "taught by: " << this->getInstructorName() << endl;
}



