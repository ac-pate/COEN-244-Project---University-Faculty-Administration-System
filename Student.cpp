#include "Student.h"
#include "Date.h"
#include <iostream>
using namespace std;


Student::Student() {
    student_id = 0;
    
}

Student::Student(const string name, Date birthdate, Date enrollment_date)
    : Person(name,birthdate) {

    static int next_student_id = 1000;  // Starting student_id
    student_id = next_student_id++;
    this->enrollment_date = enrollment_date;
}

Student::~Student() {
    cout << "Student object destroyed." << endl;
}

void Student::setEnrollmentDate(Date enrollment_date) {

    this->enrollment_date = enrollment_date;
}

int Student::getId() const {

    return this->student_id;
}

string Student::getStudentName() const {

    return this->getPersonName();
}

Date Student::getEnrollmentDate() const {

    return this->enrollment_date;
}

ostream& operator<<(ostream& output,  Student& s1)
{
    Person* ptr;
    ptr = &s1;
  
    output  << *ptr << " " << s1.student_id << " " << s1.enrollment_date ;
   
   

    return output;
}

void Student::print() const {
    Person::print();
    cout << "Student ID: " << this->student_id << "  Enrollment date :";
    enrollment_date.printDate(); 
    cout << "-----------------------------------------------------------------------" << endl;
    cout << endl;
    

} 

int Student::getEnrolledSubjects() const { /////////////////////////////////////////////////////

    return 0;
}

