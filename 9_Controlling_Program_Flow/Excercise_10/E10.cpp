/*
This callenge is about using a collection (list) of a integers and allowing the user to select options from a menu to perform operations on the list.

You program should display a menu options to the user as follows:

P - print numbers
A - Add a number
M - Display mean of the numbers
S- Display the smallest number
L - Display the largest number
Q - Quit

Enter your choice:

The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choise is made, you should display "Unknown selection, please try again" and the menu options should be displayed again.

If the user enters 'P' or 'p', you should display all of the lements (ints) int the list
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackerts separated by a space.
For example: [ 1 2 3 4 5 ]

If the user enters 'A' or 'a' then you should promt the user for an integer to add to the list
which you will add to the list and then display it was added. For example if the user enters 5
You should display "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm' you should calculate the mean or average of the elements in the list and display it.
if the list is empty you should display "Unable to calcualte the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1] you should display, "the smallest number is 5"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1] you should display "The largest number is 5".
If the list is empty you should display "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display "Goodbye" and the program should terminate

Before beging Write out the steps you need to take and decide in wht order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This excercise can be challenging! it may likely take few attempts before complete it -- that's OK1

Finally be sure to test your program as you go and at the end.

Hint: Use a vector!
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    char option;
    bool running = true;
    int add {0}, min {0}, max {0};
    vector<int> vec {};
    float average {0};

    while (running)
    {
        cout << "P - print numbers\nA - Add a number\nM - Display mean of the numbers\nS- Display the smallest number\nL - Display the largest number\nQ - Quit\n\nEnter your choice: ";
        cin >> option;

        switch (option)
        {
        case 'p':
        case 'P':
            if(vec.size() > 0)
            {
                cout << "\n[ ";
                for (int i = 0; i < vec.size(); i++)
                {
                    cout << vec.at(i) << " ";
                }
                cout << "]" << endl;
            }
            else
            {
                cout << "\n[] - the list is empty\n"<< endl;
            }
            break;
        case 'a':
        case 'A':
            cout << "\nGive a integer number: ";
            cin >> add;
            vec.push_back(add);
            cout << add <<" Added\n" << endl;
            break;
        case 'm':
        case 'M':
            if(vec.size() > 0)
            {
                for (int i = 0; i < vec.size(); i++)
                {
                    average += vec.at(i);
                }
                average /= static_cast<float>(vec.size());
                cout << "\nAverage: " << average << endl;
                
            }
            else
            {
                cout << "\nUnable to calcualte the mean - no data\n" << endl;
            }
            break;
        case 's':
        case 'S':
            if(vec.size() > 0)
            {
                min = vec.at(0);
                for (int i = 1; i < vec.size(); i++)
                {
                    if (min > vec.at(i))
                    {
                        min = vec.at(i);
                    }
                }
                cout << "The smallest number is " << min << endl;
            }
            else
            {
                cout << "\nUnable to determine the smallest number - list is empty\n"<< endl;
            }
            break;
        case 'l':
        case 'L':
            if(vec.size() > 0)
            {
                max = vec.at(0);
                for (int i = 1; i < vec.size(); i++)
                {
                    if (max < vec.at(i))
                    {
                        max = vec.at(i);
                    }
                }
                cout << "The largest number is " << max << endl;
            }
            else
            {
                cout << "\nUnable to determine the largest number - list is empty\n"<< endl;
            }
            break;
        case 'q':
        case 'Q':
            cout << "Goodbye" << endl;
            running = false;
            break;
        
        default:
            cout << "\nUnknown selection, please try again"<< endl;
            break;
        }
    }
    return 0;
}