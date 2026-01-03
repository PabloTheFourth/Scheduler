//  12-23-25: In the future we need to add a feature that puts all the text files in a folder.

//12-29-25
/*
1. I need to add a feature that declares whether an employee is a manager or co worker - DONE

2. I need to add categories to the kitchen to see how good each person is in those categories 
    for example - Grill side, Salad Side, Pizza line, Pizza strecter, and prep.

3. Add a system that can detect what shift each person can work and turn those into "Hour Sectors".
    for example - Morning could be 8am-3pm and for a Manager it could be 7am-4pm
    ----------------------------------------------------------------------------------------
    After these sections have been done, only than can i start on the system that can 
    schedule the employees based on those variables
*/



#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;

void gatherAvailability(string schedule[],int arraySize, int employeeLoopTime);
void gatherSkillSet(string schedule[], int arraySize, int employeeLoopTime, int employeesAdded);
void editAvailability(string schedule[], int arraySize);
void viewAvailability( string schedule[], int arraySize);

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
    cout << "3. View an employees availability\n";
    cout << "4. Turn Off\n";
    cout << "Choice: ";
    cin >> menuChoice;

    if (menuChoice == "1") {
        cout << "How many Employess are we adding? ";
        cin >> employeeLoopTime;
        dummyEmployeeLoopTime += employeeLoopTime;
        cin.ignore();
        //string schedule[numOfEmployees]; //I need to fix this - its only updating the array within the function and not the whole program
        /*
        i fixed it bro
        */
    
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
        viewAvailability(schedule, numOfEmployees);
    }

    if (menuChoice == "4") {
        string name, fileType = ".txt";

        menuLoop = false;
        cout << "Closing all files";

        for (int i = 0; i < dummyEmployeeLoopTime; i++)
        {
            name = schedule[i] + fileType;
            remove(name.c_str());
        }
        cout << "All files closed";
        cout << "have a good day!";    
    }
}

return 0;
}

void gatherSkillSet(string schedule[], int arraySize, int employeeLoopTime, int employeesAdded)
{
string name;

    for (int i = employeeLoopTime - employeesAdded; i < employeeLoopTime; i++)
    {
        name = schedule[i];
        cout << endl << endl << name;
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
    cout << "You currently have " << numOfEmployees << "." << endl << "Would you like to view all or only one? " << endl;
    cout << "1. all" << endl << "2. One" << endl << "choice: ";
    cin >> choice;
    if (choice == 2)
    {
        cout << "\nPlease enter the name of the employee that you would like to view.\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, employeesName);
        cout << endl;

    employeesName = employeesName + fileType;
    ifstream MyFile (employeesName);  
    
    while (getline(MyFile, fileText))
    {
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