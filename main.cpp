#include <iostream>
#include <limits>
#include "Gradebook.hpp"
using namespace std;

void displayMenu(Gradebook& gb);
int getIntInput(const string& prompt);
double getDoubleInput(const string& prompt);
string getValidAssignmentName(Gradebook& gb);
//void clearConsole();


int main() {

    ///////////// TESTING AREA /////////////////////////////
    Gradebook gb;

    // Add students test
    gb.addStudent("John", "Doe", 101);
    gb.addStudent("Jane", "Smith", 102);

     // Add assignments test
    gb.addAssignment("Homework1", 100);
    gb.addAssignment("ExtraCredit1", 50);

    // Assign grades test
    gb.assignGrade(101, "Homework1", 85);      //ensure that john gets assigned the correct grade of 85 and likewise for Jane of 90
    gb.assignGrade(101, "ExtraCredit1", 90);

    gb.assignGrade(102, "Homework1", 90);
    gb.assignGrade(102, "ExtraCredit1", 45);

    // Print the test report
    gb.printReport();

    /////////// Edge case checks/////////////
    // Assigning a grade to a non-existent student ID:
    gb.assignGrade(103, "Homework2", 100);
    gb.printReport();   

    cout << "\nAll checks passed." << endl;
    /////////////////////////////////////////////////////

    ////////// Run the program //////////

    string enterProgram;
    cout << "\n--- Welcome to Gradebook Application! ---";
    cout << "\n-----------------------------------------";
    cout << "\n\nWould you like to try the application?";
    cout << "\n(Input y for yes. Any other input will be no)";
    cout << "\n\nAwaiting Input: "; 
    cin >> enterProgram;

    if (enterProgram == "y")
    {
        //clearConsole();
        Gradebook gb2;
        displayMenu(gb2);  
        return 0;
    }
    else
    {
        cout << "\nProgram closing. Good bye!";
        return 0;
    }
    

    return 0;
}

///// Function Definitions for trying the program Below  /////

// Menu-driven interface
void displayMenu(Gradebook& gb) {
    int choice = 0;
    while (true) {
        cout << "\n--- Gradebook Menu ---\n";
        cout << "1. Add a new student\n";
        cout << "2. Add a new assignment\n";
        cout << "3. Assign a grade\n";
        cout << "4. Print the report\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";

        choice = getIntInput("");

        switch (choice) {
        case 1: {
            string firstName, lastName;
            int studentID;
            cout << "Enter student's first name: ";
            cin >> firstName;
            cout << "Enter student's last name: ";
            cin >> lastName;
            studentID = getIntInput("Enter student ID: ");
            gb.addStudent(firstName, lastName, studentID);
            cout << "Student added successfully!\n";
            break;
        }
        case 2: {
            string assignmentName;
            double totalPoints;
            cout << "Enter assignment name: ";
            cin >> assignmentName;
            totalPoints = getDoubleInput("Enter total points possible: ");
            gb.addAssignment(assignmentName, totalPoints);
            cout << "Assignment added successfully!\n";
            break;
        }
        case 3: {
            int studentID = getIntInput("Enter student ID: ");
            string assignmentName = getValidAssignmentName(gb);
            double grade = getDoubleInput("Enter grade: ");
            gb.assignGrade(studentID, assignmentName, grade);
            cout << "Grade assigned successfully!\n";
            break;
        }
        case 4:
            gb.printReport();
            break;
        case 5:
            cout << "Exiting the program. Goodbye!\n";
            return;
        default:
            cout << "Invalid option! Please choose a number between 1 and 5.\n";
            break;
        }
    }
}

// Function to safely get integer input with validation
int getIntInput(const string& prompt) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid integer.\n";
        }
        else {
            return input;
        }
    }
}

// Function to safely get double input with validation
double getDoubleInput(const string& prompt) {
    double input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number.\n";
        }
        else {
            return input;
        }
    }
}

// Get a valid assignment name that exists in the Gradebook
string getValidAssignmentName(Gradebook& gb) {
    string assignmentName;
    while (true) {
        cout << "Enter assignment name: ";
        cin >> assignmentName;
        if (gb.assignmentExists(assignmentName)) {
            return assignmentName;
        }
        else {
            cout << "Error: Assignment \"" << assignmentName << "\" does not exist. Try again.\n";
        }
    }
}