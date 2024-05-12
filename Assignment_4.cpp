#include "dataManager.h"
#include <iostream>
using namespace std;


int main() {




        Date* D1 = new Date(3, 15, 2001);   //month-day-year
        Date* D2 = new Date(5, 20, 2011);
        UndergraduateStudent* student0 = new UndergraduateStudent("John", *D1, *D2);   //name,enrol date,birthday
        UndergraduateStudent* student1 = new UndergraduateStudent("Jane", *D2, *D1);

        GraduateStudent* gradStudent0 = new GraduateStudent("Prof1", "Graduate01", *D1, *D2);        ////supivisor, name,enrol date,birthday
        GraduateStudent* gradStudent1 = new GraduateStudent("Prof1", "Graduate02", *D2, *D1);

        FullTimeProfessor* fullTimeProf1 = new FullTimeProfessor("Prof1", *D1, *D2);
        PartTimeProfessor* partTimeProf1 = new PartTimeProfessor("Prof2", *D2, *D1);


        Course* course1 = new Course(101, "Mathematics", "MathematicsProf");
        fullTimeProf1->insertCourse(*course1);
        CourseRegistration* regCourse1 = new CourseRegistration(*course1);

        Course* course2 = new Course(571, "Computer Science", "ComputerScienceProf");
        partTimeProf1->insertCourse(*course2);
        CourseRegistration* regCourse2 = new CourseRegistration(*course2);

        Course* course3 = new Course(102, "Physics", "PhysicsProf");
        partTimeProf1->insertCourse(*course3);
        CourseRegistration* regCourse3 = new CourseRegistration(*course3);

        Course* course4 = new Course(103, "Chemistry", "ChemistryProf");
        fullTimeProf1->insertCourse(*course4);
        CourseRegistration* regCourse4 = new CourseRegistration(*course4);

        Course* course5 = new Course(104, "Biology", "BiologyProf");
        CourseRegistration* regCourse5 = new CourseRegistration(*course5);

        Course* course6 = new Course(105, "History", "N/A");
        CourseRegistration* regCourse6 = new CourseRegistration(*course6);

        Course* course7 = new Course(106, "English", "EnglishProf");
        partTimeProf1->insertCourse(*course7);
        CourseRegistration* regCourse7 = new CourseRegistration(*course7);

        dataManager* manager1 = new dataManager();

        cout << "\n\nDriver Test Beginning " << endl;
        cout << "******************************************************************************************" << endl<<endl;
       
        if (manager1->insert(student0))
            cout << "Student Inserted: " << student0->getStudentName() << endl;
        else
            cout << "Failed to insert student." << endl;
        if (manager1->insert(student1))
            cout << "Student Inserted: " << student1->getStudentName() << endl;
        else
            cout << "Failed to insert student." << endl;
        if (manager1->insert(regCourse1))
            cout << "Course Inserted: " << regCourse1->getCourseNum() << endl;
        else
            cout << "Failed to insert course." << endl;
        if (manager1->registering_to_Course(student0, *course1))
            cout << "Student Registered to Course." << endl;
        else
            cout << "Failed to register course." << endl;

        if (manager1->insert(gradStudent0))
            cout << "Graduate Student 0 inserted." << endl;
        if (manager1->insert(gradStudent1))
            cout << "Graduate Student 1 inserted." << endl;

        cout << "Inserting courses to data Manager." << endl ;
        manager1->insert(regCourse2);
        manager1->insert(regCourse3);
        manager1->insert(regCourse4);
        manager1->insert(regCourse5);
        manager1->insert(regCourse6);
        manager1->insert(regCourse7);

        manager1->insert(fullTimeProf1);
        manager1->insert(partTimeProf1);

        manager1->registering_to_Course(student0, *course3);
        if (manager1->registering_to_Course(student0, *course3))
            cout << "Student Registered to Course." << endl;
        else
            cout << "Failed to register course." << endl;
        manager1->registering_to_Course(student0, *course4);
        manager1->registering_to_Course(student0, *course5);
        manager1->registering_to_Course(student0, *course6);
        manager1->registering_to_Course(student0, *course7);
        manager1->registering_to_Course(student1, *course1);
        manager1->registering_to_Course(student1, *course2);
        manager1->registering_to_Course(gradStudent0, *course2);


        if (manager1->registering_to_Course(gradStudent0, *course2))
            cout << "Registering Course for Graduate Students." << endl;

        manager1->registering_to_Course(gradStudent1, *course2);

        manager1->studentCourses(gradStudent0);

        if (manager1->dropping_a_Course(student0, *course1))
            cout << "John dropped a course." << endl << endl;
            cout << "John also failed a course." << endl;
            student0->setGrade(course5, "F");

            manager1->studentCourses(student0);
      
        gradStudent0->setGrade(course2, "A");
        gradStudent1->setGrade(course2, "B");
        cout << "--------------------------------------------------------------" << endl;

        cout << "Course info on Graduate Student 1." << endl;
        manager1->studentCourses(gradStudent1);
        cout << "--------------------------------------------------------------" << endl;

        cout << "Info on Full-Time Professor 1." << endl;
        manager1->printProfessorInfo(fullTimeProf1);
        cout << "--------------------------------------------------------------" << endl;

        cout << "Printing all courses." << endl;
        manager1->printcourses();
        cout <<endl << endl << endl << endl << endl;

        cout << "~~~~~~~~~~~~~~~~~~~~[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[ ASSIGNMENT 5 ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl << endl;
        
        cout << *D1 << endl;
        cout << *student0 << endl; 

        manager1->getTotal();
        cout << "-------------------------------------------------------------- " << endl << endl << endl;

        manager1->save("StudentFile.txt");
        manager1->read(1001);
        manager1->read(1002);


        cout << endl << endl << endl << endl << endl << endl << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Terminating Program~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << endl << endl << endl << endl << endl << endl << endl;

        //delete all objects.
        delete manager1;
        delete regCourse1;
        delete regCourse2;
        delete regCourse3;
        delete regCourse4;
        delete regCourse5;
        delete regCourse6;
        delete regCourse7;
        delete course1;
        delete course2;
        delete course3;
        delete course4;
        delete course5;
        delete course6;
        delete course7;
        delete gradStudent0;
        delete gradStudent1;
        delete student0;
        delete student1;
//        delete fullTimeProf1;
        //delete partTimeProf1;
        delete D1;
        delete D2;
        return 0;
    }


    //Date date0;
    //Date* D1 = new Date(3, 15, 2001);   //month-day-year
    //Date* D2 = new Date(5, 20, 2011);

    //UndergraduateStudent* s0 = new UndergraduateStudent("John", *D1, *D2);

    //Person* p0 = s0;

    //

    //   cout << date0 << endl;
    //   cout << *p0 ;
    //   cout << *s0 << endl;
