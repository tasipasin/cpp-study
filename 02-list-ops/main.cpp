/**
 * Problem: Using a collection of integers and allow the user to
 * select options from a menu to perform operations on the list.
 *
 * Menu Options:
 * P - Print numbers
 * A - Add a number (at the end)
 * M - Display mean of the numbers
 * S - Display the smallest number
 * L - Display the largest number
 * Q - Quit
 *
 * The program should accept lower and upper case select options.
 * If the user input an unknown option, should display "Unknown
 * selection, please try again".
 *
 * ==============================================================
 *
 * Selected 'P' (or 'p') option:
 * If the list is empty, should display "[] - the list is empty".
 * Otherwise, should display inside square brackets separated by space.
 * Example:
 *     [ 1 2 3 4 5 ]
 *
 * ==============================================================
 *
 * Selected 'A' (or 'a') option:
 * Prompt the user for a integer to add to the list. After adding
 * the number, should display "x added", as 'x' is the user entry.
 * Example:
 * User input: 88
 * Output    : 88 added
 *
 * ==============================================================
 *
 * Selected 'M' (or 'm') option:
 * Calculate the means of the elements in list and display it.
 * If the list is empty, display "Unable to calculate the mean -
 * no data".
 * Example:
 * List content: [1,2,3,4,5]
 * Output      : Mean is 5
 *
 * List content: [] (empty)
 * Output      : Unable to calculate the mean - no data
 *
 * ==============================================================
 *
 * Selected 'S' (or 's') option:
 * Display the smallest element in the list.
 * If the list is empty, display "Unable to deteminate the smallest
 * number - no data".
 * Example:
 * List content: [5,33,61,0,5]
 * Output      : The smallest number is 0
 *
 * List content: []
 * Output      : Unable to deteminate the smallest number - no data
 *
 * ==============================================================
 *
 * Selected 'L' (or 'l') option:
 * Display the largest element in the list.
 * If the list is empty, display "Unable to deteminate the largest
 * number - no data".
 * Example:
 * List content: [5,33,61,0,5]
 * Output      : The largest number is 61
 *
 * List content: []
 * Output      : Unable to deteminate the smallest number - no data
 *
 * ==============================================================
 *
 * Selected 'Q' (or 'q') option:
 * Display "Goodbye" and the program terminates
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Prints all the elements in the vector.
 */
void printAllElements();

/**
 * Resquest a element to insert from user and inserts in the vector.
 */
void addElement();

/**
 * Calculates and displays the mean value of the elements in the vector
 */
void calculateMean();

/**
 * Searches and displays the smallest element in the vector.
 */
void displaySmallest();

/**
 * Searches and displays the largest element in the vector.
 */
void displayLargest();

/** Vector to be manipulated. */
vector<int> vec{};

int main()
{
    // Keeps program running until user says to quit
    bool terminate = false;
    do {
        // Print menu options
        cout << "Menu Options:" << endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number (at the end)" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "Enter your choice: ";
        // Read user options
        char user_option;
        cin >> user_option;
        // Select the option the user entered
        switch (user_option) {
            // Print all elements options
        case 'p':
        case 'P':
            printAllElements();
            break;
            // Add element options
        case 'a':
        case 'A':
            addElement();
            break;
            // Calculate mean options
        case 'm':
        case 'M':
            calculateMean();
            break;
            // Display smallest number options
        case 's':
        case 'S':
            displaySmallest();
            break;
            // Display largest number options
        case 'l':
        case 'L':
            displayLargest();
            break;
            // Terminates the program options
        case 'q':
        case 'Q':
            terminate = true;
            cout << "Goodbye";
            break;
            // User entry do not fits any other options
        default:
            cout << "Unknown selection, please try again" << endl;
            break;
        }
        cout << "===========================================" << endl;
    } while (!terminate);
    return 0;
}

void printAllElements()
{
    // Check if the vector is empty and print message saying so
    if (vec.empty()) {
        cout << "[] - the list is empty" << endl;
    }
    else {
        cout << "[ ";
        // Iterate over the elements of the vector displaying them
        for (auto item : vec) {
            cout << item << " ";
        }
        cout << "]";
    }
}

void addElement()
{
    // Take input from user
    cout << "Type the number to add to the list: ";
    int user_number_input{ 0 };
    cin >> user_number_input;
    // Insert the user input inside the vector
    vec.push_back(user_number_input);
    // Shows user the number input
    cout << user_number_input << " added" << endl;
}

void calculateMean()
{
    // Check if the vector is empty and print message saying so
    if (vec.empty()) {
        cout << "Unable to calculate the mean - no data" << endl;
    }
    else {
        int sum_of_items{ 0 };
        // Sum all the elements in the vector
        for (auto item : vec) {
            sum_of_items += item;
        }
        // Display user the mean of elements
        cout << "Mean is " << sum_of_items / static_cast<int>(vec.size()) << endl;
    }
}

void displaySmallest()
{
    // Check if the vector is empty and print message saying so
    if (vec.empty()) {
        cout << "Unable to deteminate the smallest number - no data" << endl;
    }
    else {
        // Selects the first element as the smallest. This way
        // I don't have to assume any other value and end up causing
        // a wrong output. Could've use INT_MAX as well.
        int smallest{ vec.at(0) };
        // Iterate over all elements checking if it's smaller than
        // the current smallest value. If so, changes the smallest
        // value to the new one
        for (auto item : vec) {
            if (item < smallest) {
                smallest = item;
            }
        }
        // Displays to user the smallest number
        cout << "The smallest number is " << smallest << endl;
    }
}

void displayLargest()
{
    // Check if the vector is empty and print message saying so
    if (vec.empty()) {
        cout << "Unable to deteminate the largest number - no data" << endl;
    }
    else {
        // Selects the first element as the largest. This way
        // I don't have to assume any other value and end up causing
        // a wrong output. Could've use INT_MIN as well.
        int largest{ vec.at(0) };
        // Iterate over all elements checking if it's larger than
        // the current largest value. If so, changes the largest
        // value to the new one
        for (auto item : vec) {
            if (item > largest) {
                largest = item;
            }
        }
        // Displays to user the largest number
        cout << "The largest number is " << largest << endl;
    }
}