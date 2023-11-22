#include <iostream>
#include <string>
using namespace std;

struct Assessment //define a struct for the variables needed for each assessment
{
public:

    float gradePercent[3];
    float totalPercentageForAssessment = 0.0f;
};

Assessment assessment1; //create an instance of the struct for each assessment
Assessment assessment2;

int CheckIfValidInput(); //create 3 functions used at the top of the code but run them below for ease when programming
int CalculatePercentageOfGrade(int criteria);
string CalculateGrade(int criteria);

void main()
{
    //Add code to build a grade calculator for the module. This should:
    //
    // - Prompt the user for input, for the grade of each component of assessment 1
    // - Prompt the user for input, for the grade of each component of assessment 2
    // - Provide a detailed breakdown of:
    //      - List the overall percentage of each assessment    mark is a percentage of the grade (30 or 70)
    //      - Their overall grade after percentage weighting    each assessment = 50%
    //      - Output which CRG band they fit into, for each criterion

    //Invalid input should be detected and handled after prompting. For example,
    //if the input grade "-1" is given, the user should be reprompted to enter the
    //grade again.

    //Furthermore, please use structs and arrays where appropriate to model
    //the different assessment components.
    //..

    cout << "Assessment 1" << endl; //assessment 1

    cout << endl << "What was your grade for C1 (Portfolio of completed challenges) (This is worth 70% of assessment 1)" << endl; //ask for grade

    cout << endl << "Boundary: " << CalculateGrade(1) << endl; //run the calculator the number is an index value used later

    cout << endl << "What was your grade for C2 (Reflective journal) (This is worth 30% of assessment 1)" << endl;

    cout << endl << "Boundary: " << CalculateGrade(2) << endl;


    cout << endl << endl << "Assessment 2" << endl; //assessment 2 same as 1 with one extra criteria

    cout << endl << "What was your grade for C1 (Development of text-based game) (Worth 60% of assessment 2)" << endl;

    cout << endl << "Boundary: " << CalculateGrade(3) << endl;

    cout << endl << "What was your grade for C2 (Code quality and best practice) (Worth 20% of assessment 2)" << endl;

    cout << endl << "Boundary: " << CalculateGrade(4) << endl;

    cout << endl << "What was your grade for C3 (Demonstration of programming techniques) (Worth 20% of assessment 2)" << endl;

    cout << endl << "Boundary: " << CalculateGrade(5) << endl;


    assessment1.totalPercentageForAssessment = assessment1.gradePercent[0] + assessment1.gradePercent[1]; //calculate the total percentages
    assessment2.totalPercentageForAssessment = assessment2.gradePercent[0] + assessment2.gradePercent[1] + assessment2.gradePercent[2];

    cout << endl << endl << "Total percentage for assessment 1: " << assessment1.totalPercentageForAssessment << "%" << endl; //output the total percentages
    cout << "Weighted percentage for assessment 2: " << assessment1.totalPercentageForAssessment / 2 << "%" << endl; //output the weighted percentages

    cout << endl << "Total percentage for assessment 2: " << assessment2.totalPercentageForAssessment << "%" << endl;
    cout << "Weighted percentage for assessment 2: " << assessment2.totalPercentageForAssessment / 2 << "%" << endl;


    cout << endl << endl << "Final grade after weighting : " << (assessment1.totalPercentageForAssessment / 2) + (assessment2.totalPercentageForAssessment / 2) << "%" << endl; //output the final percentage for grade
    cout << "Final mark boundary: " << CalculateGrade(0); //run the calculator to output the final grade 0 is a specific index that alters the code below
}

int CheckIfValidInput() //gets an input from the user and checks if it is a number and between 1 - 100
{
    string tempInput = "";
    int returnValue = 0;

    for (int i = 0; i != 1;) //loops until it gets a valid number
    {
        i++;

        cout << endl << "> ";
        cin >> tempInput;

        try
        {
            returnValue = stoi(tempInput); 

            if (returnValue < 0 || returnValue > 100) //checks if input is between 1 - 100
            {
                cout << endl << "Please enter a valid grade" << endl; 

                i--;
            }
        }
        catch (...) //checks for error of any kind
        {
            cout << endl << "Please enter a valid grade" << endl;

            i--;
        }

    }

    returnValue = stoi(tempInput); //converts to int after checks have been run

    return returnValue; //returns if a valid number has been entered
}

int CalculatePercentageOfGrade(int criteria) //runs checkifvalidinput, calculates the percentage for each criteria, returns the mark value for the grade calculator
{
    int mark = CheckIfValidInput();

    if (criteria == 1)
    {
        assessment1.gradePercent[criteria - 1] = 70.0f * (mark / 100.0f); //i.e 70 divided by (0.71) 
    }
    else if (criteria == 2)
    {
        assessment1.gradePercent[criteria - 1] = 30.0f * (mark / 100.0f);
    }
    else if (criteria == 3)
    {
        assessment2.gradePercent[criteria - 3] = 60.0f * (mark / 100.0f);
    }
    else if (criteria == 4)
    {
        assessment2.gradePercent[criteria - 3] = 20.0f * (mark / 100.0f);
    }
    else if (criteria == 5)
    {
        assessment2.gradePercent[criteria - 3] = 20.0f * (mark / 100.0f);
    }

    return mark; //returns mark value for later use
}

string CalculateGrade(int criteria) //gets a mark, returns the grade depending on the mark
{
    int marks = 0;
    string grade = "";

    if (criteria != 0) //if the criteria is 0 (the final grade) uses the overall percentages otherwise uses the one from checkifvalidnumber
    {
        marks = CalculatePercentageOfGrade(criteria);
    }
    else
    {
        marks = (assessment1.totalPercentageForAssessment / 2) + (assessment1.totalPercentageForAssessment / 2);
    }

    if (marks >= 70) //goes through all grades
    {
        grade = "1:1 (First)";
    }
    else if (marks >= 60)
    {
        grade = "2:1";
    }
    else if (marks >= 50)
    {
        grade = "2:2";
    }
    else if (marks >= 40)
    {
        grade = "Pass";
    }
    else
    {
        grade = "Fail";
    }

    return grade; //returns grade 
}