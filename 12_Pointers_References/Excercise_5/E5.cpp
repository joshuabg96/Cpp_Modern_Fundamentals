/*
Reverse a std::string using Pointers (Challenging!)
Exercise: Reverse a std::string using Pointers

Specification:

Write a C++ function reverse_string that takes a std::string as input and returns a new std::string with the characters in reverse order. The function should use pointers to perform the reversal.

Function Signature:

std::string reverse_string(const std::string& str);
Input:

str: The input string.

Output:

The function should return a new string with the characters of str reversed.

Example:

std::string input = "Hello, World!";
std::string reversed = reverse_string(input);
 
// reversed should be "!dlroW ,olleH"
*/
#include <iostream>
#include <string>
using namespace std;

string reverse_string(const string &str) {
    string reversed;
    int size = str.size();
    reversed = str;
    if(size > 1)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            reversed.push_back(str.at(i));
        }
    }
    else
    {
        reversed = str;
    }
    return reversed;
}

int main()
{
    string world = "Hello, World!";
    string reversed;
    reversed = reverse_string(world);
    cout << reversed << endl;
    return 0;
}