#include <iostream>
#include "Grade.h"
#include "Course.h"


Grade::Grade(Course& course1) {
    this->courseNumber = course1.getCourseNumber();
    this->courseName = course1.getCourseName();
    this->courseGrade = "";
}


Grade::~Grade() {
    cout << "Grade object destroyed." << endl;
}

void Grade::setCourseGrade(string grade) {
    courseGrade = (grade == "A" || grade == "B" || grade == "C" || grade == "D" || grade == "F") ? grade : "";
}

string Grade::getCourseGrade() const {
    return this->courseGrade;
}

void Grade::print() const {
    cout << "Course: " << courseNumber << "  " << courseName
         << "--->" << "Course Grade: " << this->courseGrade << endl;
}