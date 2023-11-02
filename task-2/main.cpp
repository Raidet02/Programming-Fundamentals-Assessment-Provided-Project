#include <iostream>
using namespace std;

void main()
{
    //Add code to prompt the player for their name, and then
    //greet them with that name. For example, 
    //
    // Please enter your name: ben
    // Hello ben!
    //

    //Expand this so the player is asked for their name, clan tag,
    //age and username. Print out these details like so:
    //
    // - Name: <name>
    // - Username: [<clantag>]<username>
    // - Age: <age>
    //
    
    string name = ""; //Initialize the variables that are going to be used
    string clanTag = "";
    string userName = "";
    int age = 0;

    cout << "Please enter your name: "; //Ask the user for their information and assign it to appropriate variables
    cin >> name;

    cout << "Please enter your clan tag: ";
    cin >> clanTag;

    cout << "Please enter your username: ";
    cin >> userName;

    cout << "Please enter your age: ";
    cin >> age;

    cout << "- Name: " << name << endl; //Out put the information in the appropriate manner 
    cout << "- Username: " << "[" << clanTag << "] " << userName << endl;
    cout << "- Age: " << age << endl;
}