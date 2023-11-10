#include "main.h"

void main()
{
    //Build a structure in main.h capable of representing a 2D vector called Vector2. Then,
    //write a function in main.h called GetDistanceBetweenPoints which:
    //
    //- Takes two Vector2 instances via parameter
    //- Returns the Euclidean distance between the two points, as a float.
    //
    //Euclidean distance calculation is used throughout games programming, for several
    //different purposes. 

    //You should then highlight the function working correctly. The code below
    //will prompt the user for an X and Y for two vectors.

    float xComponents[2] = { 0.0f, 0.0f };
    float yComponents[2] = { 0.0f, 0.0f };

    for(int i = 0; i < 2; i++)
    {
        std::cout << "Please enter the X component of vector " << (i + 1) << ": ";
        std::cin >> xComponents[i];

        std::cout << "Please enter the Y component of vector " << (i + 1) << ": ";
        std::cin >> yComponents[i];

        std::cout << std::endl;
    }

    Vector2 vector2P;
    Vector2 vector2Q;

    vector2P.xCoordinates = xComponents[0];
    vector2P.yCoordinates = yComponents[0];

    vector2Q.xCoordinates = xComponents[1];
    vector2Q.yCoordinates = yComponents[1];

    cout << endl << "This is the Euclidean distance between the given points: " << GetDistanceBetweenPoints(vector2P, vector2Q) << endl;

    //You should then build two Vector2s from the given x and y components, and show
    //the calculated distance between each point.
    
}

