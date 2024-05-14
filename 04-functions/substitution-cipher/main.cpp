/**
 * Problem: Cipher a message. The user should write a message
 * and the program should encrypt it by replacing every
 * letter for another. Display the encrypted message.
 * After this, decrypt the message back to original message.
 * The letter should be changed by the one in the same position
 * of the key.
 * Alphabet: abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
 * Cypher:   KIGDFZRPWQYUXMBLHOJCVTENSAkigdfzrpwqyuxmblhojcvtensa
 */
#include <iostream>
#include <string>

using namespace std;

// Normal alphabet
string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
// Cyphered alphabet
string cypher{ "KIGDFZRPWQYUXMBLHOJCVTENSAkigdfzrpwqyuxmblhojcvtensa" };

int main()
{
    for(;;) {
        // Reads input from user
        string user_input{};
        cout << "Entry message ('q' to quit): ";
        getline(cin, user_input);
        // Check to terminate program
        if("q" == user_input) {
            break;
        }

        // ENCRYPTING
        cout << "Encrypting message..." << endl << endl;
        string encrypted_message{};
        // Iterate over each letter changing to the
        // encrypted value
        for(char letter : user_input) {
            char encrypted_letter{ letter };
            // Adds space as is
            if(' ' != letter) {
                size_t alph_pos = alphabet.find(letter);
                encrypted_letter = cypher.at(alph_pos);
            }
            encrypted_message += encrypted_letter;
        }
        cout << "Encrypted message: " << encrypted_message << endl << endl;

        // DECRYPTING
        // Iterate over each letter changing back to the
        // normal value
        cout << "Decrypting message..." << endl << endl;
        string decrypted_message{};
        for(char letter : encrypted_message) {
            char decrypted_letter{ letter };
            // Adds space as is
            if(' ' != letter) {
                size_t alph_pos = cypher.find(letter);
                decrypted_letter = alphabet.at(alph_pos);
            }
            decrypted_message += decrypted_letter;
        }
        cout << "Decrypted message: " << decrypted_message << endl << endl;
    }
    return 0;
}