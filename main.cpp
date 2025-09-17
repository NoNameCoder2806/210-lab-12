// COMSC-210 | Lab 12 | Dat Hoang Vien
// IDE used: Visual Code Studio

// Libraries
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <array>
#include "Student.h"
using namespace std;

// Constants
const int ARRAY_SIZE = 100;
const int NAME_FIELD = 30;
const int GPA_FIELD = 5;

// Function prototypes
void fileInput(array<Student, ARRAY_SIZE>& studentArray, string path, int& count);

void displayArray(const array<Student, ARRAY_SIZE>& studentArray, const int count);

// Main
int main()
{
    // Declare an array to store Student objects data
    array<Student, ARRAY_SIZE> studentArray;
    int count = 0;      // Store the total number of Student objects in the array

    // Read the data from the 2 files
    fileInput(studentArray, "data1.txt", count);
    fileInput(studentArray, "data2.txt", count);

    // Print the current size
    cout << "Current size: " << count << endl;
    
    // Display all the Student objects in the array
    displayArray(studentArray, count);

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
void fileInput(array<Student, ARRAY_SIZE>& studentArray, string path, int& count)
{
    // Create a file stream and read the file
    ifstream fin;
    fin.open(path);

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
    displayArray()
    Display the data of the Student objects in the array
    Arguments: an array 
    Returns: none
*/
void displayArray(const array<Student, ARRAY_SIZE>& studentArray, const int count)
{
    for (int i = 0; i < count; i++)
    {
        // Display the fields
        cout << left << setw(NAME_FIELD) << studentArray[i].name;
        cout << left << setw(GPA_FIELD) << studentArray[i].gpa;

        // Enter a new line
        cout << endl;
    }
}