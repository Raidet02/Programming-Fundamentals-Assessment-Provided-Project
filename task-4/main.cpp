#include <iostream>
#include <string>
using namespace std;

void textBoxGenerator(string& textForTextBox)
{
    int amountOfAsterisk = 0;
    int loopCondition = 1;

    amountOfAsterisk = textForTextBox.length() + 4;

    while (amountOfAsterisk >= 1)
    {
        cout << "*";
        amountOfAsterisk--;

        if (amountOfAsterisk == 0 && loopCondition == 1)
        {
            cout << endl << "* " << textForTextBox << " *" << endl;

            amountOfAsterisk = textForTextBox.length() + 4;
            loopCondition--;
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

    string textForTextBox = "";

    cout << "Please enter some text: ";
    getline(cin, textForTextBox);

    textBoxGenerator(textForTextBox);
}