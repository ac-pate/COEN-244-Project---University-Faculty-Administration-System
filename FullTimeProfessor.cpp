#include "FullTimeProfessor.h"
#include "Date.h"
#include "Course.h"
#include "GraduateStudent.h"
#include "Professor.h"
#include <iostream>
using namespace std;

FullTimeProfessor::FullTimeProfessor() {

    for (int i = 0; i < 10; i++)
    {
        this->supervised_students[i] = nullptr;
    }

    for (int i = 0; i < 2; i++)
    {
        this->teaching_courses[i] = nullptr;
    }
}

FullTimeProfessor::FullTimeProfessor(string name, Date birthdate, Date employment_date) : Professor(name, birthdate, employment_date) {

    for (int i = 0; i < 10; i++)
    {
        this->supervised_students[i] = nullptr;
    }

    for (int i = 0; i < 2; i++)
    {
        this->teaching_courses[i] = nullptr;
    }
}

FullTimeProfessor::~FullTimeProfessor() {

    for (int i = 0; i < 10; i++)
    {
        delete supervised_students[i];
    }

    for (int i = 0; i < 2; i++)
    {
        delete teaching_courses[i];
    }
    cout << "FullTimeProfessor object destroyed." << endl;
}


bool FullTimeProfessor::insertSupervisedStudent(GraduateStudent& student) {

    if (this->no_of_supervised_students < 10)
    {
        for (int i = 0; i < this->no_of_supervised_students; i++) 
        {
            if (this->supervised_students[i]->getId() == student.getId())
            {
                cout << "This student is already register with this professor.." << endl;
                return false;
            }
        }
        this->supervised_students[this->no_of_supervised_students] = &student;
        this->no_of_supervised_students++;
        return true;
    }
    cout << "Full time professor can not supervise more than 10 students..." << endl;
    return false;
}

bool FullTimeProfessor::insertCourse(Course& course1) {

    for (int i = 0; i < 2; i++) {
        if (this->teaching_courses[i] == nullptr)
        {
            teaching_courses[i] = &course1;
            return true;
        }
        else if (this->teaching_courses[i]->getCourseNumber() == course1.getCourseNumber())
        {
            cout << "This course is already available in your teaching course list..." << endl;
            return false;
        }
    }

    cout << "Full time professor can not teach more than 2 courses..." << endl;
    return false;
}

int FullTimeProfessor::get_no_of_supervised_students() {

    return this->no_of_supervised_students;
}

void FullTimeProfessor::print() {

    this->Professor::print();
    cout << "List of student under supervision : " << endl;

    for (int i = 0; i < this->no_of_supervised_students; i++)
    {
        cout << this->supervised_students[i]->get_name_of_supervisor() << endl;
    }

    cout << "List of courses being teach by this professor : " << endl;

    for (int i = 0; i < 2; i++)
    {
        if (this->teaching_courses[i] != nullptr)
        {
            this->teaching_courses[i]->print();
        }
        cout << endl;
    }
}