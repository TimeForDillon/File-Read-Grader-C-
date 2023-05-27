#include "header.h"


/*******************************************************************************
 * formatOutputFile
 * _____________________________________________________________________________
 * This function takes in an array for struct, the array length, and ref to
 * output file and writes to the file.
 *  - returns nothing.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      studentList[]   : This is an array of Student structs
 *      numberOfStudents: This is an int value with the length of the array
 *      &outputFile     : ofstream variable to write to
 *
 * POST-CONDITIONS
 *      N/A. This function writes to an output txt file.
 ******************************************************************************/

void formatOutputFile(Student studentList[],   // IN - struct array of students
                      int numberOfStudents,    // IN - number of students
                      ofstream &outputFile)    // IN - ref output file
{
    int classSize;      // CALC - counter for avg grade
    double classAvg;    // CALC - sum of grades for avg class grade

    classAvg = 0;
    classSize = 0;

    // OUTPUT - writing to output file formatted class information
    outputFile << "Student Grade Summary\n";
    outputFile << "---------------------\n" << endl << endl;
    outputFile << "ENGLISH CLASS\n" << endl;
    outputFile << "Student Name                         Test Avg     Grade\n";
    outputFile << "---------------------------------"
                  "-------------------------------\n";
    // PROCESSING - go through array and look for all students in english class
    for(int i = 0;i < numberOfStudents;i++)
    {
        // PROCESSING - if student is in english class
        if(studentList[i].courseName == "E")
        {
            classSize++;
            // OUTPUT - students last and first name
            outputFile << studentList[i].lastName << ", "
                       << studentList[i].firstName;
            // PROCESSING - output propper spacing
            for(int j = 0;(j < 40 -
               (studentList[i].lastName.length() +
                studentList[i].firstName.length() + 2)); j++)
            {
                outputFile << " ";
            }
            // OUTPUT - output grades with correct decimal numbers
            outputFile << fixed << setprecision(2) << studentList[i].testAverage;
            for(int k = 0;k < 7;k++)
            {
                outputFile << " ";
            }
            classAvg += studentList[i].testAverage;
            // letterGrade - takes in grade number returns letter grade
            outputFile << letterGrade(studentList[i].testAverage) << endl;
        }
    }
    // OUTPUT - formatting and class avg
    outputFile << endl;
    outputFile << "Class Average                           "
         <<fixed<<setprecision(2)<<(classAvg/classSize);
    for(int k = 0;k < 7;k++)
    {
        outputFile << " ";
    }
    // letterGrade - takes in grade number returns letter grade
    outputFile << letterGrade(classAvg/classSize);
    classAvg = 0;
    classSize = 0;
    outputFile << endl;
    outputFile << "----------------------------------------------------------------\n";
    outputFile << "HISTORY CLASS\n" << endl;
    outputFile << "Student Name                         Test Avg     Grade\n";
    outputFile << "----------------------------------------------------------------\n";
    // PROCESSING - go through array and look for all students in history class
    for(int i = 0;i < numberOfStudents;i++)
    {
        // PROCESSING - if student is in history class
        if(studentList[i].courseName == "H")
        {
            classSize++;
            // OUTPUT - students last and first name
            outputFile << studentList[i].lastName << ", "
                       << studentList[i].firstName;
            // PROCESSING - output propper spacing
            for(int j = 0;(j < 40 -
               (studentList[i].lastName.length() +
                studentList[i].firstName.length() + 2)); j++)
            {
                outputFile << " ";
            }
            // OUTPUT - output grades with correct decimal numbers
            outputFile << fixed << setprecision(2) << studentList[i].testAverage;
            for(int k = 0;k < 7;k++)
            {
                outputFile << " ";
            }
            classAvg+=studentList[i].testAverage;
            // letterGrade - takes in grade number returns letter grade
            outputFile << letterGrade(studentList[i].testAverage) << endl;
        }
    }
    // OUTPUT - formatting and class avg
    outputFile << endl;
    outputFile << "Class Average                           "
         <<fixed<<setprecision(2)<<(classAvg/classSize);
    for(int k = 0;k < 7;k++)
    {
        outputFile << " ";
    }
    // letterGrade - takes in grade number returns letter grade
    outputFile << letterGrade(classAvg/classSize);
    classAvg = 0;
    classSize = 0;
    outputFile << endl;
    outputFile << "----------------------------------------------------------------\n";
    outputFile << "MATH CLASS\n" << endl;
    outputFile << "Student Name                         Test Avg     Grade\n";
    outputFile << "----------------------------------------------------------------\n";
    // PROCESSING - go through array and look for all students in math class
    for(int i = 0;i < numberOfStudents;i++)
    {
        // PROCESSING - if student is in english class
        if(studentList[i].courseName == "M")
        {
            classSize++;
            // OUTPUT - students last and first name
            outputFile << studentList[i].lastName << ", "
                       << studentList[i].firstName;
            // PROCESSING - output propper spacing
            for(int j = 0;(j < 40 -
               (studentList[i].lastName.length() +
                studentList[i].firstName.length() + 2)); j++)
            {
                outputFile << " ";
            }
            // OUTPUT - output grades with correct decimal numbers
            outputFile << fixed << setprecision(2) << studentList[i].testAverage;
            for(int k = 0;k < 7;k++)
            {
                outputFile << " ";
            }
            classAvg+=studentList[i].testAverage;
            // letterGrade - takes in grade number returns letter grade
            outputFile << letterGrade(studentList[i].testAverage) << endl;
        }
    }
    // OUTPUT - formatting and class avg
    outputFile << endl;
    outputFile << "Class Average                           "
         <<fixed<<setprecision(2)<<(classAvg/classSize);
    for(int k = 0;k < 7;k++)
    {
        outputFile << " ";
    }
    // letterGrade - takes in grade number returns letter grade
    outputFile << letterGrade(classAvg/classSize);
    classAvg = 0;
    classSize = 0;
    outputFile << endl;
    outputFile << "----------------------------------------------------------------\n";
}

/*******************************************************************************
 * printOutputFile
 * _____________________________________________________________________________
 * This function takes in an array for struct and the array length and prints
 * out.
 *  - returns nothing.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      studentList[]   : Array of student structs
 *      numberOfStudents: lenght of array
 *
 * POST-CONDITIONS
 *      N/A. Prints out class info.
 ******************************************************************************/

void printOutputFile(Student studentList[],   // IN - struct array of students
                     int numberOfStudents)    // IN - number of students
{
    int classSize;      // CALC - counter for avg grade
    double classAvg;    // CALC - sum of grades for avg class grade

    classAvg = 0;
    classSize = 0;

    // OUTPUT - writing to output file formatted class information
    cout << "Student Grade Summary\n";
    cout << "---------------------\n" << endl << endl;
    cout << "ENGLISH CLASS\n" << endl;
    cout << "Student Name                         Test Avg     Grade\n";
    cout << "----------------------------------------------------------------\n";
    // PROCESSING - go through array and look for all students in english class
    for(int i = 0;i < numberOfStudents;i++)
    {
        // PROCESSING - if student is in english class
        if(studentList[i].courseName == "E")
        {
            classSize++;
            // OUTPUT - students last and first name
            cout << studentList[i].lastName << ", "
                       << studentList[i].firstName;
            // PROCESSING - output propper spacing
            for(int j = 0;(j < 40 -
               (studentList[i].lastName.length() +
                studentList[i].firstName.length() + 2)); j++)
            {
                cout << " ";
            }
            // OUTPUT - output grades with correct decimal numbers
            cout << fixed << setprecision(2) << studentList[i].testAverage;
            for(int k = 0;k < 7;k++)
            {
                cout << " ";
            }
            classAvg+=studentList[i].testAverage;
            // letterGrade - takes in grade number returns letter grade
            cout << letterGrade(studentList[i].testAverage) << endl;
        }
    }
    // OUTPUT - formatting and class avg
    cout << endl;
    cout << "Class Average                           "
         <<fixed<<setprecision(2)<<(classAvg/classSize);
    for(int k = 0;k < 7;k++)
    {
        cout << " ";
    }
    // letterGrade - takes in grade number returns letter grade
    cout << letterGrade(classAvg/classSize);
    classAvg = 0;
    classSize = 0;
    cout << endl;
    cout << "----------------------------------------------------------------\n";
    cout << "HISTORY CLASS\n" << endl;
    cout << "Student Name                         Test Avg     Grade\n";
    cout << "----------------------------------------------------------------\n";
    // PROCESSING - go through array and look for all students in history class
    for(int i = 0;i < numberOfStudents;i++)
    {
        // PROCESSING - if student is in history class
        if(studentList[i].courseName == "H")
        {
            classSize++;
            // OUTPUT - students last and first name
            cout << studentList[i].lastName << ", "
                       << studentList[i].firstName;
            // PROCESSING - output propper spacing
            for(int j = 0;(j < 40 -
               (studentList[i].lastName.length() +
                studentList[i].firstName.length() + 2)); j++)
            {
                cout << " ";
            }
            // OUTPUT - output grades with correct decimal numbers
            cout << fixed << setprecision(2) << studentList[i].testAverage;
            for(int k = 0;k < 7;k++)
            {
                cout << " ";
            }
            classAvg += studentList[i].testAverage;
            // letterGrade - takes in grade number returns letter grade
            cout << letterGrade(studentList[i].testAverage) << endl;
        }
    }
    // OUTPUT - formatting and class avg
    cout << endl;
    cout << "Class Average                           "
         <<fixed<<setprecision(2)<<(classAvg/classSize);
    for(int k = 0;k < 7;k++)
    {
        cout << " ";
    }
    // letterGrade - takes in grade number returns letter grade
    cout << letterGrade(classAvg/classSize);
    classAvg = 0;
    classSize = 0;
    cout << endl;
    cout << "----------------------------------------------------------------\n";
    cout << "MATH CLASS\n" << endl;
    cout << "Student Name                         Test Avg     Grade\n";
    cout << "----------------------------------------------------------------\n";
    // PROCESSING - go through array and look for all students in math class
    for(int i = 0;i < numberOfStudents;i++)
    {
        // PROCESSING - if student is in math class
        if(studentList[i].courseName == "M")
        {
            classSize++;
            // OUTPUT - students last and first name
            cout << studentList[i].lastName << ", "
                       << studentList[i].firstName;
            // PROCESSING - output propper spacing
            for(int j = 0;(j < 40 -
               (studentList[i].lastName.length() +
                studentList[i].firstName.length() + 2)); j++)
            {
                cout << " ";
            }
            // OUTPUT - output grades with correct decimal numbers
            cout << fixed << setprecision(2) << studentList[i].testAverage;
            for(int k = 0;k < 7;k++)
            {
                cout << " ";
            }
            classAvg+=studentList[i].testAverage;
            // letterGrade - takes in grade number returns letter grade
            cout << letterGrade(studentList[i].testAverage) << endl;
        }
    }
    // OUTPUT - formatting and class avg
    cout << endl;
    cout << "Class Average                           "
         <<fixed<<setprecision(2)<<(classAvg/classSize);
    for(int k = 0;k < 7;k++)
    {
        cout << " ";
    }
    // letterGrade - takes in grade number returns letter grade
    cout << letterGrade(classAvg/classSize);
    classAvg = 0;
    classSize = 0;
    cout << endl;
    cout << "----------------------------------------------------------------\n";
}

/*******************************************************************************
* letterGrade
* _____________________________________________________________________________
* This functions takes in the double grade and returns the corresponding letter
* grade
*  - returns char letter grade.
* _____________________________________________________________________________
* PRE-CONDITIONS
*  The following need previously define values:
*       classAvg: Class average grade.
*
* POST-CONDITIONS
*       returns the letter grade as a char.
******************************************************************************/

char letterGrade(double classAvg)   // IN - double grade
{
    if(classAvg <= 100 && classAvg >= 90) return 'A';
    else if(classAvg < 90 && classAvg >= 80) return 'B';
    else if(classAvg < 80 && classAvg >= 70) return 'C';
    else if(classAvg < 70 && classAvg >= 60) return 'D';
    else return 'F';
}
