/*
    Recall the challenge from section 9 Below
    Your challenge for section 11 is to modularize your solution to the section 9
    chanllenge by refactoring your solution so that it uses funtion

    You decide how to modularize the program
    Here are a few hints:
    - Create functions for each major function
    - Keep the functions small
    - Remember the Boss/Worker analogy
    - Keep the vector declaration in the main function and pass the vector object to any function that requires oit

    Do not move the vector object outside the main and make it a global variable

    - You can start by defining a function that displays the menu
    - You can then define a function that reads the selection from the user and returns it in uppercase
    - Create functions for each menu option
    - Create functions that display the list of numbers, calcualtes the mean and so forth

    Take it one function at a time and take your time
    If you get frustrated, take a break this isn't as easy as it looks the first time you doi it

    Finally do not forget to use function prototypes
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;


void menu();
char get_option();
void print_numbers(const vector<int> vec);
void add_number(vector<int> &vec);
void mean_numbers(const vector<int> vec);
void smallest_number(const vector<int> vec);
void largest_number(const vector<int> vec);
void quit(bool &running);


void menu()
{
    cout << "P - print numbers\nA - Add a number\nM - Display mean of the numbers\nS- Display the smallest number\nL - Display the largest number\nQ - Quit\n\nEnter your choice: ";
}

char get_option()
{
    char option {};
    cin >> option;
    return toupper(option);
}

void print_numbers(const vector<int> vec)
{
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
}

void add_number(vector<int> &vec)
{
    int add;
    cout << "\nGive a integer number: ";
    cin >> add;
    vec.push_back(add);
    cout << add <<" Added\n" << endl;
}

void mean_numbers(const vector<int> vec)
{
    double average;
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
}

void smallest_number(const vector<int> vec)
{
    int min;
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
}

void largest_number(const vector<int> vec)
{
    int max;
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
}

void quit(bool &running)
{
    running = false;
}



int main()
{
    bool running = true;
    char option;
    vector<int> vec {};

    while (running)
    {
        menu();
        option = get_option();

        switch (option)
        {
            case 'P':
                print_numbers(vec);
                break;

            case 'A':
                add_number(vec);
                break;

            case 'M':
                mean_numbers(vec);
                break;

            case 'S':
                smallest_number(vec);
                break;

            case 'L':
                largest_number(vec);
                break;

            case 'Q':
                quit(running);
                break;
            
            default:
                cout << "\nUnknown selection, please try again" << endl;
                break;
        }
    }
    return 0;
}