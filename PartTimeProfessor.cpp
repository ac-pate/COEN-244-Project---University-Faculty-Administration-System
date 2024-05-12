#include "PartTimeProfessor.h"
#include "Professor.h"
#include "Course.h"
#include "Date.h"
#include <iostream>
using namespace std;


PartTimeProfessor::PartTimeProfessor() {

    for (int i = 0; i < 3; i++) {

        this->teaching_courses[i] = nullptr;
    }
}

PartTimeProfessor::PartTimeProfessor(string name, Date birthdate, Date employment_date) 
    : Professor(name, birthdate, employment_date) {

    for (int i = 0; i < 3; i++) {

        this->teaching_courses[i] = nullptr;
    }
}

PartTimeProfessor::~PartTimeProfessor() {

    for (int i = 0; i < 3; i++) {

        delete teaching_courses[i];
    }
}

bool PartTimeProfessor::insertCourse(Course& course1) {

    for (int i = 0; i < 3; i++)
    {
        if (this->teaching_courses[i] == nullptr)
        {
            this->teaching_courses[i] = &course1;
            return true;
        }
        else if (this->teaching_courses[i]->getCourseNumber() == course1.getCourseNumber())
        {
            cout << "This course is already available in your teaching course list..." << endl;
            return false;
        }
    }

    cout << "Part time professor can not teach more than 3 courses..." << endl;
    return false;
}

Course* PartTimeProfessor::get_teaching_courses() const
{
    return *this->teaching_courses;
}

void PartTimeProfessor::print()
{
    this->Professor::print();
    cout << "List of courses being teach by this professor : " << endl;

    for (int i = 0; i < 3; i++)
    {
        if (this->teaching_courses[i] != nullptr)
        {
            this->teaching_courses[i]->print();
        }
        cout << endl;
    }
}
