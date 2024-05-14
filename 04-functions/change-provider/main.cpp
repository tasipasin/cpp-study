/**
 * Problem: Write a program that asks the user to enter an
 * integer representing the number of cents.
 *
 * The number entered must be greater than or equal to zero.
 *
 * The program should then display how to provide the change to user.
 *
 * Using:
 * Money   as 100 cents
 * Quarter as 25 cents
 * Dime    as 10 cents
 * Nickel  as 5 cents
 * Penny   as 1 cent
 *
 * Example:
 * User input:
 *    92
 * Output:
 *    Moneys: 0
 *    Quarters: 3
 *    Dimes: 1
 *    Nickels: 1
 *    Pennies: 2
 * User input:
 *    7411
 * Output:
 *    Moneys: 74
 *    Quarters: 0
 *    Dimes: 1
 *    Nickels: 0
 *    Pennies: 1
 */
#include <iostream>
using namespace std;

// Amount of cents to have a money
#define MONEY 100;
// Amount of cents to have a quarter
#define QUARTER 25;
// Amount of cents to have a dime
#define DIME 10;
// Amount of cents to have a nickel
#define NICKEL 5;

int main()
{
    // Initialize variable that will receive the
    // input from user with the minimum required
    int input_user_cents{ 0 };
    cout << "Input the cents: ";
    // Reads input from user
    cin >> input_user_cents;
    // Checks if user inputs the minimum required
    if(input_user_cents >= 0) {
        // Divides the input by the value of each money
        // to have the required full money
        int money = input_user_cents / MONEY;
        // As the full money has already been taken,
        // remove the full money amount from cents
        input_user_cents %= MONEY;

        // Divides the input by the value of each money
        // to have the required quarters
        int quarter = input_user_cents / QUARTER;
        // As the quarters has already been taken,
        // remove the quarter amount from cents
        input_user_cents %= QUARTER;

        // Divides the input by the value of each money
        // to have the required dimes
        int dime = input_user_cents / DIME;
        // As the quarters has already been taken,
        // remove the dime amount from cents
        input_user_cents %= DIME;

        // Divides the input by the value of each money
        // to have the required nickels
        int nickel = input_user_cents / NICKEL;
        // As the quarters has already been taken,
        // remove the nickel amount from cents
        // which left only the pennies in the cents
        input_user_cents %= NICKEL;

        // Output results
        cout << "Moneys: " << money << endl;
        cout << "Quarters: " << quarter << endl;
        cout << "Dimes: " << dime << endl;
        cout << "Nickels: " << nickel << endl;
        cout << "Pennies: " << input_user_cents << endl;

    } else {
        cout << endl << "Value must be grater or equals than zero" << endl;
    }
    return 0;
}