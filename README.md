# COEN 244 Project - University Faculty Manager

## Overview
This project implements a university faculty management system using various object-oriented programming (OOP) concepts in C++.

### Project Structure
- `dataManager.h`: Header file containing the `dataManager` class declaration.
- `dataManager.cpp`: Implementation file for the `dataManager` class.
- `main.cpp`: Main program file demonstrating the usage of the implemented classes.
- `PartTimeProfessor.h`, `FullTimeProfessor.h`, `GraduateStudent.h`, `UndergraduateStudent.h`: Header files for specific classes representing different roles within the university.
- `CourseRegistration.h`, `Course.h`, `Grade.h`: Header files for classes related to courses, course registration, and grades.
- `Person.h`, `Date.h`: Header files for base classes representing individuals and dates.

### OOP Concepts Implemented
1. **Inheritance**: Utilized to create specialized classes such as `UndergraduateStudent`, `GraduateStudent`, `FullTimeProfessor`, and `PartTimeProfessor` inheriting from a base `Person` class.
2. **Encapsulation**: Used private member variables and member functions to encapsulate data within classes.
3. **Polymorphism**: Employed virtual functions and pure virtual functions for dynamic method dispatch.
4. **Operator Overloading**: Overloaded output stream (`<<`) operator for custom output of class objects.
5. **Input/Output Handling**: Demonstrated advanced input/output operations, including reading from and writing to text files.
6. **Constructor and Destructor**: Utilized constructors and destructors for object initialization and cleanup.
7. **Exception Handling**: Implemented advanced exception handling using try-catch blocks for error management.

### Assignment Progression
- **Assignment 1**: Preliminary classes (`Date`, `Person`, `Student`, `Professor`) with inheritance and encapsulation.
- **Assignment 2**: Added more classes (`Course`, `CourseRegistration`) and implemented constructors, destructors, and virtual functions.
- **Assignment 3**: Introduced `Grade` class and implemented polymorphism with virtual and pure virtual functions.
- **Assignment 4**: Utilized operator overloading and advanced exception handling techniques.
- **Assignment 5**: Demonstrated advanced input/output operations by reading data from a text file and writing formatted data to another output text file.

### Usage
- Compile the project files and execute `main.cpp` to run the program.
- The program demonstrates various functionalities such as student registration, course management, grading, and file I/O operations.

### Note
- Ensure proper memory management by deleting dynamically allocated objects using `delete` operator.

