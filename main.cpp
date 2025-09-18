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
const int SMALL_ARRAY_SIZE = 5;
const int NAME_FIELD = 30;
const int GPA_FIELD = 5;

// Function prototypes
void fileInput(array<Student, ARRAY_SIZE>& studentArray, string path);

void displayHeader();

template <size_t N>
void displayArray(const array<Student, N>& studentArray);

bool ascCompareGPA(const Student& student1, const Student& student2);

bool desCompareGPA(const Student& student1, const Student& student2);

void sortGPA(array<Student, ARRAY_SIZE>& studentArray);

double addGPA(double sum, const Student& student);

bool hasGPA(const Student& student, double targetGPA);

void findElement(array<Student, ARRAY_SIZE>& studentArray, double targetGPA);

// Main
int main()
{
    // Declare an array to store Student objects data
    array<Student, ARRAY_SIZE> studentArray;

    // Output the address to the console
    cout << " - Address of the array: " << studentArray.data() << endl;

    // Check whether the current array is empty
    cout << " - Empty?: ";
    if (studentArray.empty())
    {
        cout << "True!" << endl;
    }
    else
    {
        cout << "False!" << endl;
    }

    // Read the data from the file
    fileInput(studentArray, "data.txt");

    // Print the current size
    cout << " - Array size: " << studentArray.size() << endl;
    
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

    // Sort the array by gpa
    sortGPA(studentArray);

    // Display a message
    cout << "Sorted Array: " << endl;

    // Display the sorted array
    displayHeader();
    displayArray(studentArray);

    // Declare a few GPA scores to search for
    double target1 = 2.25;
    double target2 = 2.5;
    double target3 = 2.75;
    double target4 = 3.0;

    // Check whether they are in the array or not
    findElement(studentArray, target1);
    findElement(studentArray, target2);
    findElement(studentArray, target3);
    findElement(studentArray, target4);

    // Find the min, max, and average GPA score of the Student objects
    cout << " - Highest GPA: " << max_element(studentArray.begin(), studentArray.end(), ascCompareGPA)->gpa << endl;
    cout << " - Lowest GPA: " << min_element(studentArray.begin(), studentArray.end(), ascCompareGPA)->gpa << endl;
    cout << " - Average GPA: " << accumulate(studentArray.rbegin(), studentArray.rend(), 0.0, addGPA) / studentArray.size() << endl;
    cout << endl;

    // Create 2 empty arrays
    array<Student, SMALL_ARRAY_SIZE> fours;
    array<Student, SMALL_ARRAY_SIZE> twos;

    // Create 2 Student objects to fill into the array
    Student student1;      // First Student object
    student1.name = "Perfect GPA";
    student1.gpa = 4.0;

    Student student2;      // Second Student object
    student2.name = "Low GPA";
    student2.gpa = 2.0;

    // Fill the Student objects into the array
    fours.fill(student1);
    twos.fill(student2);

    // Display the 2 arrays
    cout << "Fours: " << endl;
    displayHeader();
    displayArray(fours);

    cout << "Twos: " << endl;
    displayHeader();
    displayArray(twos);

    // Swap the 2 arrays
    fours.swap(twos);
    cout << " --- The 2 arrays are swapped! --- " << endl;

    // Display the 2 arrays again
    cout << "Fours: " << endl;
    displayHeader();
    displayArray(fours);

    cout << "Twos: " << endl;
    displayHeader();
    displayArray(twos);

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

    // Exit the function if the file fails to open
    if (!fin.is_open()) {
        cerr << "Error: Unable to open file: " << path << endl;
        return;
    }

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
        studentArray.at(count) = temp;
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
template <size_t N>
void displayArray(const array<Student, N>& studentArray)
{
    // Iterate through the array
    for (int i = 0; i < N; i++)
    {
        // Display the fields
        cout << left << setw(NAME_FIELD) << studentArray[i].name;
        cout << left << setw(GPA_FIELD) << studentArray[i].gpa;

        // Enter a new line
        cout << endl;
    }

    // Enter a new line
    cout << endl;
}

/*
    ascCompareGPA()
    Compare the GPA of two Student objects.
    Arguments:
        - student1: const reference to a Student
        - student2: const reference to a Student
    Returns:
        - true if student1's GPA is less than student2's GPA (for descending order)
        - false otherwise
*/
bool ascCompareGPA(const Student& student1, const Student& student2)
{
    return student1.gpa < student2.gpa;    // Ascending order
}

/*
    desCompareGPA()
    Compare the GPA of two Student objects.
    Arguments:
        - student1: const reference to a Student
        - student2: const reference to a Student
    Returns:
        - true if student1's GPA is greater than student2's GPA (for descending order)
        - false otherwise
*/
bool desCompareGPA(const Student& student1, const Student& student2)
{
    return student1.gpa > student2.gpa;    // Descending order
}

/*
    sortGPA()
    Sort the data of the array in descending order based on the GPA
    Arguments:
        - studentArray: const reference to the std::array<Student, ARRAY_SIZE> containing students
    Returns: none
*/
void sortGPA(array<Student, ARRAY_SIZE>& studentArray)
{
    // Use the sort() function to sort the array
    sort(studentArray.begin(), studentArray.end(), desCompareGPA);
}

/*
    addGPA()
    Helper function for accumulate: adds a Student's GPA to the running sum
    Arguments:
        - sum: the current accumulated GPA total
        - student: const reference to a Student object
    Returns: the new sum after adding the student's GPA
*/
double addGPA(double sum, const Student& student)
{
    return sum + student.gpa;
}

/*
    hasGPA()
    Helper function to check if a Student's GPA matches a target value.
    Arguments:
        - student: const reference to a Student object to check
        - targetGPA: the GPA value to compare against
    Returns:
        - true if the Student's GPA equals the target, false otherwise
*/
bool hasGPA(const Student& student, double targetGPA)
{
    return student.gpa == targetGPA;    // Check whether the Student's gpa = target
}

/*
    findElement()
    Search the student array for a Student with a specific GPA.
    Arguments:
        - studentArray: reference to the std::array<Student, ARRAY_SIZE> containing the students
        - targetGPA: the GPA value to search for
    Returns:
        - none (prints search results to the console)
*/
void findElement(array<Student, ARRAY_SIZE>& studentArray, double targetGPA)
{
    // Display a message to notify the user of the element being searched
    cout << " --- Searching for: " << targetGPA << " --- " << endl;

    // Declare an iterator to point to the found element
    array<Student, ARRAY_SIZE>::iterator it;
    it = find_if(studentArray.begin(), studentArray.end(), [targetGPA](const Student& s) { return hasGPA(s, targetGPA); });
    
    // Check whether the iterator points to an element or not
    if (it != studentArray.end())
    {
        // Displaying a message
        cout << "Element found! Position: " << it - studentArray.begin() << endl;
    }
    else
    {
        // Displaying a message
        cout << "Element not found!" << endl;
    }

    // Enter a new line
    cout << endl;
}