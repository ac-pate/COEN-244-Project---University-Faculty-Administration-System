#ifndef DATAMANAGER_H
#define DATAMANAGER


#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include "FullTimeProfessor.h"
#include "PartTimeProfessor.h"
#include "CourseRegistration.h"
#include "Course.h"
#include "Grade.h"
#include <iostream>
using namespace std;


class dataManager {
private:
    Student* student[2300];
    Professor* professor[50];
    CourseRegistration* coursearray[50];

    int ugstudent_count;
    int gstudent_count;
    int ftprofessor_count;
    int ptprofessor_count;
    int coursearray_count;

public:
    dataManager();
    virtual ~dataManager();

    bool insert(UndergraduateStudent*);
    bool insert(GraduateStudent*);
    bool insert(FullTimeProfessor*);
    bool insert(PartTimeProfessor*);
    bool insert(CourseRegistration*);

    bool registering_to_Course(Student*, Course&);

    bool dropping_a_Course(Student*, Course&);

    void studentCourses(Student*);

    void printCourseInfo(Course&) const;

    bool graduateSupervisor(FullTimeProfessor&, GraduateStudent&);

    void printProfessorInfo(FullTimeProfessor*) ;

    int  getTotal();

    void save(string);
    void read(int);

    void printcourses() const;
};

#endif