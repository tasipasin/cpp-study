#include <iostream>

#include "DerivedException.hpp"
#include "DivisionByZeroException.hpp"
#include "NegativeValueException.hpp"

using namespace std;

double calculate_avg(int sum, int total) {
    if (total == 0) {
        throw 0;
    }
    return static_cast<double>(sum) / total;
}

double calculate_avg_multiple_exceptions(int sum, int total) {
    if (total == 0) {
        throw 0;
    }
    if (sum < 0 || total < 0) {
        throw string{ "Negative value error" };
    }
    return static_cast<double>(sum) / total;
}

double calculate_avg_custom_exceptions(int sum, int total) {
    if (total == 0) {
        throw DivisionByZeroException();
    }
    if (sum < 0 || total < 0) {
        throw NegativeValueException();
    }
    return static_cast<double>(sum) / total;
}

int main() {
    {
        cout << "[Simple Exception Handling]" << endl;
        double average{};

        // To read input from user
        // int sum, total{};
        // cout << "Input sum: ";
        // cin >> sum;
        // cout << "Input total: ";
        // cin >> total;

        int sum{ 15 };
        int total{ 0 };
        try {
            // Inside the "try" block, runs the code that
            // might throws an Exception

            if (total == 0) {
                // The best practice is throw by value and catch by reference *******
                throw 0;
            }

            average = static_cast<double>(sum) / total;
            cout << "Average: " << average << endl;
        }
        catch (int& ex) {
            // The "catch" block of code captures any exception thrown
            // by the try block and deals with it
            cerr << "Can't divide by zero" << endl;
        }

        // [Throw in function]
        try {
            average = calculate_avg(sum, total);
            cout << "Average (function): " << average << endl;
        }
        catch (int& ex) {
            // The "catch" block of code captures any exception thrown
            // by the try block and deals with it
            cerr << "Can't divide by zero (function)" << endl;
        }
    }

    cout << endl;

    // Multiple Exception Handling
    {
        cout << "[Multiple Exception Handling]" << endl;
        int sum{ 15 };
        int total{ -1 };
        try {
            calculate_avg_multiple_exceptions(sum, total);
        }
        catch (int& ex1) {
            cerr << "Can't divide by zero (function)" << endl;
        }
        catch (string& ex2) {
            cerr << ex2 << endl;
        }
        catch (...) {
            // This is a catch all exception
            // Won't be possible to access the object being thrown
            // but can deal with it
            cerr << "Unknown Expetion" << endl;
        }
    }

    cout << endl;

    // User-defined Exception
    {
        cout << "[User-Defined Exception]" << endl;
        int sum{ 15 };
        int total{ -1 };
        try {
            calculate_avg_custom_exceptions(sum, total);
        }
        catch (const DivisionByZeroException& ex1) {
            cerr << "Can't divide by zero (function)" << endl;
        }
        catch (const NegativeValueException& ex2) {
            cerr << "Negative value error" << endl;
        }
        catch (...) {
            // This is a catch all exception
            // Won't be possible to access the object being thrown
            // but can deal with it
            cerr << "Unknown Expetion" << endl;
        }
    }

    cout << endl;

    // Class-level Exceptions
    {
        cout << "[Class-level Exceptions]" << endl;

        // -- Methods --
        // Exceptions work in methods the way seemed before

        // -- Constructor --
        // Constructor may fail
        // Construtors do not return any value
        // An exception is thrown by the constructor if an object cannot be
        // initialized

        // -- Destructor --
        // NO!
        try {
            throw DerivedException();
        }
        catch (const DerivedException& ex) {
            cerr << ex.what() << endl;
        }
    }
    return 0;
}
