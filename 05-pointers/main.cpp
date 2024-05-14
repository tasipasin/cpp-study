/**
 * Pointers:
 * 1. Pointers are variables so they can change;
 * 2. Pointers can be null (nullptr)
 * 3. Pointers can be unitialized.
 * 4. Using pointer variable with an * (*pointer), it can be used
 *    in the same way as the original variable.
 * 5. Never "Unitialize" a pointer.
 * 6. Assure that all pointer in code references to an address
 *    beeing used and not yet release.
 * 7. Always be sure that 'new' did successfully.
 * 8. Never forget to release allocated memory.
 *
 * When to pass a variable by value: (int a)
 * 1. The variable should NOT be modified by the funtion
 * 2. It's a simple and small variable
 *
 * When to pass a variable by reference using pointer: (int *a)
 * 1. The variable can be modified by the funtion
 * 2. It's a complex/expensive variable (string, lists)
 * 3. It's ok to have nullptr value
 *
 * When to pass a variable by reference using pointer to const: (const int* a)
 * 1. The variable should NOT be modified by the funtion
 * 2. It's a complex/expensive variable (string, lists)
 * 3. It's ok to have nullptr value
 *
 * When to pass a variable by reference using const pointer to const: (const int* const a)
 * 1. The variable should NOT be modified by the funtion
 * 2. It's a complex/expensive variable (string, lists)
 * 3. It's ok to have nullptr value
 * 4. The pointer should NOT be modified
 *
 * When to pass a variable by reference using reference: (int &a)
 * 1. The variable can be modified by the funtion
 * 2. It's a complex/expensive variable (string, lists)
 * 3. It's NOT ok to have nullptr value
 *
 * When to pass a variable by reference using const reference: (const int &a)
 * 1. The variable should NOT be modified by the funtion
 * 2. It's a complex/expensive variable (string, lists)
 * 3. It's NOT ok to have nullptr value
*/
#include <iostream>
#include <string>

using namespace std;

// Returns nothing, but changes the value
void double_entry(int* ptr_to_value_to_double) {
    *ptr_to_value_to_double *= 2;
}

/**
 * Returns the pointer of an item from the array that has
 * the biggest value.
 * @param array Array with mixed and positive values.
 * @param sentinal Stop condition.
 * @return the pointer of an item from the array that has
 * the biggest value.
*/
int* find_biggest_value(int* array, int sentinel) {
    int* biggest{ array++ };
    while (*array != sentinel) {
        if (*array > *biggest) {
            biggest = array;
        }
        array++;
    }
    return biggest;
}

/**
 * Reverse the array content order.
 * @param arr Array to be reversed.
 * @param size Size of the array.
*/
void reverse_array(int* arr, int size) {
    int* start{ arr };
    int* end{ (arr + size - 1) };
    while (start < end)
    {
        int temp{ *start };
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

/**
 * Reverse a string.
 * @param str The String to be reversed.
 * @return The reversed String.
*/
string reverse_string(const string& str) {
    string reversed;
    // Pointer to the first character
    const char* start{ str.c_str() };
    // Pointer to the last character
    const char* end{ str.c_str() + str.size() - 1 };

    while (end >= start) {
        // Append the character at the end pointer to the reversed string
        reversed.push_back(*end);
        end--;
    }
    return reversed;
}

int main() {

    /** Declaring pointers. */
    {
        // int_ptr is a pointer to a integer
        int* int_ptr;
        // double_ptr is a pointer to a double
        double* double_ptr;
        // Doesn't matter where the '*' is
        // Preferable, next to the name
        // These are not initialized, so, like all other non initialized
        // variables, contains garbage
    }

    /** Initializing properly */
    {
        // It's like initializing normal variables.
        int* int_ptr{};
        // If don't initialize a pointer to a variable or function (?)
        // then you should initialize it to nullptr (address zero - pointing to nowhere)
        double* double_ptr{ nullptr };
    }

    /** Accessing Pointer address. */
    {
        cout << "Accessing Pointer address" << endl;
        // "Normal" variable
        int num{ 10 };
        cout << "Display value of num: " << num << endl;
        cout << "Display the address of num: " << &num << endl;

        // Pointer variable
        int* p;
        cout << "Display value of p (garbage): " << p << endl;
        cout << "Display the address of p: " << &p << endl;
        p = nullptr;
        cout << "Display value of p (nullptr): " << p << endl;
        double* dp;
        // The size of the ADDRESS is the same for every type in the
        // same cpu.
        cout << "Size of p (pointer of integer): " << sizeof p << endl;
        cout << "Size of dp (pointer of doule): " << sizeof dp << endl;
    }

    cout << endl;

    /** Storing an Address in Pointer Variable. */
    {
        cout << "Storing an Address in Pointer Variable" << endl;
        int num{ 10 };
        double dob{ 100.7 };
        cout << "num address: " << &num << endl;
        cout << "dob address: " << &dob << endl;
        // It will store only the address of a int
        int* pointer{ nullptr };
        cout << "Display value of p (before): " << pointer << endl;
        pointer = &num;
        cout << "Display value of p (address of num): " << pointer << endl;
        // This will cause an error because the pointer can store
        // the address because the size of the address is the same for
        // both variables (num and dob), but the type of the content
        // at the address is different
        // pointer = &dob; // Will cause Compiler Error
    }

    cout << endl;

    /** Dereferencing a Pointer (accessing the value of the addres is pointing to) */
    {
        cout << "Dereferencing a Pointer (accessing the value of the addres is pointing to)" << endl;
        int num{ 96 };
        cout << "num value: " << num << endl;
        cout << "num address: " << &num << endl;
        // Initialize the pointer with the address of num
        int* pointer{ &num };
        cout << "pointer address (initialized with num address): " << pointer << endl;
        // Use * to acess the value of the address
        cout << "pointer address value: " << *pointer << endl;
        // To change the value of num using pointer, is the same
        *pointer = 91;
        cout << "new pointer address value: " << *pointer << endl;
        cout << "new num value: " << num << endl;
        cout << "num address: " << &num << endl;
        cout << "pointer address: " << pointer << endl;
        // Also, we can change to where the pointer is pointing to
        int year{ 2024 };
        cout << "year value: " << year << endl;
        cout << "year address: " << &year << endl;
        pointer = &year;
        cout << "new pointer address: " << pointer << endl;
        cout << "new pointer address value: " << *pointer << endl;
    }

    cout << endl;

    /** Dynamic Memory Allocation. */
    {
        cout << "Dynamic Memory Allocation" << endl;
        int* all_ptr{ nullptr };
        cout << "New allocated pointer (all_ptr) address: " << all_ptr << endl;
        // Allocates a new integer (no specified value - garbage)
        all_ptr = new int;
        cout << "after allocate all_ptr address: " << all_ptr << endl;
        cout << "after allocate all_ptr value (garbage): " << *all_ptr << endl;
        *all_ptr = 28;
        cout << "after determined all_ptr value: " << *all_ptr << endl;
        // Frees the allocated stored
        delete all_ptr;
    }

    cout << endl;

    /** Arrays and Pointers. */
    {
        cout << "Arrays and Pointers" << endl;
        double stars[]{ 9.8, 8.8, 8.9, 9.0 };
        cout << "stars address: " << &stars << endl;
        double* stars_ptr{ stars };
        // It's the same behavior, because array is just a pointer (address)
        // to the first element of the sequence
        cout << "stars_ptr address: " << stars_ptr << endl;
        cout << "Accessing values of stars from stars_ptr[0]: " << stars_ptr[0] << endl;
        cout << "Accessing values of stars from stars[0]: " << stars[0] << endl;
        cout << "Accessing values of stars from *stars_ptr: " << *stars_ptr << endl;
        cout << "Accessing values of stars from stars_ptr[2]: " << stars_ptr[2] << endl;
        cout << "Accessing values of stars from stars[2]: " << stars[2] << endl;
        cout << "Accessing values of stars from *(stars_ptr+2): " << *(stars_ptr + 2) << endl;
        // We can sum values to the address, so it will sum the amount 
        // of memory address to the next position. We can do the same
        // with the array variable itself
    }

    cout << endl;

    /** Pointer arithmetic */
    {
        cout << "Pointer arithmetic" << endl;
        // All the arithmetic operators that has been previously
        // learned, work for pointer
        cout << "Arrays and Pointers" << endl;
        double stars[]{ 9.8, 8.8, 8.9, 9.0 };
        cout << "stars address: " << &stars << endl;
        double* stars_ptr{ stars };
        cout << "Accesing first element from stars using pointer: " << *stars_ptr << endl;
        // Now we add one more and goes to the next value;
        stars_ptr++;
        cout << "Accesing the next element from stars using pointer (++): " << *stars_ptr << endl;
        // Now we add one more and goes to the next value;
        stars_ptr += 1;
        cout << "Accesing the next element from stars using pointer (+= 1): " << *stars_ptr << endl;

        string first{ "Tasi" };
        string last{ "Pasin" };
        string samefirst{ "Tasi" };

        string* pointer1{ &first };
        string* pointer2{ &last };
        string* pointer3{ &first };
        string* pointer4{ &samefirst };

        cout << "first string addr: " << &first << endl;
        cout << "last string addr: " << &last << endl;
        cout << "samefirst string addr: " << &samefirst << endl;
        cout << "pointer1 addr: " << pointer1 << endl;
        cout << "pointer2 addr: " << pointer2 << endl;
        cout << "pointer3 addr: " << pointer3 << endl;
        cout << "pointer4 addr: " << pointer4 << endl;
        // Option to print string boolean instead 01
        cout << boolalpha;
        cout << "pointer1 == pointer2: " << (pointer1 == pointer2) << endl;
        cout << "pointer1 == pointer3: " << (pointer1 == pointer3) << endl;
        cout << "pointer1 == pointer4: " << (pointer1 == pointer4) << endl;
        cout << "pointer2 == pointer3: " << (pointer2 == pointer3) << endl;
        cout << "pointer2 == pointer4: " << (pointer2 == pointer4) << endl;
        cout << "pointer3 == pointer4: " << (pointer3 == pointer4) << endl;
        cout << "*pointer1 == *pointer4: " << (*pointer1 == *pointer4) << endl;
        cout << "*pointer1 == *pointer3: " << (*pointer1 == *pointer3) << endl;
        cout << "*pointer3 == *pointer4: " << (*pointer3 == *pointer4) << endl;
    }

    cout << endl;

    /** Pointers and consts */
    {
        cout << "Pointers and consts" << endl;
        cout << "Pointers to consts" << endl;
        // Pointers to constants
        int price1{ 2533 };
        int price2{ 59 };
        cout << "price1 value: " << price1 << endl;
        cout << "price1 address: " << &price1 << endl;
        cout << "price2 value: " << price2 << endl;
        cout << "price2 address: " << &price2 << endl;
        const int* best_price{ &price2 };
        cout << "Best price value (before): " << *best_price << endl;
        cout << "Best price address (before): " << best_price << endl;
        // Can't change the value of the best_price
        // *best_price = 42;
        // But can point to another value address
        best_price = &price1;
        cout << "Best price value (after): " << *best_price << endl;
        cout << "Best price address (after): " << best_price << endl;

        cout << "Constant pointers" << endl;
        int* const not_best_price{ &price2 };
        cout << "not_best_price value (before): " << *not_best_price << endl;
        cout << "not_best_price address (before): " << not_best_price << endl;
        cout << "price2 value (before): " << not_best_price << endl;
        // Can't change the address of the not_best_price pointing to
        // not_best_price = &price1;
        // But can change the value
        *not_best_price = 66;
        cout << "not_best_price value (after): " << *not_best_price << endl;
        cout << "not_best_price address (after): " << not_best_price << endl;
        cout << "price2 value (after): " << price2 << endl;

        cout << "Everything is const" << endl;
        const int* const too_much_consts{ &price2 };
        // Can't change address pointing or value
        // too_much_consts = &price1;
        // *too_much_consts = price1;
        cout << "too_much_consts value: " << *too_much_consts << endl;
        cout << "too_much_consts address: " << too_much_consts << endl;
    }

    cout << endl;

    /** Passing functions to a function */
    {
        cout << "Passing functions to a function" << endl;
        int* ptr_to_double = new int{ 5 };
        cout << "ptr_to_double value (before double): " << *ptr_to_double << endl;
        cout << "ptr_to_double address (before double): " << ptr_to_double << endl;
        // Pass the pointer, change the original value, returns nothing, keep same address
        double_entry(ptr_to_double);
        cout << "ptr_to_double value (after double): " << *ptr_to_double << endl;
        cout << "ptr_to_double address (after double): " << ptr_to_double << endl;

        int value_to_double{ 512 };
        cout << "value_to_double value (before double): " << value_to_double << endl;
        cout << "value_to_double address (before double): " << &value_to_double << endl;
        // Pass the pointer, change the original value, returns nothing, keep same address
        double_entry(&value_to_double);
        cout << "value_to_double value (after double): " << value_to_double << endl;
        cout << "value_to_double address (after double): " << &value_to_double << endl;
    }

    cout << endl;

    /** Returning pointer from a function. */
    {
        cout << "Returning pointer from a function" << endl;
        int values[]{ 1,5,2,4,9,5,-1 };
        // Pass the array (or the first value address of the array)
        // and a indicator of the end
        // It returns which address inside this array has the biggest value
        int* biggest_value{ find_biggest_value(values, -1) };
        cout << "biggest_value address " << biggest_value << endl;
        cout << "biggest_value value " << *biggest_value << endl;
        // Using arithmetics, we can determinate which position it is
        int position = biggest_value - values;
        cout << "biggest_value is at position " << position << endl;
        cout << "value in position " << position << ": " << values[position] << endl;
    }

    cout << endl;

    /** Reverse array exercise */
    {
        cout << "Reverse array exercise" << endl << endl;
        int arr[] = { 1, 2, 3, 4 };
        int size = sizeof(arr) / sizeof(arr[0]);
        cout << "Array before reverse function: ";
        for (auto item : arr) {
            cout << item << " ";
        }
        cout << endl;
        reverse_array(arr, size);
        cout << "Array after reverse function: ";
        for (auto item : arr) {
            cout << item << " ";
        }
        cout << endl;
    }

    cout << endl;

    /** Reverse string exercise */
    {
        cout << "Reverse string exercise" << endl;
        string input = "Hello, World!";
        cout << "String before reverse function: " << input << endl;
        string reversed = reverse_string(input);
        cout << "Reversed: " << reversed << endl;
    }

    cout << endl;

    /** References. */
    {
        cout << "References" << endl;
        int num{ 100 };
        int& ref{ num };
        cout << "num value: " << num << endl;
        cout << "ref value: " << ref << endl;
        cout << "num address: " << &num << endl;
        cout << "ref address: " << &ref << endl;
        num = 200;
        cout << "num changed value using num: " << num << endl;
        cout << "ref changed value using num: " << ref << endl;
        ref = 300;
        cout << "num changed value using ref: " << num << endl;
        cout << "ref changed value using ref: " << ref << endl;
    }
    return 0;
}