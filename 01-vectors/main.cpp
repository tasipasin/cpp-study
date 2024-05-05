/**
 * A study about C++ vectors.
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Declare 2 empty vectors of integers
    vector<int> vector1;
    vector<int> vector2;
    // Add 10 and 20 to vector1
    vector1.push_back(10);
    vector1.push_back(20);
    // Display the elements in vector1 using at() method;
    for (int pos{ 0 }; pos < static_cast<int>(vector1.size()); pos++) {
        cout << vector1.at(pos) << " ";
    }
    // Display the size of vector1
    cout << "\nVector1 size: " << vector1.size() << endl;

    // Add 100 and 200 to vector2
    vector2.push_back(100);
    vector2.push_back(200);
    // Display the elements in vector1 using at() method;
    for (int pos{ 0 }; pos < static_cast<int>(vector2.size()); pos++) {
        cout << vector2.at(pos) << " ";
    }
    // Display the size of vector1
    cout << "\nVector2 size: " << vector2.size() << endl;

    // Declare an empty 2D vector
    vector<vector<int>> vector_2d;
    // Adds vector1 and vector2 dynamically to vector_2d
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    // Display the elements in vector_2d in grid
    for (int row{ 0 }; row < static_cast<int>(vector_2d.size()); row++) {
        for (int column = 0; column < (int)vector_2d.at(row).size(); column++) {
            cout << vector_2d.at(row).at(column) << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Change vector1[0] to 1000
    vector1.at(0) = 1000;

    // Display the elements in vector_2d in grid
    for (int row{ 0 }; row < static_cast<int>(vector_2d.size()); row++) {
        for (int column = 0; column < (int)vector_2d.at(row).size(); column++) {
            cout << vector_2d.at(row).at(column) << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Display the elements in vector1 using at() method;
    for (int pos{ 0 }; pos < static_cast<int>(vector1.size()); pos++) {
        cout << vector1.at(pos) << " ";
    }
    return 0;
}