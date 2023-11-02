#include <iostream>
using namespace std;

void main()
{
    //Add code to prompt a user for a single number, and then show
    //the square of that number. For example, imagine the session:

    // What number do you want to Square? 5
    // > 5 squared is 25.

    float numToSquare = 0.0f; //Initialize the variable to be used

    cout << "What number do you want to Square?"; //Ask the user for the umber they wish to be squared
    cin >> numToSquare;

    cout << "> " << numToSquare << " squared is " << numToSquare * numToSquare << endl; //Output the number in a clear manner
}