#include <iostream>
#include <string>
using namespace std;

void main()
{
    //Make a program which converts any given string to sentence
    //case. For example:

    // Please enter some text: hello this is a sentence. and here is another. and another.
    //
    // > Hello this is a sentence. And here is another. And another.

    //The program should be able to work regardless of whitespace between
    //period characters. Note that proper nouns shouldn't be considered here, just
    //the rule that if a character is after a period, it should be capitalised.

    //Additionally, you should expand the solution to:
    //
    // - Show the given text in sentence case, lowercase, or uppercase
    // - Detect if the text has no alphabetical characters, and if so, show a warning
    //
    // e.g.

    // Please enter some text: hello this is another sentence. blah. something else.
    //
    // - Sentence case: Hello this is another sentence. Blah. Something else.
    // - Lowercase: hello this is another sentence. blah. something else.
    // - Uppercase: HELLO THIS IS ANOTHER SENTENCE. BLAH. SOMETHING ELSE.
    //

    string sentenceToEdit = ""; //creates the variables to be used
    string sentenceToUpper = "";
    string sentenceToLower = "";

    cout << "Please enter some text: "; //asks the user for text
    getline(cin, sentenceToEdit);

    sentenceToUpper = sentenceToEdit; //sets the variables to the inital input
    sentenceToLower = sentenceToEdit;

    for (int i = 0; i <= sentenceToEdit.length(); i++)
    {
        if ((sentenceToEdit[i] >= 'a' && sentenceToEdit[i] <= 'z') || (sentenceToEdit[i] >= 'A' && sentenceToEdit[i] <= 'Z')) //checks if the character is a character not a symbol or number
        {
            if (sentenceToEdit[0] == ' ') //checks if the first charater is a space if so unpercases the second otherwise it upercases the first character
            {
                sentenceToEdit[1] = toupper(sentenceToEdit[1]);
            }
            else 
            {
                sentenceToEdit[0] = toupper(sentenceToEdit[0]);
            }

            for (int i = 0; i <= sentenceToEdit.length(); i++) //goes though the sentence and checks if there is a . if so the next character is set to uppercase
            {
                if (sentenceToEdit[i] == '.' && sentenceToEdit[i + 1] != ' ') //if here is a . and the first character is a space the next character is set to upercase
                {
                    sentenceToEdit[i + 1] = toupper(sentenceToEdit[i + 1]);
                }
                else if (sentenceToEdit[i] == '.' && sentenceToEdit[i + 1] == ' ')
                {
                    sentenceToEdit[i + 2] = toupper(sentenceToEdit[i + 2]);
                }
            }

            for (int i = 0; i <= sentenceToEdit.length(); i++) //sets the whole sentence to uppercase
            {
                sentenceToUpper[i] = toupper(sentenceToEdit[i]);
            }

            for (int i = 0; i <= sentenceToEdit.length(); i++) //sets the whole sentence to lowercase
            {
                sentenceToLower[i] = tolower(sentenceToEdit[i]);
            }

            cout << "Sentence case: " << sentenceToEdit << endl; //prints the three sentences to the console
            cout << "Uppercase: " << sentenceToUpper << endl;
            cout << "Lowercase: " << sentenceToLower << endl;

            i = sentenceToEdit.length() + 1;
        }

        if (i == sentenceToEdit.length()) //if the sentence did not conatin any alphebetical characters prints this to console instead
        {
            cout << "Sorry but your sentence does not contain alphebetical characters" << endl;
        }
    }
}