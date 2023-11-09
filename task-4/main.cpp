#include <iostream>
#include <string>
using namespace std;

void textBoxGenerator(string& textForTextBox) //creates a function for making a textbox around a given input
{
    int amountOfAsterisk = 0; //creaytes the variables needed
    int loopCondition = 1;

    amountOfAsterisk = textForTextBox.length() + 4; //sets the amout of asterisks needed for the lines above and below to the correct amount

    while (amountOfAsterisk >= 1)
    {
        cout << "*";
        amountOfAsterisk--;

        if (amountOfAsterisk == 0 && loopCondition == 1) //when the line above the text has been done the text is added between 2 asterisks
        {
            cout << endl << "* " << textForTextBox << " *" << endl;

            amountOfAsterisk = textForTextBox.length() + 4;
            loopCondition--; //maks the loop only happen once then the line below is made
        }
    }
}

void main()
{
    //For this challenge, produce a program which 
    //prompts the user for a string of text. When
    //this text is entered, the program should:

    //- Automatically generate a box around the text.
    //- And show it in the console.

    //This is a feature commonly seen in text-based
    //adventure games, to show speech bubbles for characters.

    //---
    //An example session:    

    //Please enter some text: blah something
    //
    // ******************
    // * blah something *
    // ******************

    //Can you also expand this so that the box can be
    //shown with some padding? Or turn it into a function?

    string textForTextBox = ""; //variable to hold the text

    cout << "Please enter some text: ";
    getline(cin, textForTextBox);

    textBoxGenerator(textForTextBox); //plays the function and passes the text to it
}