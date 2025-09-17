// COMSC-210 | Lab 12 | Dat Hoang Vien
// IDE used: Visual Code Studio

// Libraries
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>  // for sort(), find()
#include <numeric>    // for accumulate()
#include <string>
#include <array>
#include "Student.h"
using namespace std;

// Constants
const int ARRAY_SIZE = 50;
const int NAME_FIELD = 30;
const int GPA_FIELD = 5;

// Function prototypes
void fileInput(array<Student, ARRAY_SIZE>& studentArray, string path);

void displayHeader();

void displayArray(const array<Student, ARRAY_SIZE>& studentArray);

// Main
int main()
{
    // Declare an array to store Student objects data
    array<Student, ARRAY_SIZE> studentArray;

    // Read the data from the file
    fileInput(studentArray, "data.txt");

    // Print the current size
    cout << "Array size: " << studentArray.size() << endl;
    
    // Display all the Student objects in the array
    displayHeader();
    displayArray(studentArray);

    // Display the first Student object of the array
    cout << " --- First Student: --- " << endl;
    cout << "Name: " << studentArray.front().name << endl;
    cout << "GPA: " << studentArray.front().gpa << endl;
    cout << endl;

    // Display the last Student object of the array
    cout << " --- Last Student: --- " << endl;
    cout << "Name: " << studentArray.back().name << endl; 
    cout << "GPA: " << studentArray.back().gpa << endl;
    cout << endl;

    return 0;
}

// Function implementations
/*
    fileInput()
    Add new Student objects from a file
    Arguments: 
        - studentArray: reference to the std::array<Student, ARRAY_SIZE> that will store the data
        - path: path to the data file
        - count: reference to an int tracking how many slots are currently used
    Returns: none
*/
void fileInput(array<Student, ARRAY_SIZE>& studentArray, string path)
{
    // Create a file stream and read the file
    ifstream fin;
    fin.open(path);

    // Declare a count variable to keep track of the array
    int count = 0;

    // Declare a string variable to store the line
    string line;

    // Iterate through the file and read the data line by line
    while (getline(fin, line))
    {
        // Create a temporary Student object
        Student temp;

        // Declare 2 variables to store the name and gpa
        string name;
        double gpa;

        // Iterate through the string
        for (int i = 0; i < line.size(); i++)
        {
            // If the current character is a number
            if (line.at(i) >= '0' && line.at(i) <= '9')
            {
                // Save the name and gpa
                name = line.substr(0, i - 1);
                gpa = stod(line.substr(i));

                // Break out of the line loop
                break;
            }
        }

        // Assign the values to the temporary Student object
        temp.name = name;
        temp.gpa = gpa;

        // Add the object into the array
        studentArray[count] = temp;
        count++;      // Increment the count
    }
}

/*
    displayHeader()
    Display a header for the data console display
    Arguments: none
    Returns: none
*/
void displayHeader()
{
    // Display a header
    cout << left << setw(NAME_FIELD) << "Student Name";
    cout << left << setw(GPA_FIELD) << "GPA";
    cout << endl;

    // Display a separator
    cout << string(NAME_FIELD + GPA_FIELD, '=') << endl;
}

/*
    displayArray()
    Display the data of the Student objects in the array
    Arguments:
        - studentArray: const reference to the std::array<Student, ARRAY_SIZE> containing students
        - count: number of students currently in the array
    Returns: none
*/
void displayArray(const array<Student, ARRAY_SIZE>& studentArray)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        // Display the fields
        cout << left << setw(NAME_FIELD) << studentArray[i].name;
        cout << left << setw(GPA_FIELD) << studentArray[i].gpa;

        // Enter a new line
        cout << endl;
    }
}