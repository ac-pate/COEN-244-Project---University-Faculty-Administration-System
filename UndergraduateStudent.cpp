#include "Student.h"
#include "Course.h"
#include "Grade.h"
#include "UndergraduateStudent.h"
#include <iostream>
using namespace std;

UndergraduateStudent::UndergraduateStudent() {

    for (int i = 0; i < 50; i++) {
        this->grades[i] = nullptr;
    }
}

UndergraduateStudent::UndergraduateStudent(string name, Date birthdate, Date enrollment_date) 
    : Student(name, birthdate, enrollment_date) {

    for (int i = 0; i < 50; i++) {
        this->grades[i] = nullptr;
    }
}

UndergraduateStudent::~UndergraduateStudent() {
    
    for (int i = 0; i < 50; i++) {
        delete grades[i];
    }
    cout << "UndergraduateStudent object destroyed." << endl;
}

bool UndergraduateStudent::insertCourse(Course& course1) {	
	Grade* ptr = new Grade(course1);
	int a = 0;
	for (int i = 0; i < 50; i++) {
		if (grades[i] == nullptr) {
			grades[i] = new Grade(course1);
			delete ptr;
			return true;
		}
		if (grades[i] == ptr) { //pointer to course already exists. 
			delete ptr;

			cout << "You cannot register in same course twice.." << endl;
			return false;
		}
		if (grades[i]->getCourseGrade() == "") {
			a++;
			if (a >= 6) {	//check if 6 registerd course detected.
				delete ptr;
				cout << "Undergraduate student cannot register in more than 6 courses.." << endl;
				return false;
			}
		}
	}
	delete ptr;
	return false;
}

bool UndergraduateStudent::dropCourse(Course& course1) {	
	Grade* ptr = new Grade(course1);
	for (int i = 0; i < 50; i++) {
		if (grades[i] == ptr) {
			delete ptr;
			delete grades[i];
			for (int j = i; j < 49; j++) {
				grades[j] = grades[j + 1];	//shift everything.
			}
			grades[49] = nullptr;	//set the very last available spot empty
			return true;
		}
	}
	delete ptr;

	cout << "This course is not available in student cart to remove, please check again.." << endl;
	return false;
}

bool UndergraduateStudent::setGrade(Course* course1, string grade) {	
	Grade* ptr = new Grade(*course1);
	for (int i = 0; i < 50; i++) {
		if (grades[i] == ptr) {
			delete ptr;
			grades[i]->setCourseGrade(grade);
			return true;
		}
	}
	delete ptr;
	return false;
}

void UndergraduateStudent::print() const {
    Student::print();
    for (int i = 0; i < 50; i++)
    {
        if (this->grades[i] != nullptr)
        {
            this->grades[i]->print();
        }
        cout << endl;
    }
};

