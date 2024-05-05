#include <cstring> // C-style string library
#include <iostream>
#include <string> // C++ string library

using namespace std;

int main()
{
    // C-style Strings section
    char first_name_ts[]{ "Tasi" };
    char last_name_ts[]{ "Pasin" };
    char whole_name[50]{};
    size_t first_name_length = strlen(first_name_ts);
    size_t last_name_length = strlen(last_name_ts);
    strcpy(whole_name, first_name_ts);
    strcat(whole_name, last_name_ts);
    size_t whole_name_length = strlen(whole_name);
    cout << "The length of the first name, " << first_name_ts << ", is " << first_name_length
        << " letters long and the length of the last name, " << last_name_ts << ", is " << last_name_length
        << " letters long. This means that the length of the whole name must be " << whole_name_length
        << " letters long." << endl;

    cout << endl;

    // ==============================================

    // C++ Strings section (Objects)

    // Initializations
    string s1; // Empty
    cout << "s1: " << s1 << endl;
    string s2{ "String" }; // String
    cout << "s2: " << s2 << endl;
    // Copy string
    string s3{ s2 }; // String;
    cout << "s3: " << s3 << endl;
    // Initialize with the given string until the size cap
    string s4{ "String", 2 }; // St
    cout << "s4: " << s4 << endl;
    // Initialize with the given string inside the indexes
    string s5{ s3, 1, 3 }; // tri
    cout << "s5: " << s5 << endl;
    // Initialize string with the amount of the char
    string s6(3, 'Z'); // ZZZ
    cout << "s6: " << s6 << endl;

    // Changes the second letter
    s2[1] = 'c'; // Scring
    cout << "New s2 value: " << s2 << endl;
    s2.at(1) = 'b'; // Sbring
    cout << "New s2 value (at): " << s2 << endl;

    // Concatenation
    string begin{ "I like" };
    string end{ "BO3 zombies" };
    cout << begin + " " + end << endl;

    string to_substring{ "mkAppleasd" };
    // Uses substring to print Apple in the middle of awkward word (start, length)
    cout << "Fruit in to_substring: " + to_substring.substr(2, 5) << endl;
    cout << "But still: " << to_substring << endl;
    // Removes the unnecessary characters (start, length)
    to_substring.erase(0, 2);
    to_substring.erase(5, 3);
    cout << "Now it's clean: " << to_substring << endl;

    // Confuse string
    string one_strange_string{ "masodpasdmobottleasnidoansd" };
    // A word to be found
    string word{ "bottle" };
    // Finds the bottle in the middle of the ocean of letters
    size_t position = one_strange_string.find(word);
    // Checks if found
    if (string::npos != position) {
        cout << "Found the bottle at " << position << endl;
    }
    else {
        cout << "Can't find the bottle" << end;
    }

    // Insert string in the middle of string
    string unformatted_full_name{ "StephenHawking" };
    cout << "Unformatted: " + unformatted_full_name << endl;
    string first_name{ unformatted_full_name, 0, 7 };
    cout << "First Name: " + first_name << endl;
    string last_name = unformatted_full_name.substr(7, 7);
    cout << "Last Name: " + last_name << endl;
    string formatted_full_name = first_name + last_name;
    cout << "Formatted: " + formatted_full_name << endl;
    // Oh, forgot the space
    formatted_full_name.insert(formatted_full_name.find(last_name), " ");
    cout << "Formatted and formatted: " + formatted_full_name << endl;

    // Sort strings by last name
    string journal_entry_1{ "Isaac Newton" };
    string journal_entry_2{ "Leibniz" };
    journal_entry_1.erase(0, 6);
    if (journal_entry_1 > journal_entry_2) {
        string temp{ journal_entry_2 };
        journal_entry_2 = journal_entry_1;
        journal_entry_1 = temp;
    }
    cout << journal_entry_1 << "\n" << journal_entry_2;

    return 0;
}