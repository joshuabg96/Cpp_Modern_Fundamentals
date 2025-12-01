
/*
    Declare an array of 10  integers named arr  and initialize the array so that all 10 integers are 0 .
    Then assign 100  to the first element of the array and 1000  to the last element of the array.
*/
#include <vector>
#include <iostream>
using namespace std;
vector<int> use_array()
{
    int arr[10] = {0};          // Initialization all elements with 0's
    arr[0] = 100;               // Modify first element
    arr[9] = 1000;              // Modify last element (size - 1)

    vector<int> v(arr, arr + sizeof arr / sizeof arr[0]);
    return v;
}

int main()
{
    vector<int> v = use_array();
    cout << "First element: " << v[0] << " Last element: " << v[9] <<endl;
}