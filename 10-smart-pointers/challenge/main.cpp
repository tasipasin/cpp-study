#include <iostream>
#include <memory>
#include <vector>
#include "Test.hpp"

using namespace std;

// Function prototypes
/**
 * Makes the unique pointer to the vector of shared pointer of Test.
 * @return the unique pointer to the vector of shared pointer of Test.
 */
unique_ptr<vector<shared_ptr<Test>>> make();

/**
 * Fills the vector with objects.
 * @param vec Vector to be filled.
 * @param num Quantity of items to put at the vector.
 */
void fill(vector<shared_ptr<Test>>& vec, int num);

/**
 * Displays all the values of the vector.
 * @param vec Vector filled with values.
 */
void display(const vector<shared_ptr<Test>>& vec);

int main() {
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    cout << "How many data points do you want to enter: ";
    int num;
    cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}

unique_ptr<vector<shared_ptr<Test>>> make() {
    return make_unique<vector<shared_ptr<Test>>>();
}

void fill(vector<shared_ptr<Test>>& vec, int num) {
    // Iterate until max value
    for (int pos = 0; pos < num; pos++) {
        int value_to_new_object;
        cout << "Enter data point [" << (pos + 1) << "] : ";
        // Read a number value from user
        cin >> value_to_new_object;
        // Create an shared reference Test object
        // and inserts on the vector
        vec.push_back(make_shared<Test>(value_to_new_object));
    }
}

void display(const vector<shared_ptr<Test>>& vec) {
    cout << "Displaying vector data" << endl;
    cout << "=======================" << endl;
    for (const auto& item : vec) {
        cout << item->get_data() << endl;
    }
    cout << "=======================" << endl;
}