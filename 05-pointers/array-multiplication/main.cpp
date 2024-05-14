/**
 * Pointers Challenge:
 * 1. Create a function to print an array. This function should expect the
 *    pointer to the array and it's size.
 * 2. Then, create a function that multiply two arrays: each item of an array with all
 *    the items of the other, resulting in a array with the multiplication of the
 *    two array sizes.
*/

#include<iostream>

using namespace std;

void print_array(const int* arr, const int size) {
    for (int pos{ 0 }; pos < size; pos++) {
        cout << *arr++ << " ";
    }
    cout << endl;
}

int* multiply(const int* const arr1, const int size_arr1, const int* const arr2, const int size_arr2) {
    // Address to the first integer of the array
    // Allocates all the positions
    int* result{ new int[size_arr1 * size_arr2] };
    int size_result{ 0 };
    for (int pos_arr1{ 0 }; pos_arr1 < size_arr1; pos_arr1++) {
        for (int pos_arr2{ 0 }; pos_arr2 < size_arr2; pos_arr2++) {
            result[size_result++] = arr1[pos_arr1] * arr2[pos_arr2];
        }
    }
    return result;
}

int main() {
    // Defines first array and prints it
    int array1[]{ 1,2,3,4,5 };
    int size_array1{ 5 };
    cout << "Array 1 with size " << size_array1 << ": " << endl;
    print_array(array1, size_array1);
    // Defines second array and prints it
    int array2[]{ 10,20,30 };
    int size_array2{ 3 };
    cout << "Array 2 with size " << size_array2 << ": " << endl;
    print_array(array2, size_array2);
    int* result = multiply(array1, size_array1, array2, size_array2);
    int size_result_array{ size_array1 * size_array2 };
    cout << "Result array with size " << size_result_array << ": " << endl;
    print_array(result, size_result_array);
    delete[] result;
    return 0;
}