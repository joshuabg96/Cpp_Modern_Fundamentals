/*
    Frank's Carpet Cleaning Service
    Charges
        $25 per small room
        $35 per large room
    Sales tax rate is 6%
    Estimates are valid for 30 days

    Promt the user for the number of small and large rooms they would like cleaned
    and provide an estuimate such as:

    Estimate for carpet cleaning service
    Number of small rooms: 3
    Number of large rooms : 1
    Price per small room: $25
    Price per large room: $35
    Cost: $110
    Tax: $6.6
    ===================================
    Total estimate: $116.6
    This estimate is valid for 30 days
*/

#include <iostream>
using namespace std;

int main()
{
    int small_rooms = 0;
    int large_rooms = 0;
    int small_cost = 25;
    int large_cost = 35; 
    int cost = 0;
    float tax = 0;

    cout << "Hello, welcome to Joshua's Carpet Cleaning Service\n" << endl;
    
    cout << "How many small rooms would you like cleaned? ";
    cin >> small_rooms;
    cout << "how many large rooms would you like cleand? ";
    cin >> large_rooms;

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << small_rooms << "\nNumber of large rooms: " << large_rooms << endl;
    cout << "Price per small room: $" << small_cost << "\nPrice per large room: $" << large_cost << endl;
    
    cost = (small_rooms * small_cost) + (large_rooms * large_cost);
    cout << "Cost: $" << cost << endl;

    tax = cost * 0.06;
    cout << "Tax: $" << tax << endl;

    cout << "===================================" <<endl;

    cout << "Total estimate $" << cost + tax << endl;
    cout << "This estimate is valid for 30 days"<< endl;
}
