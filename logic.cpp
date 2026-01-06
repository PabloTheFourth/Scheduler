//  12-23-25: In the future we need to add a feature that puts all the text files in a folder.

//12-29-25
/*
1. I need to add a feature that declares whether an employee is a manager or co worker - DONE

2. I need to add categories to the kitchen to see how good each person is in those categories 
    for example - Grill side, Salad Side, Pizza line, Pizza strecter, and prep. - DONE 

3. Add a system that can detect what shift each person can work and turn those into "Hour Sectors".
    for example - Morning could be 8am-3pm and for a Manager it could be 7am-4pm
    ----------------------------------------------------------------------------------------
    After these sections have been done, only than can i start on the system that can 
    schedule the employees based on those variables
*/

/*
NOTES NOTES NOTES NOTES NOTES
1/3/2026
later remove the feature that deletes the files after closing the program. Find a way to reupload those files each time the 
program is reused. 
Fix the view for either Availability or Skill set - FIXED

1/4/2026
The schedule Array contains every bit of information about the employee, from their kitchen title to their skill set.
*/



#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;

void gatherAvailability(string schedule[],int arraySize, int employeeLoopTime);
void editSkillSet(string schedule[], int arraySize);
void gatherSkillSet(string schedule[], int arraySize, int employeeLoopTime, int employeesAdded);
void editAvailability(string schedule[], int arraySize);
void viewAvailability(string schedule[], int arraySize);
void viewSkillSet(string schedule[], int arraySize);
void printSchedule(string schedule[], int arraySize, int dummyEmployeeLoopTime);

int main() {
bool menuLoop = true;
const int numOfEmployees = 50;
int employeeLoopTime, dummyEmployeeLoopTime = 0;
string schedule[numOfEmployees], menuChoice;

while (menuLoop == true) {
    cout << "\nWelcome to Pablos ultamate Scheduler! \n";
    cout << "please choose an option from the list below\n";
    cout << "1. add Employees Availability\n";
    cout << "2. edit an employees availability\n";
    cout << "3. edit an employees skills\n";
    cout << "4. View an employees availability\n";
    cout << "5. View an employees skills\n";
    cout << "6. Print out Schedule\n";
    cout << "7. Turn Off\n";
    cout << "Choice: ";
    cin >> menuChoice;

    if (menuChoice == "1") {
        cout << "How many Employess are we adding? ";
        cin >> employeeLoopTime;
        dummyEmployeeLoopTime += employeeLoopTime;
        cin.ignore();
        //string schedule[numOfEmployees]; //I need to fix this - its only updating the array within the function and not the whole program - FIXED
    
        gatherAvailability(schedule, numOfEmployees, dummyEmployeeLoopTime);

        cout << endl << "Would you like to add a skill set to the following added employee/s for the kitchn? Y or N: ";
        cin >> menuChoice;
        if (menuChoice == "Y")
        {
            gatherSkillSet(schedule, numOfEmployees, dummyEmployeeLoopTime, employeeLoopTime);
        }
    }

    if (menuChoice == "2") {
        editAvailability(schedule, numOfEmployees);
    }

    if (menuChoice == "3") {
        editSkillSet(schedule, numOfEmployees);
    }

    if (menuChoice == "5") {
        viewSkillSet(schedule, numOfEmployees);
    }
    
    if (menuChoice == "4") {
        viewAvailability(schedule, numOfEmployees);
    }

    if (menuChoice == "6") {
        printSchedule(schedule, numOfEmployees, dummyEmployeeLoopTime);

    }

    if (menuChoice == "7") {
        string name, fileType = ".txt";

        menuLoop = false;
        cout << "Closing all files";

        for (int i = 0; i < dummyEmployeeLoopTime; i++)
        {
            name = schedule[i] + fileType;
            remove(name.c_str());
        }
        cout << "\nAll files closed";
        cout << "\nhave a good day!";    
    }
}

return 0;
}

void printSchedule(string schedule[], int arraySize, int dummyEmployeeLoopTime)
{
    string weekDays[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    string availTimes[] = {"Morning", "All Day", "None", "Night"};
    for (int i = 0; i < 7; i++)
    {
        string wordSearch = weekDays[i] + ":", fileText;
        for (int j = 0; i < dummyEmployeeLoopTime; j++)
        {
            ifstream MyFile (schedule[j] + ".txt");
            while (getline(MyFile, fileText))
            {
                if (fileText.find(wordSearch) != string::npos)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if (fileText.find(availTimes[k]) != string::npos)
                        {
                            cout << schedule[j] << availTimes[k] << endl;
                        }
                    }
                }
            }
            MyFile.close();
        }
    }
}


void viewSkillSet(string schedule[], int arraySize)
{
string employee, menuSelect, dummyString;
    //SHOW ALL EMPLOYEES
    cout << "\nHere are all the Employees\n";
    for (int i = 0; i < arraySize; i++)
    {
        if(schedule[i] == "")
        {
            break;
        }
        cout << schedule[i] << endl;
    }

    //INPUT THE SELECTED EMPLOYEE
    cin.ignore();
    cout << "\nWhich employees skill set would you like to view? ";
    getline(cin, employee);
    ifstream MyFile (employee + ".txt");\
    //SHOW THE SKILL SET
    cout << "Heres their Skill Set\n\n";
    while (getline(MyFile, dummyString))
    {
        if(dummyString == "Skill Set")
        {
            cout << dummyString << endl;
            while (getline(MyFile, dummyString))
            {
                cout << dummyString << endl;
            }
        }
    }
    MyFile.close();
}

void editSkillSet(string schedule[], int arraySize)
{
string employee, menuSelect, dummyString;
    //SHOW ALL EMPLOYEES
    cout << "\nHere are all the Employees\n";
    for (int i = 0; i < arraySize; i++)
    {
        if(schedule[i] == "")
        {
            break;
        }
        cout << schedule[i] << endl;
    }
    //INPUT THE SELECTED EMPLOYEE
    cin.ignore();
    cout << "\nWhich employees skill set would you like to edit? ";
    getline(cin, employee);
    ifstream MyFile (employee + ".txt");
    ofstream MyTempFile ("temp.txt");
    ofstream MySecondTempFile ("temp2.txt");
    cout << "Heres their Skills\n";
bool wordTest = true;
    while (getline(MyFile, dummyString))
    {
        if(dummyString == "Skill Set")
        {
            wordTest = false;
            cout << "it turned to false";
        }
        if(wordTest == true)
        {
            MySecondTempFile << dummyString << endl;
        }
        if(dummyString == "Skill Set")
        {
            cout << dummyString << endl;
            MyTempFile << dummyString << endl;
            while(getline(MyFile, dummyString))
            {
                cout << dummyString << endl;
                MyTempFile << dummyString << endl;
            }
        }
    }
    MySecondTempFile.close();
    MyFile.close();
    MyTempFile.close();
    employee += ".txt";
    remove(employee.c_str());
    //INPUT WHICH SKILL TO EDIT
    cout << "\nWhich skill would you like to edit? ";
    getline(cin, menuSelect);
    ofstream EmpSkills (employee);
    ifstream TempFile ("temp.txt");
    ifstream SecondTempFile ("temp2.txt");
string skillSelected = menuSelect + ":";
int skill;
    while (getline(SecondTempFile, dummyString))
    {
        EmpSkills << dummyString << endl;
    }
    while (getline(TempFile, dummyString))
    {
        if(dummyString.find(skillSelected) == string::npos)
        {
            EmpSkills << dummyString << endl;
        }
        if(dummyString.find(skillSelected) != string::npos)
        {
            cout << "\nWhat would you like to change it to from 0 to 10? ";
            cin >> skill;
            EmpSkills << skillSelected << " " << skill << endl;
        }

    }
    EmpSkills.close();
    TempFile.close();
    SecondTempFile.close();
    remove("temp.txt");
    remove("temp2.txt");
    }


/*
Skill set list
1. Salad side
2. Grill side  
3. Stretcher    
4. Pizza line
5. Oven
6. Prep
7. Dishwasher

gatherSkillSet Function Notes
 - While writing to the file, it does not start at the bottom but starts at the beginning and rewrites anything in its way.
*/

void gatherSkillSet(string schedule[], int arraySize, int employeeLoopTime, int employeesAdded)
{
string name, fileType = ".txt";
double skillNum;

    for (int i = employeeLoopTime - employeesAdded; i < employeeLoopTime; i++)
    {
    string dummyString;
        name = schedule[i] + fileType;
        ifstream MyFile (name);
        ofstream TempFile ("temp.txt");
        for (int i = 0; i < 10; i++)
        {
            getline(MyFile, dummyString);
            TempFile << dummyString << endl;
        }
        TempFile << endl;
        MyFile.close();
        remove(name.c_str());
        TempFile.close();
        ofstream Myfile ("temp2.txt");
        Myfile << "Skill Set";
        cout << "Please input a number between 0 - 10 for each skill that pops up for " << schedule[i] << endl;
        cout << "Salad Side: ";
        cin >> skillNum;
        Myfile << "\nSalad Side: " << skillNum;
        cout << "Grill Side: ";
        cin >> skillNum;
        Myfile << "\nGrill Side: " << skillNum;
        cout << "Stretcher: ";
        cin >> skillNum;
        Myfile << "\nStretcher: " << skillNum;
        cout << "Pizza Line: ";
        cin >> skillNum;
        Myfile << "\nPizza Line: " << skillNum;
        cout << "Oven: ";
        cin >> skillNum;
        Myfile << "\nOven: " << skillNum;
        cout << "Prep: ";
        cin >> skillNum;
        Myfile << "\nPrep: " << skillNum;
        cout << "Dishwasher: ";
        cin >> skillNum;
        Myfile << "\nDishwasher: " << skillNum;
        Myfile << endl << endl;
        Myfile.close();
        ifstream Myfile2 ("temp2.txt");
        ifstream TempFile2 ("temp.txt");
        ofstream Myfile3 (name);
        while(getline(TempFile2, dummyString))
        {
            Myfile3 << dummyString << endl;
        }
        while(getline(Myfile2, dummyString))
        {
            Myfile3 << dummyString << endl;
        }
        TempFile2.close();
        Myfile2.close();
        Myfile3.close();

        remove("temp2.txt"); 
        remove("temp.txt");
    }    
}

void viewAvailability( string schedule[], int arraySize)
{
    int choice, numOfEmployees;
    string employeesName, fileType = ".txt", fileText, fileTextTest;
    for (int i = 0; i < arraySize; i++)
    {
        if(schedule[i] != "")
        {
            numOfEmployees += 1;
        }
    }
    cout << "You currently have " << numOfEmployees << " employees" << "." << endl << "Would you like to view all or only one? " << endl;
    cout << "1. all" << endl << "2. One" << endl << "choice: ";
    cin >> choice;
    if (choice == 2)
    {
        cout << "\nPlease enter the name of the employee that you would like to view.\n";
        for (int i = 0; i < numOfEmployees; i++)
        {
            cout << schedule[i] << endl;
        }
        cout << "Name: ";
        cin.ignore();
        getline(cin, employeesName);
        cout << endl;

    employeesName = employeesName + fileType;
    ifstream MyFile (employeesName);  
    
    while (getline(MyFile, fileText))
    {
        if (fileText == "Skill Set")
        {
            break;
        }
        cout << fileText << endl;

    }
    
    MyFile.close();
    }

    if (choice == 1)
    {
        cout << "\nAll the employees are being shown\n" << endl;

        for (int i = 0; i < arraySize; i++)
        {
            if (schedule[i] == "")
            {
                break;
            }
            cout << schedule[i] << " - ";
            employeesName = schedule[i] + fileType;
            ifstream MyFile (employeesName);  
    
            while (getline(MyFile, fileText))
            {
                if (fileText == "Skill Set")
                {
                    break;
                }
                cout << fileText << endl;
            }
            fileText = "";
            cout << endl;
            MyFile.close();
        }
    }

}

void gatherAvailability(string schedule[], int arraySize, int employeeLoopTime)
{
string name, fileType = ".txt", hours, role;

    for (int i = 0; i < employeeLoopTime; i++)
    {
        if (schedule[i] == ""){
        cout << "What is the name of Employee " << i+1 << endl;
        getline(cin, name);
        schedule[i] = name;
        name = name + fileType;
        ofstream MyFile (name);
        cout << "\nWhat is their role in the kitchen? Please input Kitchen Manager or Coworker: ";
        getline(cin, role);
        MyFile << role;
        cout << "\nplease input Morning, Night, All Day, or None";
        cout << "\nEmployees availability\n" << "Monday: ";
        MyFile << "\n\nEmployees availability\n" << "Monday: ";
        getline(cin, hours);
        MyFile << hours;
        cout << "\nTuesday: ";
        MyFile << "\nTuesday: ";
        getline(cin, hours);
        MyFile << hours;
        cout << "\nWednesday: ";
        MyFile << "\nWednesday: ";
        getline(cin, hours);
        MyFile << hours;
        cout << "\nThursday: ";
        MyFile << "\nThursday: ";
        getline(cin, hours);
        MyFile << hours;
        cout << "\nFriday: ";
        MyFile << "\nFriday: ";
        getline(cin, hours);
        MyFile << hours;
        cout << "\nSaturday: ";
        MyFile << "\nSaturday: ";
        getline(cin, hours);
        MyFile << hours;
        cout << "\nSunday: ";
        MyFile << "\nSunday: ";
        getline(cin, hours);
        MyFile << hours;
        MyFile.close();

        }
    }
        return;
}

void editAvailability(string schedule[], int arraySize) {

string day, employee, fileType = ".txt", fileText, change, dummyOne; 
int lineFound = 1, repeatChoice;
bool loop = true;

while (loop)
{

//open the files of the employee that was inputted by the user
//and receive the string that will contain the day that the user wants to change for the employee
    cout << "\nPlease enter the name of the employee that you would like to edit.\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, employee);
    cout << endl;

    employee = employee + fileType;
    ifstream MyFile (employee);
    ofstream OutFile("temp.txt");
    ofstream SecOutFile("second_temp.txt");
    cout << "\nwhat day would you like to edit? ";
    getline(cin, day);
    
    day = day + ":";

//Input the .txt file information into two strings that will be used to edit the original.
    for(int i = 1; i <= 8; i++)
    {
        getline(MyFile, dummyOne); //copy employees hours into a dummy string
        SecOutFile << dummyOne << endl;
        if(dummyOne.find(day) != string::npos)
        {
            lineFound = i;   
        }

    }
    

    SecOutFile.close();
    ifstream ReadSecOutFile("second_temp.txt");

    cout << "What would you like to change it to?";
    getline(cin, change);

    for(int i = 1; i <= 8; i++)
    {
        if(i < lineFound)
        {
            getline(ReadSecOutFile, fileText);
            OutFile << fileText << endl;
        } else if(i == lineFound)
        {
            OutFile << day << " " << change << endl;
            getline(ReadSecOutFile, fileText);
        } else 
        {
            getline(ReadSecOutFile, fileText);
            OutFile << fileText << endl;
        }
        
    }

    ReadSecOutFile.close();
    MyFile.close();
    OutFile.close();
    remove(employee.c_str());
    remove("second_temp.txt");
    rename("temp.txt", employee.c_str());

    cout << "The availability has been changed. Would you like to add another? \n";
    cout << "1. Yes" << endl << "2. No" << endl << "Choice: ";
    cin >> repeatChoice;
    if (repeatChoice == 1)
    {
        loop = true;
    }

    if (repeatChoice == 2)
    {
        loop = false;
        cout << "\nReturning you to the main menu\n";
    }
}

return;
}