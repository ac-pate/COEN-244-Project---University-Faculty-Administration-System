#include "dataManager.h"
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include "FullTimeProfessor.h"
#include "PartTimeProfessor.h"
#include "CourseRegistration.h"
#include "Course.h"
#include "Grade.h"
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;


dataManager::dataManager() {

    // Initializing member variables
    this->ugstudent_count = 0;
    this->gstudent_count = 0;
    this->ftprofessor_count = 0;
    this->ptprofessor_count = 0;
    this->coursearray_count = 0;

    // Initializing arrays of objects with nullptr
    //student = new Student[2300];
    for (int i = 0; i < 2300; i++)
        student[i] = nullptr;
    
    //professor = new Professor[50];
    for (int i = 0; i < 50; i++)
        professor[i] = nullptr;
    
    //coursearray = new CourseRegistration[50];
    for (int i = 0; i < 50; i++)    
        coursearray[i] = nullptr;
    
}

dataManager::~dataManager() {
    //delete[] student;
    //delete[] professor;
    //delete[] coursearray;
    cout << "DataManager Object Deleted" << endl;
}

bool dataManager::insert(UndergraduateStudent* student) {
    if (ugstudent_count < 2000) {

        // Checking if the student already exists
        for (int i = 0; i < ugstudent_count; i++) {
           
            if (dynamic_cast<UndergraduateStudent*>(this->student[i]) != nullptr && this->student[i]->getId() == student->getId()) {

                cout << "Error: Student with ID " << student->getId() << " already exists." << endl;
                return false;
            }
        }

        // Inserting the student
        this->student[ugstudent_count] = student;
        ugstudent_count++;
        cout << "Successfully inserted undergraduate student with ID " << student->getId() << endl;
    }
    else {

        cout << "Error: Maximum limit of undergraduate students reached." << endl;
    }
    return false;
}

bool dataManager::insert(GraduateStudent* student) {
    if (gstudent_count < 300) {

        // Checking if the student already exists
        for (int i = 0; i < gstudent_count; i++) {

            if (dynamic_cast<GraduateStudent*>(this->student[i]) != nullptr && this->student[i]->getId() == student->getId()) {

                cout << "Error: Student with ID " << student->getId() << " already exists." << endl;
                return false;
            }
        }

        // Inserting the student
        this->student[ugstudent_count + gstudent_count] = student;
        gstudent_count++;
        cout << "Successfully inserted graduate student with ID " << student->getId() << endl;
        return true;
    }
    else {

        cout << "Error: Maximum limit of graduate students reached." << endl;
    }
    return false;
}

bool dataManager::insert(FullTimeProfessor* professor) {
   
    if (ftprofessor_count < 40) {

        // Checking if the professor already exists
        for (int i = 0; i < ftprofessor_count; i++)
        {
            if (dynamic_cast<FullTimeProfessor*>(this->professor[i]) != nullptr && this->professor[i]->getId() == professor->getId())
            {
                cout << "Error: Full-time professor with ID " << professor->getId() << " already exists." << endl;
                return false;
            }
        }

        // Inserting the professor
        this->professor[ftprofessor_count] = professor;
        ftprofessor_count++;
        cout << "Successfully inserted full-time professor with ID " << professor->getId() << endl;
        return true;
    }
    else {

        cout << "Error: Maximum limit of full-time professors reached." << endl;
        return false;
    }

}

bool dataManager::insert(PartTimeProfessor* professor) {

    if (ptprofessor_count < 10)
    {
        // Checking if the professor already exists
        for (int i = 0; i < ptprofessor_count; i++)
        {
            if (dynamic_cast<PartTimeProfessor*>(this->professor[i]) != nullptr && this->professor[i]->getId() == professor->getId())
            {
                cout << "Error: Part-time professor with ID " << professor->getId() << " already exists." << endl;
                return false;
            }
        }

        // Inserting the professor
        this->professor[ptprofessor_count + ftprofessor_count] = professor;
        ptprofessor_count++;
        cout << "Successfully inserted part-time professor with ID " << professor->getId() << endl;
        return true;
    }
    else
    {
        cout << "Error: Maximum limit of part-time professors reached." << endl;
        return false;
    }
}

bool dataManager::insert(CourseRegistration* course1) {

        if (coursearray_count < 50) {

            // Checking if the course registration already exists
            for (int i = 0; i < coursearray_count; i++)
            {
                if (coursearray[i]->getCourseNum() == course1->getCourseNum())
                {
                    return false;
                }
            }
            // Inserting the course registration
            coursearray[coursearray_count] = course1;
            coursearray_count++;

            cout << "Course registration inserted successfully." << endl;
            return true;
        }
        else {

            cout << "Maximum limit of course registrations reached." << endl;
        }
        return false;
}

bool dataManager::registering_to_Course(Student* student, Course& course) {

    if (dynamic_cast<UndergraduateStudent*>(student) != nullptr && course.getCourseNumber() >= 500) {

        cout << "Undergraduate student cannot register for graduate courses." << endl;
        return false;
    } 
    else if (dynamic_cast<GraduateStudent*>(student) != nullptr && course.getCourseNumber() < 500 && course.getCourseNumber() > 600) {

            cout << "Graduate student cannot register for Under graduate courses." << endl;
            return false;
    } 
    else {
         
        CourseRegistration* courseRegistration = nullptr;

        // Finding the course registration
        for (int i = 0; i < coursearray_count; i++)
        {
            if (coursearray[i]->getCourseNum() == course.getCourseNumber())
            {
                courseRegistration = coursearray[i];
                break;
            }
        }


        // Registering the student for the course
        if (courseRegistration != nullptr && student != nullptr) {
            courseRegistration->insertStudent(student->getId());
        }
        student->insertCourse(course);

        
        return true;

        if (dynamic_cast<UndergraduateStudent*>(student) != nullptr && course.getCourseNumber() >= 500) {

            cout << "Undergraduate student successfully registered for the course." << endl;
            return false;
        }
        else if (dynamic_cast<GraduateStudent*>(student) != nullptr && course.getCourseNumber() > 500 && course.getCourseNumber() < 600) {

               cout << "Graduate student successfully registered for the course." << endl;
               return false;
        }
    }
    return false;
}

bool dataManager::dropping_a_Course(Student* student, Course& course) {

    CourseRegistration* courseRegistration = nullptr;

    // Finding the course registration
    for (int i = 0; i < coursearray_count; i++)
    {
        if (coursearray[i]->getCourseNum() == course.getCourseNumber())
        {
            courseRegistration = coursearray[i];
            break;
        }
    }

    if (courseRegistration == nullptr)
    {
        cout << "This course is not available in our system, please check again.." << endl;
        return false;
    }

    // Removing the student from the course registration and the student's course list
    else if (courseRegistration->dropStudent(student->getId()) && student->dropCourse(course))
    {
        cout << "Dropped the course successfully.." << endl;
        return true;
    }

    cout << "Failed to drop the course.." << endl;
    return false;
}

void dataManager::studentCourses(Student* student) {

    cout << "Courses registered by undergraduate student: " << student->getStudentName() << " ID: " << student->getId() << endl;
    student->print();

}

void dataManager::printCourseInfo(Course& course1) const {

    for (int i = 0; i < 50; i++) {
        if (coursearray[i] == nullptr)
            break;
        else if (coursearray[i]->getCourseNum() == course1.getCourseNumber()) {
            coursearray[i]->print();
        }
    }
}

bool dataManager::graduateSupervisor(FullTimeProfessor& professor, GraduateStudent& student) {

    if (professor.insertSupervisedStudent(student))
    {
        cout << "Supervisor assigned successfully." << endl;
        return true;
    }
    return false;

}
 
void dataManager::printProfessorInfo(FullTimeProfessor* professor)  {

    professor->print();
}


int  dataManager::getTotal() {

    int total = 0;
    for (int i = 0; i < coursearray_count; i++) {
        if (coursearray[i] == nullptr)
            return total;
        else
            total = *coursearray[i] + total;
     }
    cout << "The total students registered in the university: " << total << endl;

    return 0;
}


void dataManager::save(string StudentFile) {
    GraduateStudent* stdt;
    
        ofstream outputFile;
    try {
        outputFile.open(StudentFile);

        if (!outputFile) {
            throw exception();
        }

        

        for (int i = 0; i < 2300; i++) {
            if (student[i] == nullptr) {
                 break;
            }
            else if (dynamic_cast<UndergraduateStudent*>(student[i])) {
                outputFile << "ugstudent" << " " << *student[i]  <<  endl;
            }
            else if (dynamic_cast<GraduateStudent*>(student[i])) {
                stdt = static_cast<GraduateStudent*>(student[i]);
                outputFile << "gstudent" << " " << *student[i] << " " << stdt->get_name_of_supervisor() <<  endl;
            }
            else
                cout << "There is a problem" << endl;
        }

    }
    catch (exception) {
        cout << StudentFile << "Failed to open" << endl;
    }
        outputFile.close();            //////////////////////////
}

void dataManager::read(int studentId) {
    ifstream inputFile;
    string className;
    string name;
    int birthmonth, birthday, birthyear,
        student_id,
        enrollment_month, enrollment_day, enrollment_year;
    string supervisorName;

    try {
        inputFile.open("StudentFile.txt");
        if (!inputFile) throw exception();

        inputFile >> className >> name >> birthmonth >> birthday >> birthyear >> student_id >> enrollment_month >> enrollment_day >> enrollment_year;
        if (className == "gstudent")
            inputFile >> supervisorName;



        while (inputFile >> className >> name >> birthmonth >> birthday >> birthyear >> student_id >> enrollment_month >> enrollment_day >> enrollment_year) {
            if (className == "gstudent") {
                inputFile >> supervisorName;
            }

            if (student_id == studentId) {
                Date* BIRTHDATE = new Date(birthmonth, birthday, birthyear);
                Date* ENROLLMENTDATE = new Date(enrollment_month, enrollment_day, enrollment_year);
                Student* STDT;

                if (className == "gstudent") {
                    STDT = new GraduateStudent(supervisorName, name, *BIRTHDATE, *ENROLLMENTDATE);
                }
                else {
                    STDT = new UndergraduateStudent(name, *BIRTHDATE, *ENROLLMENTDATE);
                }

                cout << "\n\nINPUT from the FILE:~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << *STDT << "\n\n\n" << endl;
               /* delete BIRTHDATE;
                delete ENROLLMENTDATE;
                delete STDT;*/
            }

            if (inputFile.eof()) {
                cout << "No students found" << endl;
            }

        }
    }
    catch (exception) {
        cout << "Cannot open the file" << endl;
    }
    inputFile.close();
}



void dataManager::printcourses() const{

    cout << "Courses offered in the current semester:" << endl;
    for (int i = 0; i < coursearray_count; i++) {

        if (coursearray[i] == nullptr)
            break;
        cout << "Course Number: " << coursearray[i]->getCourseNum() << ", Instructor: " << coursearray[i]->getCourseInstructor() << endl;
    }
}


