/*
Declare a vector of integers named vec  and initialize the vector to 10,20,30,40, and 50 
Modify the first element of the vector to be 100  and modify the last element of the vector to be 1000 .
The final vector should then be 100, 20, 30, 40, and 1000.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> use_vector()
{
    vector<int> vec {10,20,30,40,50};
    vec[0] = 100;
    vec[4] = 1000;
    return vec;
}

int main()
{
    vector<int> v = use_vector();
    cout << "First element: " << v.at(0) << " Last element: " << v.at(4) << endl;
}