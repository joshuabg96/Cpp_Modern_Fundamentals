/*
Using C-style Strings
In this exercise you will create a program that determines the length of a first name and last name individually and then the length of the entire name through the use of the C-style string functions strlen, strcpy, and strcat.

Begin by declaring and initializing the C-style string variable first_name to contain "Bjarne".
Now, declare and initialize a second C-style string variable last_name to contain "Stroustrup".
You must also declare a third C-style string variable whole_name but do not initialize it yet. Remember that the variable whole_name must be large enough to contain the first and last name with no whitespaces.

Now, by using the C-style string function strlen, declare and initialize the variable first_name_length to contain the length of the first_name string and the variable last_name_length to contain the length of the last_name string.


Using the C-style string function strcpy, copy the first_name string into the whole_name string variable.
Now, by using the C-style string function strcat, concatenate the last_name string at the end of the whole_name string.
Finally, by using the C-style string function strlen, declare and initialize the variable whole_name_length to contain the length of the whole_name string.
*/
#include <iostream>
#include <cstring>
using namespace std;

void string_adn_functions()
{
    char first_name [7] {"Bjarne"};
    int first_name_length;
    char last_name [11] {"Stroustrup"};
    int last_name_length;
    char whole_name [20] {};
    int whole_name_length;

    first_name_length = strlen(first_name);
    last_name_length = strlen(last_name);
    strcat(whole_name, first_name);
    strcat(whole_name, last_name);
    whole_name_length = strlen((whole_name));
    cout << "The length of the first name, " << first_name << ", is " << first_name_length << " letters long and the length of the last name, " << last_name << ", is " << last_name_length << " letters long. This means that the length of the whole name must be " << whole_name_length << " letters long.";
}

int main()
{
    string_adn_functions();
    return 0;
}