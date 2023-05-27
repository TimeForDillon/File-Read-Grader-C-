#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

struct Student
{
    string lastName;        // CALC & OUT - student last name
    string firstName;       // CALC & OUT - student first name
    string courseName;      // CALC & OUT - name of class
    int test1Grade;         // CALC & OUT - grade for test 1
    int test2Grade;         // CALC & OUT - grade for test 2
    int finalExamGrade;     // CALC & OUT - grade for final exam
    double testAverage;     // CALC & OUT - avg score

};

/*******************************************************************************
 * formatOutputFile
 * This function takes in an array for struct, the array length, and ref to
 * output file and writes to the file.
 *  - returns nothing.
 ******************************************************************************/

void formatOutputFile(Student studentList[],   // IN - struct array of students
                      int numberOfStudents,    // IN - number of students
                      ofstream &outputFile);   // IN - ref output file

/*******************************************************************************
 * printOutputFile
 * This function takes in an array for struct and the array length and prints
 * out.
 *  - returns nothing.
 ******************************************************************************/

void printOutputFile(Student studentList[],    // IN - struct array of students
                     int numberOfStudents);    // IN - number of students

/*******************************************************************************
 * letterGrade
 * This functions takes in the double grade and returns the corresponding letter
 * grade
 *  - returns char letter grade.
 ******************************************************************************/

char letterGrade(double classAvg);  // IN - double grade

#endif // HEADER_H
