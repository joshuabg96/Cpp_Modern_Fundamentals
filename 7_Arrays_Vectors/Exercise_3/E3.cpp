/* 
Write a C++ program as follows:

Declare 2 empty vectors of integers named
vector1 and vector2, respectively.

Add 10 and 20 to vector1 dynamically using push_back
Display the elements in vector1 using the at() method as well as its size using the size() method

Add 100 and 200 to vector2 dynamically using push_back
Display the elements in vector2 using the at() method as well as its size using the size() method

Declare an empty 2D vector called vector_2d
Remember, that a 2D vector is a vector of vector<int>

Add vector1 to vector_2d dynamically using push_back
Add vector2 to vector_2d dynamically using push_back

Display the elements in vector_2d using the at() method

Change vector1.at(0) to 1000

Display the elements in vector_2d again using the at() method

Display the elements in vector1

What did you expect? Did you get what you expected? What do you think happened?
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vector1;
    vector<int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    vector2.push_back(100);
    vector2.push_back(200);
    
    cout << "Vector 1 size: " << vector1.size() << " Elements: ";
    for (int i = 0; i < vector1.size(); i++)
    {
        cout << vector1.at(i) << " ";
    }
    cout << endl;

    cout << "Vector 2 size: " << vector2.size() << " Elements: ";
    for (int i = 0; i < vector2.size(); i++)
    {
        cout << vector2.at(i) << " ";
    }

    vector <vector<int>> vector2d;
    vector2d.push_back(vector1);
    vector2d.push_back(vector2);

    cout << "\nElements 2D vector " << endl;
    for (int i = 0; i < vector2d.at(0).size(); i++)
    {
        cout << vector2d.at(0).at(i) << " ";
    }
    cout << endl;

    for (int i = 0; i < vector2d.at(1).size(); i++)
    {
        cout << vector2d.at(1).at(i) << " ";
    }
    cout << endl;

    vector1.at(0) = 1000;
    cout << "\n\n";
    cout << "\nElements 2D vector " << endl;
    for (int i = 0; i < vector2d.at(0).size(); i++)
    {
        cout << vector2d.at(0).at(i) << " ";
    }
    cout << endl;

    for (int i = 0; i < vector2d.at(1).size(); i++)
    {
        cout << vector2d.at(1).at(i) << " ";
    }
    cout << endl;

    cout << "Vector 1 size: " << vector1.size() << " Elements: ";
    for (int i = 0; i < vector1.size(); i++)
    {
        cout << vector1.at(i) << " ";
    }
    cout << endl;
    
}