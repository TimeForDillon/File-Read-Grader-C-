/*******************************************************************************
 * AUTHOR        : Dillon Welsh
 * ASSIGNMENT 2  : STUDENT RECORDS
 * CLASS         : CS3A
 * SECTION       : 71206
 * DUE DATE      : 09/10/2020
 ******************************************************************************/

#include "header.h"
#include "functions.cpp"

/*******************************************************************************
 * STUDENT RECORDS
 *______________________________________________________________________________
 * You will write a program that reads and stores student data from an input
 * file, computes and stores each student's test average, then prints a report
 * to an output file, along with class averages.
 *______________________________________________________________________________
 * INPUT:
 *  int numberOfStudents : extracted from input file
 *  string inputFileName : user input for input file name
 *  string outputFileName: user input for output file name
 *  string tempInput     : extracted from input file
 *
 * OUTPUT:
 *  Student *studentList : struct holding extracted student info for output
 ******************************************************************************/

int main()
{
    int numberOfStudents;       // INPUT - number of students
    int count;                  // CALC - iterator
    string inputFileName;       // INPUT - input file name
    string outputFileName;      // INPUT - ouput file name
    string tempInput;           // INPUT - from input file to conver to int
    ifstream inputFile;         // CALC - txt file to extract from
    ofstream outputFile;        // CALC & OUT - txt file to write to
    Student *studentList;       // CALC & OUT - for dynamic struct array

    // INPUT - user enters input file name and output file name
    do
    {
        cout << "Please enter the name of the input file.\n";
        cout << "Filename: \n";
        getline(cin,inputFileName);
        // PROCESSING - user must enter correct file name
    }while((inputFileName != "test1.txt") && (inputFileName != "test2.txt"));
        cout << endl;
        cout << "Please enter the name of the output file.\n";
        cout << "Filename: \n";
        getline(cin,outputFileName);

    // PROCESSING - initialize fstream variables to open files
    inputFile.open(inputFileName.c_str());
    outputFile.open(outputFileName.c_str());

    // PROCESSING - if files dont open
    if(inputFile.fail() || outputFile.fail())
    {
        cout << "Error.\n";
    }
    // PROCESSING - if files open
    else
    {
        // PROCESSING - collect number of students
        getline(inputFile,tempInput);
        stringstream convert(tempInput);
        convert >> numberOfStudents;
        // PROCESSING - dynamic array
        studentList = new Student[numberOfStudents];
        // PROCESSING - execute up to end of file
        // PROCESSING - extract information line by line
        for(count = 0;count < numberOfStudents;count++)
        {
            getline(inputFile,studentList[count].lastName,',');
            getline(inputFile,studentList[count].firstName,',');
            getline(inputFile,studentList[count].courseName,',');
            inputFile >> studentList[count].test1Grade;
            inputFile.ignore();
            inputFile >> studentList[count].test2Grade;
            inputFile.ignore();
            inputFile >> studentList[count].finalExamGrade;
            inputFile.ignore();
            // PROCESSING - calculates test average for each student
            studentList[count].testAverage =
                    (double(studentList[count].test1Grade)*0.30) +
                    (double(studentList[count].test2Grade)*0.30) +
                    (double(studentList[count].finalExamGrade)*0.40);
        }
        cout << "Processing Complete\n\n";
        // formatOutputFile - writes to output file
        formatOutputFile(studentList,numberOfStudents,outputFile);
        // printOutputFile - prints out output file
        printOutputFile(studentList,numberOfStudents);

        //PROCESSING - clean up
        inputFile.close();
        outputFile.close();
        delete[] studentList;
    }

    return 0;
}
