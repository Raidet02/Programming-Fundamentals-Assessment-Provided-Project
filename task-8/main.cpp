#include <iostream>
#include <string>
using namespace std;

int CheckIfValid() //checks if the value entered for the size of the inventory is a proper value
{
    string inventorySizeTemp = "";
    int inventorySize;

    for (int i = 0; i != 1;)
    {
        i++;

        cin >> inventorySizeTemp;

        try //uses a try catch to make sure that a letter or symbol was not input
        {
            inventorySize = stoi(inventorySizeTemp);
        }
        catch (...)
        {
            cout << "Please enter a valid number ";
            i--;
        }
    }

    return inventorySize; //returns only when the value is valid
}

void main()
{
    //In this challenge, you should build an inventory system using a dynamically
    //allocated array of structs.

    //There should also be an array of all possible inventory items, so that
    //the user can set inventory slots to one of these values. Each index into this
    //array could be classes as an "item id"

    
    //The player should be able to:
    //- Specify the size of the inventory (1 - 16 slots)
    //- Type commands to interact with the inventory, like so:
    //  - "view <number>"         -> Prints out details of the inventory slot index specified by number.
    //  - "show_all"              -> Shows all slots in the inventory.
    //  - "set <index> <item_id>" -> Sets the inventory specified by #index to the item #item_id
    //  - "items"                 -> Shows all the items you can possibly set a slot to, along with their ids.
    //  - "exit"                  -> Exits the tool

    //Invalid choices (such as setting or viewing and invalid index) should also be handled. 

    //An example of the commands:
    //  - "view 0"  -> Shows details of the first inventory slot
    //  - "set 0 2" -> Sets the first inventory slot to item id #2

    //-------------

    //An example list of items:
    // - 0: Empty
    // - 1: Shield
    // - 2: Potion
    // - 3: Gloves
    
    //An example session with these items might look like:

    // Please enter an inventory size: 8
    // > Initialized inventory with 8 slots.
    //
    // > view 0
    //
    // Inventory Slot 0 information:
    // Name: Empty
    //
    // > set 0 2
    // > view 0
    //
    // Inventory Slot 0 information:
    // Name: Potion
    //
    // > items
    // - 0: Empty
    // - 1: Shield
    // - 2: Potion
    // - 3: Gloves
    //
    // > show_all
    //
    // Inventory: 
    // - Slot 0: Potion
    // - Slot 1: Empty
    // - Slot 2: Empty
    // - Slot 3: Empty
    // - Slot 4: Empty
    // - Slot 5: Empty
    // - Slot 6: Empty
    // - Slot 7: Empty
    //
    // > exit

    int inventorySize; //initiates all the varibales to be used 
    bool exit = false;
    string playerCommand = "";
    string playerCommandTemp = "";
    int indexValue1 = 0;
    int indexValue2 = 0;
    string indexValueS1 = "";
    string indexValueS2 = "";
    int validCheck = 0;

    cout << "Please enter an inventory size: "; //asks player for the size of the inventory

    inventorySize = CheckIfValid();

    cout << "Initialized inventory with " << inventorySize << " slots" << endl;

    string* inventory = new string[inventorySize]; //creates a dynamic array

    string item[5] = {}; // a standard 1d array for the item list
    item[0] = "Empty";
    item[1] = "Sword";
    item[2] = "Shield";
    item[3] = "Health potion";
    item[4] = "Mana potion";

    for (int i = 0; i <= inventorySize; i++) //sets all the slots in the inventory to empty
    {
        inventory[i - 1] = item[0];
    }

    cin.ignore();

    while (exit == false) //the game loop
    {
        cout << endl << "> ";
        getline(cin, playerCommandTemp); //gets the players command

        int end = playerCommandTemp.find(" "); //seperates the string into the intial command and index values
        int stringSize = sizeof(playerCommandTemp) / 4;

        playerCommand = playerCommandTemp.substr(0, end);

        if (playerCommand == "items") //lists the item array
        {
            cout << endl << "> items:" << endl;

            for (int i = 0; i < 5; i++)
            {
                cout << "- " << i << ": " << item[i] << endl;
            }
        }
        else if (playerCommand == "show_all") //lists theplayers inventory
        {
            cout << endl << "> inventory:" << endl;
            for (int i = 0; i < inventorySize; i++)
            {
                cout << "- Slot " << i << ": " << inventory[i] << endl;
            }
        }
        else if (playerCommand == "view") //shows a specific inventory slot
        {
            indexValueS1 = playerCommandTemp.substr(end, stringSize - end); //gets the index value from the initail command
            validCheck = 0;

            try //checks if the index value is valid
            {
                indexValue1 = stoi(indexValueS1);
            }
            catch (...)
            {
                cout << endl << "Not a proper index" << endl;
                validCheck = 1;
            }

            if (validCheck != 1) //if the index value is valid runs the code
            {
                indexValue1 = stoi(indexValueS1);

                if (indexValue1 > inventorySize - 1 || indexValue1 < 0)
                {
                    cout << "The index value does not exist" << endl;
                }
                else
                {
                    cout << endl << "> Inventory Slot " << indexValue1 << " information:" << endl << "Name: " << inventory[indexValue1] << endl;
                }
            }
        }
        else if (playerCommand == "set") //changes the contents of an inventory slot to an item the player designates
        {

            indexValueS1 = playerCommandTemp.substr(end, stringSize - end); //gets the index values from the initail command

            stringSize = sizeof(indexValueS1) / 4;
            end = indexValueS1.find_last_of(" ");
            indexValueS2 = indexValueS1.substr(end, stringSize - end);

            validCheck = 0;

            try //checks if the index value is valid
            {
                indexValue1 = stoi(indexValueS1);
                indexValue2 = stoi(indexValueS2);
            }
            catch (...)
            {
                cout << endl << "Not a proper index" << endl;
                validCheck = 1;
            }

            if (validCheck != 1) //if the index value is valid runs the code
            {
                indexValue1 = stoi(indexValueS1);
                indexValue2 = stoi(indexValueS2);

                if ((indexValue1 > inventorySize - 1 || indexValue1 < 0) && (indexValue2 > 4 || indexValue2 < 0))
                {
                    cout << "The index value does not exist" << endl;
                }
                else
                {
                    inventory[indexValue1] = item[indexValue2];
                }
            }
        }
        else if (playerCommand == "exit") //exists the inventory tool
        {
            exit = true;
        }
        else //if anything other than a correct comand is inputed it will tell the player
        {
            cout << endl << "Please enter a valid command" << endl;
        }
    }
}
