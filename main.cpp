// COMSC-210 | Lab 12 | Dat Hoang Vien
// IDE used: Visual Code Studio

// Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include "Student.h"
using namespace std;

// Constants
const int ARRAY_SIZE = 100;

// Function prototypes
void fileInput(string path);

// Main
int main()
{
    // Declare an array to store Student objects data
    array<Student, ARRAY_SIZE>;

    return 0;
}

// Function implementations
/*
    fileInput()
    Add new Student objects from a file
    Arguments: the path to the data file
    Returns: none
*/
void fileInput(string path)
{
    // Create a file stream and read the file
    ifstream fin;
    fin.open(path);

    // Declare a string variable to store the line
    string line;

    // Iterate through the file and read the data line by line
    while (getline(fin, line))
    {
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
    }
}