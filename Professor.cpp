
#include "Date.h"
#include "Professor.h"
#include <iostream>
using namespace std;


Professor::Professor() {
    employee_id = 0;
}

Professor::Professor( const string name, const Date birthdate, const Date enrollment_date) 
    : Person(name, birthdate) {

    static int next_employee_id = 100;  // Starting student_id
    employee_id = next_employee_id++;

    this->employment_date = employment_date;

}

Professor::~Professor() {
    cout << "Professor object destroyed." << endl;
}
void Professor::set_employment_date(Date employment_date) {

    this->employment_date = employment_date;
};

Date Professor::get_employment_date() const { 

    return this->employment_date;
}

int Professor::getId() const { 

    return this->employee_id;
}

void Professor::print() const { 

    Person::print();
    cout << "Professor id is : " << this->employee_id <<"   Employment date :" ;
    employment_date.printDate();
    cout << "-----------------------------------------------------------------------" << endl;
    cout << endl;
   
    /*this->get_employment_date().printDate();*/
}
