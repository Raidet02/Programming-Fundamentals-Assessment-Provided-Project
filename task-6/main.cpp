#include "main.h"

using namespace std;

void main()
{
    //The code in this file has been produced to show you how to seed
    //a random number generator, and use it. In main.h, we are using
    //C++'s <random> library to generate random numbers.

    //This can be done with srand() and rand(), but we have opted for
    //using a modern C++ approach. It gives you much more control
    //over the random numbers generated.

    //-----------
    //Expand the current solution to build a random number guessing game.
    //The game should produce a random number between 0-100, and ask users
    //for their guess. Based on their guess, the game should:

    //- Say "freezing" if the number is plus or minus 50 from the guess.
    //- Say "colder" if the number is plus or minus 35 from the guess.
    //- Say "cold" if the number is plus or minus 25 from the guess.
    //- Say "warm" if the number is plus or minus 15 from the guess.
    //- Say "warmer" if the number is plus or minus 10 from the guess.
    //- Say "hot" if the number is plus or minus 5 from the guess.
    //- Say "boiling" if the number is plus or minus 2 from the guess.

    //Once the user has submitted a guess, the program should show them
    //one of these strings and prompt them for another guess.

    //Alternatively, if the guess is correct, a success message should be shown,
    //telling the player they have won.

    //At the end of the program, it should also display the number of guesses
    //the player needed to guess the value in.     

    //cout << "Here is a random number between 1 and 10: " << random(1, 10) << endl;
    //cout << "And here is one between -3 and -5: " << random(-3, -5) << endl;

    int guess = 0; //the variables to be used
    int randNum = random(1, 100);
    int guessCounter = 0;
    bool isGuessCorrect = false;

    do //do while will run the code atleast once
    {
        cout << "Choose a number between 1 and 100: "; //asks the player for their guess
        cin >> guess;

        if (guess == randNum) //if the guess was correct the player wins
        {
            guessCounter++;
            isGuessCorrect = true;
            cout << "Well done, you have guessed the correct number in: " << guessCounter << endl;
        }
        else if (guess <= randNum + 2 && guess >= randNum - 2) //if the guess is inbtween these values and prints the outcome to the console
        {
            cout << "Boiling" << endl;
            guessCounter++;
        }
        else if (guess <= randNum + 5 && guess >= randNum - 5)
        {
            cout << "Hot" << endl;
            guessCounter++;
        }
        else if (guess <= randNum + 10 && guess >= randNum - 10)
        {
            cout << "Warmer" << endl;
            guessCounter++;
        }
        else if (guess <= randNum + 15 && guess >= randNum - 15)
        {
            cout << "Warm" << endl;
            guessCounter++;
        }
        else if (guess <= randNum + 25 && guess >= randNum - 25)
        {
            cout << "Cold" << endl;
            guessCounter++;
        }
        else if (guess <= randNum + 35 && guess >= randNum - 35)
        {
            cout << "Colder" << endl;
            guessCounter++;
        }
        else if (guess <= randNum + 100 && guess >= randNum - 100)
        {
            cout << "Freezing" << endl;
            guessCounter++;
        }

    } while (isGuessCorrect == false);
}