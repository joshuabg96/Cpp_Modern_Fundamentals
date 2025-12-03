/*
If Statement - Can you Drive?
In this exercise you will use a simple if  statement to decide if someone can drive. Let's assume that anyone 16 or older can legally drive.

If the person can legally drive, your program should display, "Yes - you can drive!" using a cout  statement. You do not have to provide a '\n'  or endl .

If the person cannot legally drive, then your program should not display anything.

The age  will be provided for you, you do NOT need to declare age . Our test cases will provide different values for age  to test your code.
*/
#include <iostream>
using namespace std;

void can_you_drive(int age)
{
    if (age >= 16)
    {
        cout << "Yes - you can drive!";
    }
    
}

int main()
{
    can_you_drive(16);
}