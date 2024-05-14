/**
 * Study about do-while.
 * Problem: From a given vector, return the first vowel appearence.
 * When a vowel is found, display: "Vowel found: vowel".
 * When no vowel could be found in the vector, display:
 * "No vowel was found".
 *
 * This solution covers only lowercase letters.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Finds the first vowel in the given vector.
 * @param vec Vector with letters.
 */
void find_first_vowel(const vector<char>& vec)
{
    // Flow control variables initialization
    char charAt;
    int pos{ 0 };
    bool vowelFound{ false };
    do {
        // Check is there is still positions in vector to analyse
        if(pos < static_cast<int>(vec.size())) {
            // Gets letter from position
            charAt = vec.at(pos);
            // Check if it vowel
            vowelFound = charAt == 'a' || charAt == 'e' || charAt == 'i' || charAt == 'o' || charAt == 'u';
            // Jump to next position
            pos++;
        }
        // Checks if the flow could terminate
    } while(!vowelFound && pos < static_cast<int>(vec.size()));
    // Checks which message should be displayed
    if(vowelFound) {
        cout << "Vowel found: " << charAt;
    } else {
        cout << "No vowel was found";
    }
}

int main()
{
    // Initialize vector
    vector<char> vec{ 'a', 'p', 'p' };
    // Invokes funtion to find first vowel
    find_first_vowel(vec);
    return 0;
}
