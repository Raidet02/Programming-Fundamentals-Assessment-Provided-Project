#include <iostream>
#include <string>
using namespace std;

void main()
{
    //Using structs and arrays, build a character class and name selection system
    //for a text-based game. The program should firstly prompt the user for a class
    //using a numbered menu system. For example:

    // Please choose a character class below:
    // 1. Spearman
    // 2. Knight
    // 3. Archer
    //
    // > 3
    // - You have selected the Archer character class.

    //The character class names and amount are up to you, but should make 
    //use of an array so the solution can be easily extended. Invalid menu choices
    //should also be handled.

    //The user should then be prompted for their in-game name, and then their
    //player details should be shown. These details should be stored in a struct,
    //so player details can be a) easily extended to encompass more player detail
    //types in the future and b) logically exist in one structure.
    
    //The prompt should be shown like below:

    // Please enter your name: ben
    //
    // Player details:
    // - Name: ben
    // - Class: Knight

    string characterClass[5] = {}; //creates an array of character classes
    characterClass[0] = "Monk";
    characterClass[1] = "Swordsman";
    characterClass[2] = "Archer";
    characterClass[3] = "Wizard";
    characterClass[4] = "Preist";

    struct Player //creates a struct for player then an instance of the struct
    {
        string playerName = "";
        string playerClass = "";
    };

    Player player1;

    string playersChoice = "";

    cout << "Please choose a character class below: " << endl; //asks the player to choose a class

    for (int k = 0; k < 5; k++) //prints the classes to the console
    {
        cout << k + 1 << ". " << characterClass[k] << endl;
    }

    for (int i = 0; i != 1;) //makes sure that the players choice is valid
    {
        i++;

        cout << endl << "> ";
        cin >> playersChoice;

        try
        {
            int playersClassChoice = stoi(playersChoice);

            if (playersClassChoice < 1 || playersClassChoice > 5)
            {
                cout << "Please enter a valid number ";
                i--;
            }
        }
        catch (...)
        {
            cout << "Please enter a valid number ";
            i--;
        }
    }

    int playersClassChoice = stoi(playersChoice); //only runs this if the player entered a valid option

    player1.playerClass = characterClass[playersClassChoice]; //changes the instance of the struct to the players choice

    cout << endl << "You have selected the " << player1.playerClass << " character class." << endl;

    cout << endl << "Please enter your name: "; //asks the player for their name

    cin.ignore();
    getline(cin, player1.playerName);

    cout << endl << "Player details:" << endl << "- " << "Name: " << player1.playerName << endl << "- " << "Class: " << player1.playerClass << endl; //ouptputs the players details
}