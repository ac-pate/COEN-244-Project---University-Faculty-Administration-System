#include "CourseRegistration.h"
#include "Course.h"
#include <iostream>
using namespace std;

CourseRegistration::CourseRegistration(Course course) {
	this->course = course;
	no_of_enrolled_students = 0;

	if (course.getCourseNumber() < 500)
		student_ids = new int[50];
	else if (course.getCourseNumber() > 500 && course.getCourseNumber() < 600) 
		student_ids = new int[20];
	else
	    cout << " Not COrrect IDs" << endl;

}

CourseRegistration::~CourseRegistration() {
	if (student_ids != nullptr) {
		delete[] student_ids;
	}
	cout << "CourseRegistration object destroyed." << endl;
}


bool CourseRegistration::insertStudent(int student_id) {

	if (course.getCourseNumber() < 500) {
		if (no_of_enrolled_students == 50)
			return false;

		student_ids[no_of_enrolled_students] = student_id;
		no_of_enrolled_students++;
		return true;
	}

	else if (course.getCourseNumber() > 500 && course.getCourseNumber() < 600) {
		if (no_of_enrolled_students == 20)
			return false;

		student_ids[no_of_enrolled_students] = student_id;
		no_of_enrolled_students++;
		return true;
	}
}

bool CourseRegistration::dropStudent(int student_id) {

	for (int i = 0; i < no_of_enrolled_students; i++) {
		if (student_ids[i] == student_id) {
			for (int j = i; j < no_of_enrolled_students - 1; j++) {
				student_ids[j] = student_ids[j + 1];
			}
			no_of_enrolled_students--;

			student_ids[no_of_enrolled_students] = 0;
			return true;
		}

	}
	return false;
}
void CourseRegistration::setCourse(Course course)
{
	this->course = course;
}

Course CourseRegistration::getCourse() const {
	return this->course;
} 

int CourseRegistration::getCourseNum() const {

	
	return course.getCourseNumber();
}

string CourseRegistration::getCourseInstructor() const {
	return course.getInstructorName();
}

int CourseRegistration::operator+ (int number) {

	return this -> no_of_enrolled_students + number;
	

}

//Course CourseRegistration::operator+ (Course& course) {
//	int n;
//	n = no_of_enrolled_students + n;
//
//	return course;
//}



void CourseRegistration::print() {

	course.print();
	cout << "Number of Enrolled Students: " << no_of_enrolled_students << endl;
	for (int i = 0; i < no_of_enrolled_students; i++) {

		cout << "Registered IDs : " << student_ids[i] << endl;
	}
}
 
