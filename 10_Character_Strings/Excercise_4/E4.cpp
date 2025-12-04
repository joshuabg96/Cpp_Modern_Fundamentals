/*
A simple and very old method of sending secret messages is the substitution cipher
You might have used this cipher with your friends when you were a kid
Basically, each letter of the alphabet gets replaced by another letter of the alphabet
For example, every 'a' get replaced with an 'X' and every 'b' get replaced with a 'Z', etc.

Write a program that ask a user to enter a secret message.

Encrypt this message using substitution cipher and siplay the encrypted message.
Then decryped the encrypted message back to the original message

You may use the 2 string below for your substitution
For example, to encrypt you can replace the character at position n in alphabet
with the character at position n in key

To decrypt you can replace the character at position n in key with the character at position n in alphabet
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"ZbcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYa"};                // Easy key for testing
    string message;

    cout << "Introduce your message: ";
    getline(cin, message);

    for (int i = 0; i < message.length(); i++)
    {
        if(alphabet.find(message.at(i)))
        {
            continue;
        }
        message.at(i) = key.at(alphabet.find(message.at(i)));
    }

    cout << "Encrypted message: " << message << endl;

    for (int i = 0; i < message.length(); i++)
    {
        if(key.find(message.at(i)))
        {
            continue;
        }
        message.at(i) = alphabet.at(key.find(message.at(i)));
    }
    
    cout << "\nDecrypted message: " << message << endl;

    return 0;
}