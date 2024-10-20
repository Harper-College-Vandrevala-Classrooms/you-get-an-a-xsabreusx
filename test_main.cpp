/*
This file is not needed, it's only for testing purposes.
*/

#include "Gradebook.hpp"
using namespace std;

void displayMenu(Gradebook& gb); // Function declarations
int getIntInput(const string& prompt);
double getDoubleInput(const string& prompt);
void clearConsole();

int main() {

    string enterProgram;
    cout << "\nWelcome to Gradebook Application!";
    cout << "\nWould you like to try the application?";
    cout << "\n(Input y for yes. Any other input will be no)";
    cout << "\nChoice: "; 
    cin >> enterProgram;

    if (enterProgram == "y")
    {
        clearConsole();
        Gradebook gb;
        displayMenu(gb);  
        return 0;
    }
    else
    {
        cout << "\nProgram closing. Good bye!";
        return 0;
    }

}

///// Function Definitions for trying the program Below  /////

void clearConsole() {
    cout << "\033[2J\033[H";  // Clear screen and move the cursor to the top left
}

// Implementing a menu-driven interface
void displayMenu(Gradebook& gb) 
{
    int choice = 0;
    while (true) 
    {
        cout << "\n--- Gradebook Menu ---\n";
        cout << "1. Add a new student\n";
        cout << "2. Add a new assignment\n";
        cout << "3. Assign a grade\n";
        cout << "4. Print the report\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";

        choice = getIntInput("");  // Get a valid integer input

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
                string assignmentName;
                double grade;

                cout << "Enter assignment name: ";
                cin >> assignmentName;
                grade = getDoubleInput("Enter grade: ");
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

// Function to get Integer inputs + prompt message implementation
int getIntInput(const string& prompt) {

    int input;

    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail()) 
        {
            cin.clear();  
            cin.ignore();  
            cout << "Invalid input! Please enter a valid integer: \n";
        } else {
            return input;
        }
    }
}

// Function to get double input + prompt message
double getDoubleInput(const string& prompt) {

    double input;

    while (true) {

        cout << prompt;
        cin >> input;

        if (cin.fail()) 
        {
            cin.clear();  
            cin.ignore();
            cout << "Invalid input! Please enter a valid number.\n";
        } 
        else 
        {
            return input;
        }
    }
}