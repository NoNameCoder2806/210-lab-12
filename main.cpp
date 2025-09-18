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
using namespace std;

// Constants
const int ARRAY_SIZE = 50;
const int SMALL_ARRAY_SIZE = 5;

// Function prototypes
void fileInput(array<double, ARRAY_SIZE>& gpaArray, string path);

template <size_t N>
void displayArray(const array<double, N>& gpaArray);

void findElement(array<double, ARRAY_SIZE>& gpaArray, double targetGPA);

// Main
int main()
{
    // Declare an array to store double gpa data
    array<double, ARRAY_SIZE> gpaArray;

    // Output the address to the console
    cout << " - Address of the array: " << gpaArray.data() << endl;

    // Check whether the current array is empty
    cout << " - Empty?: ";
    if (gpaArray.empty())
    {
        cout << "True!" << endl;
    }
    else
    {
        cout << "False!" << endl;
    }

    // Read the data from the file
    fileInput(gpaArray, "data.txt");

    // Print the current size
    cout << " - Array size: " << gpaArray.size() << endl;
    cout << endl;
    
    // Display all the gpa in the array
    cout << "Original array: ";
    displayArray(gpaArray);
    cout << endl;

    // Display the first and last element of the array
    cout << " - First element: " << gpaArray.front() << endl;
    cout << " - Last element: " << gpaArray.back() << endl;
    cout << endl;

    // Sort the array
    sort(gpaArray.begin(), gpaArray.end());

    // Display the sorted array
    cout << "Sorted array: ";
    displayArray(gpaArray);
    cout << endl;

    // Declare a few GPA scores to search for
    double target1 = 2.25;
    double target2 = 2.5;
    double target3 = 2.75;
    double target4 = 3.0;

    array<double, ARRAY_SIZE>::iterator it;

    // Check whether they are in the array or not
    findElement(gpaArray, target1);
    findElement(gpaArray, target2);
    findElement(gpaArray, target3);
    findElement(gpaArray, target4);

    // Find the min, max, and average GPA score of the Student objects
    cout << " - Highest GPA: " << *max_element(gpaArray.begin(), gpaArray.end()) << endl;
    cout << " - Lowest GPA: " << *min_element(gpaArray.begin(), gpaArray.end()) << endl;
    cout << " - Average GPA: " << accumulate(gpaArray.rbegin(), gpaArray.rend(), 0.0) / gpaArray.size() << endl;
    cout << endl;

    // Create 2 empty arrays
    array<double, SMALL_ARRAY_SIZE> fours;
    array<double, SMALL_ARRAY_SIZE> twos;

    // Fill the Student objects into the array
    fours.fill(4.0);
    twos.fill(2.0);

    // Display the 2 arrays
    cout << "Array of Fours: ";
    displayArray(fours);
    cout << "Array of Twos: ";
    displayArray(twos);
    cout << endl;

    // Swap the 2 arrays
    fours.swap(twos);
    cout << " --- The 2 arrays are swapped! --- " << endl;

    // Display the 2 arrays again
    cout << "Array of Fours: ";
    displayArray(fours);
    cout << "Array of Twos: ";
    displayArray(twos);
    cout << endl;

    return 0;
}

// Function implementations
/*
    fileInput()
    Add new gpa from a file
    Arguments: 
        - gpaArray: reference to the std::array<double, ARRAY_SIZE> that will store the data
        - path: path to the data file
    Returns: none
*/
void fileInput(array<double, ARRAY_SIZE>& gpaArray, string path)
{
    // Create a file stream and read the file
    ifstream fin;
    fin.open(path);

    // Exit the function if the file fails to open
    if (!fin.is_open()) {
        cerr << "Error: Unable to open file: " << path << endl;
        return;
    }

    // Declare a string variable to store the line
    double value = 0.0;

    // Fill the array with 0.0 before reading
    gpaArray.fill(value);

    // Iterate through the file and read the data line by line
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        // Read the value
        fin >> value;

        // Add the value into the array
        gpaArray.at(i) = value;
    }
}

/*
    displayArray()
    Display the data of the gpa (double type) in the array
    Arguments:
        - gpaArray: const reference to the std::array<double, ARRAY_SIZE> containing gpa values
    Returns: none
*/
template <size_t N>
void displayArray(const array<double, N>& gpaArray)
{
    // Iterate through the array
    for (int i = 0; i < N; i++)
    {
        // Display the fields
        cout << gpaArray[i];

        // Add a comma and a space if this is not the last element
        if (i != N - 1)
        {
            cout << ", ";
        }
    }

    // Enter a new line
    cout << endl;
}

/*
    findElement()
    Search the gpaArray for a specific gpa.
    Arguments:
        - gpaArray: reference to the std::array<double, ARRAY_SIZE> containing the gpa
        - targetGPA: the GPA value to search for
    Returns:
        - none (prints search results to the console)
*/
void findElement(array<double, ARRAY_SIZE>& gpaArray, double targetGPA)
{
    // Display a message to notify the user of the element being searched
    cout << " --- Searching for: " << targetGPA << " --- " << endl;

    // Declare an iterator to point to the found element
    array<double, ARRAY_SIZE>::iterator it;
    it = find(gpaArray.begin(), gpaArray.end(), targetGPA);
    
    // Check whether the iterator points to an element or not
    if (it != gpaArray.end())
    {
        // Displaying a message
        cout << "Element found! Position: " << it - gpaArray.begin() << endl;
    }
    else
    {
        // Displaying a message
        cout << "Element not found!" << endl;
    }

    // Enter a new line
    cout << endl;
}