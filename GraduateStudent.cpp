#include "Student.h"
#include "Person.h"
#include "Course.h"
#include "Grade.h"
#include "GraduateStudent.h"
#include "Date.h"

#include <iostream>
using namespace std;

GraduateStudent::GraduateStudent()
{
    for (int i = 0; i < 15; i++)
    {
        this->grades[i] = nullptr;
    }
}

GraduateStudent::GraduateStudent(string name_supervisor, string name, Date birthdate, Date enrollment_date) 
    : Student(name, birthdate, enrollment_date)
{
    for (int i = 0; i < 15; i++)
    {
        this->grades[i] = nullptr;
    }

    this->set_name_of_supervisor(name_supervisor);
}
GraduateStudent::~GraduateStudent() {

    for (int i = 0; i < 15; i++) {
        delete grades[i];
    }
    cout << "UndergraduateStudent object destroyed." << endl;
}

bool GraduateStudent::insertCourse(Course& course1)  {	//Set a pointer to a course.
	Grade* ptr = new Grade(course1);
	int a = 0;
	for (int i = 0; i < 15; i++) {
		if (grades[i] == nullptr) {
			grades[i] = new Grade(course1);
			delete ptr;
			return true;
		}
		if ((grades[i] == ptr)) { //pointer to course already exists. 
			delete ptr;

			cout << "You cannot register in same course twice.." << endl;
			return false;
		}
		if (grades[i]->getCourseGrade() == "") {
			a++;
			if (a >= 3) {	//check if 3 registerd course detected.
				delete ptr;

				cout << "Graduate student cannot register in more than 3 courses.." << endl;
				return false;
			}
		}
	}
	delete ptr;
	return false;
}

bool GraduateStudent::dropCourse(Course& course1) {	//drop a course.
	Grade* ptr = new Grade(course1);
	for (int i = 0; i < 15; i++) {
		if (grades[i] == ptr) {
			delete ptr;
			delete grades[i];
			for (int j = i; j < 14; j++) {
				grades[j] = grades[j + 1];	//shift everything.
			}
			grades[14] = nullptr;	//set the very last available spot empty
			return true;
		}
	}
	delete ptr;
	return false;
}

bool GraduateStudent::setGrade(Course* course1, string grade) {	//set a grade for a course
	Grade* ptr = new Grade(*course1);
	for (int i = 0; i < 15; i++) {
		if (grades[i] == nullptr) {
			delete ptr;
			return false;
		}
		if (grades[i] == ptr) {
			delete ptr;
			grades[i]->setCourseGrade(grade);
			return true;
		}
	}
	delete ptr;

	cout << "This course is not available in student cart to remove, please check again.." << endl;
	return false;
}

void GraduateStudent::set_name_of_supervisor(string name_supervisor) {
    this->name_supervisor = name_supervisor;
}

string GraduateStudent::get_name_of_supervisor() const {

	return name_supervisor;
	
}

void GraduateStudent::print() const {
	cout << "Supervisor: " << get_name_of_supervisor() << endl;
	cout << "Courses : \n";
	for (int i = 0; i < 15; i++) {
		if (grades[i] == nullptr) {
			if (i == 0)
				cout << "No Course Found" << endl;
			break;
		}
		grades[i]->print();
		cout << endl;
	}
	cout << endl;
}
