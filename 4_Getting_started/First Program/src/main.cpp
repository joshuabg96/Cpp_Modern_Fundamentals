#include <iostream>

int main()
{
    // Declaration of the variable
    int favorite_number;

    // Ask for a number
    std::cout << "Enter your favorite number between 1 and 100: ";
    // Save the number in the variable
    std::cin >> favorite_number;
    // Print a message with the variable
    std::cout << "Amazing!! That's my favorite number too \nNot really!!, " << favorite_number << " Is my favorite number" << std::endl;
    return 0;
}