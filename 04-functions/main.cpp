#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/** Function Prototypes */

/** Math problems */
double calc_area_circle(double);
void area_circle();
double calc_volume_cylinder(double radius, double height);
void volume_cylinder();

/** Passing by value */
void pass_by_value1(int num);
void pass_by_value2(string s);

/** Default argument values */
double calc_cost(double base_cost, double tax_rate = 0.06);

/** Functions overloading (polymorphism) */
void display(int value);
void display(string value);
void display(double value);

/** Passing arrays */
void print_array(int numbers[], size_t size);
void change_array(int numbers[], size_t size, int plus = 5);
void cant_change_array(const int numbers[], size_t size);

/** Passing by reference */
void scale_number(int& num);
void print_vector(vector<int>& v);
void print_vector_non_change(const vector<int>& v);

/** Static local scope */
void static_local_scope();

/** Inline Function */
// Inline functions are simpler functions. Defining them as
// intline avoids call stacks and are executed faster, like it has
// been written, well, inline
inline int add_numbers(int a, int b) { return a + b; }

/** Global scope variable */
// Pi definition
const double pi{ 3.14159 };

int main()
{
    /** Math problems */
    {
        cout << "\nMath problems" << endl;
        area_circle();
        volume_cylinder();
    }

    /** Passing by value */
    {
        cout << "\nPassing arguments by value" << endl;
        int num{ 10 };
        cout << "Value of num before function pass_by_value1(int): " << num << endl;
        pass_by_value1(num);
        // Should display the same value because num is passed as
        // a copy to the function
        cout << "Value of num after function: " << num << endl;
        string name{ "Tasi" };
        cout << "Value of name before function pass_by_value2(string): " << name << endl;
        pass_by_value2(name);
        // Should display the same value because name is passed as
        // a copy to the function
        cout << "Value of name after function pass_by_value2(string): " << name << endl;
    }

    /** Default argument values */ {
        cout << "\nDefault argument values" << endl;
        int base_cost{ 100 };
        cout << "Cost with a base cost of " << base_cost << " at default tax rate: " << calc_cost(base_cost) << endl;
        double tax_rate{ 0.1 };
        cout << "Cost with a base cost of " << base_cost << " at " << tax_rate << " tax rate: " << calc_cost(base_cost, tax_rate) << endl;
    }

    /** Functions overloading (polymorphism) */
    {
        cout << endl
            << "Overloading Functions" << endl;
        display(12);
        display('A');    // char is interpreted as int
        display("Tasi"); // C-style string is converted to C++ string
        display(55.5);
    }

    /** Passing arrays */
    {
        cout << endl
            << "Passing arrays" << endl;
        // To pass an array to a function we can use [] in the formal description
        // The elements are NOT copied, but the address from the first element
        // is copied. The function don't know how many elements the array has
        // so we should inform it.
        int number_arrays[]{ 1, 2, 3, 4, 5 };
        print_array(number_arrays, 5);
        // But since we pass the address, we can modify the array inside function
        change_array(number_arrays, 5);
        print_array(number_arrays, 5);
        // To avoid changing the array, the function should define the
        // array parameter as const
        cant_change_array(number_arrays, 5); // This will result in compiler error
        print_array(number_arrays, 5);
    }

    /** Passing by reference (Can change the origin value)*/
    {
        cout << "\nPassing by reference" << endl;
        int number1{ 54 };
        cout << "number1 before calling function scale_number: " << number1 << endl;
        scale_number(number1);
        cout << "number1 after calling function scale_number: " << number1 << endl;
        int number2{ 112 };
        cout << "number2 before calling function scale_number: " << number2 << endl;
        scale_number(number2);
        cout << "number2 after calling function scale_number: " << number2 << endl;
        vector<int> data{ 5, 6, 4, 3, 1 };
        print_vector(data);
        print_vector_non_change(data);
    }

    /** Static local scope */
    {
        cout << "\nStatic local scope" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Iteration: " << i + 1 << endl;
            static_local_scope();
            cout << endl;
        }
    }

    /** Inline Functions */
    {
        cout << "\nInline Functions" << endl;
        int a{ 10 };
        int b{ 20 };
        cout << "The sum of a and b are: " << add_numbers(a, b) << endl;
    }
    return 0;
}

/**
 * Math problems
 */

double calc_area_circle(double radius)
// Receiving a copy of radius
{
    return pi * pow(radius, 2);
}

void area_circle()
{
    double radius{};
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    cout << "The area of a circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

// Receiving a copy of radius and height
double calc_volume_cylinder(double radius, double height)
{
    return calc_area_circle(radius) * height;
}

void volume_cylinder()
{
    double radius{};
    double height{};
    cout << "\nEnter the radius of the cylinder: ";
    cin >> radius;
    cout << "\nEnter the height of the cylinder: ";
    cin >> height;
    cout << "The volume of a cylinder with radius " << radius << " and height " << height
        << " is: " << calc_volume_cylinder(radius, height) << endl;
}

/**
 * Passing by value
 */

void pass_by_value1(int num)
{
    num = 1000; // Do not change the origin
}

void pass_by_value2(string s)
{
    s = "Changed"; // Do not change the origin
}

/**
 * Default argument values
 */

double calc_cost(double base_cost, double tax_rate)
// Default tax_rate is informed in prototype
{
    return base_cost * (1.0 + tax_rate);
}

/**
 * Functions overloading (polymorphism)
 */
void display(int value) { cout << "Displaying int value: " << value << endl; }
void display(string value) { cout << "Displaying string value: " << value << endl; }
void display(double value) { cout << "Displaying double value: " << value << endl; }

/**
 * Passing arrays
 */
void print_array(int numbers[], size_t size)
{
    cout << "Printing array of " << size << " elements" << endl;
    for (size_t pos{ 0 }; pos < size; pos++)
    {
        cout << numbers[pos] << " ";
    }
    cout << endl;
}

void change_array(int numbers[], size_t size, int plus)
{
    cout << "Changing array of " << size << " elements adding " << plus << endl;
    for (size_t pos{ 0 }; pos < size; pos++)
    {
        numbers[pos] += plus;
    }
}

void cant_change_array(const int numbers[], size_t size)
{
    int plus{ 5 };
    cout << "Try to change array of " << size << " elements adding " << plus << endl;
    for (size_t pos{ 0 }; pos < size; pos++)
    {
        // numbers[pos] += plus; // This will cause compiler error
        // it won't even run
    }
}

/**
 * Passing by reference
 */
void scale_number(int& num)
{
    if (num < 100)
    {
        // This will change the origin value
        num *= 10;
    }
}

void print_vector(vector<int>& v)
{
    // Here the vector will be passed by reference and could
    // be changed
    for (auto value : v)
    {
        cout << value << " ";
    }
    cout << endl;
}

void print_vector_non_change(const vector<int>& v)
{
    // Here the vector will be passed by reference but is defined as const
    // Trying to change any element from v will cause compiler error
    for (auto value : v)
    {
        cout << value << " ";
    }
    cout << endl;
}

/**
 * Static local scope
 */
void static_local_scope()
{
    // Retains it value between calls
    static int numeral{ 50 };
    cout << "Before: " << numeral << endl;
    numeral *= 4;
    cout << "After: " << numeral << endl;
}