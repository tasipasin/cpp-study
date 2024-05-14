/**
 * Problem: Swap the values of the pointers.
*/

#include <iostream>

using namespace std;

void swapPointers(int* ptr1, int* ptr2) {
    int temp{ *ptr1 };
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    /** Swaping pointers value. */
    {
        int* first_ptr = new int{ 1996 };
        int* second_ptr = new int{ 2024 };
        cout << "Before swapping: " << endl;
        cout << "first value: " << *first_ptr << endl;
        cout << "first addr: " << first_ptr << endl;
        cout << "second value: " << *second_ptr << endl;
        cout << "second addr: " << second_ptr << endl;
        swapPointers(first_ptr, second_ptr);
        cout << "After swapping: " << endl;
        cout << "first value: " << *first_ptr << endl;
        cout << "first addr: " << first_ptr << endl;
        cout << "second value: " << *second_ptr << endl;
        cout << "second addr: " << second_ptr << endl;
    }

    cout << endl;

    /** Swapping values.*/
    {
        int first_value{ 1996 };
        int second_value{ 2024 };
        cout << "Before swapping: " << endl;
        cout << "first value: " << first_value << endl;
        cout << "first addr: " << &first_value << endl;
        cout << "second value: " << second_value << endl;
        cout << "second addr: " << &second_value << endl;
        // sending the addresses
        swapPointers(&first_value, &second_value);
        cout << "After swapping: " << endl;
        cout << "first value: " << first_value << endl;
        cout << "first addr: " << &first_value << endl;
        cout << "second value: " << second_value << endl;
        cout << "second addr: " << &second_value << endl;
    }
    return 0;
}