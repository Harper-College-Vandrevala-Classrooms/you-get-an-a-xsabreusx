#include <iostream>
#include "Gradebook.hpp"
using namespace std;

int main() {
    Gradebook gb;

    // Add students
    gb.addStudent("John", "Doe", 101);
    gb.addStudent("Jane", "Smith", 102);

    // Add assignments
    gb.addAssignment("Assignment1", 100);
    gb.addAssignment("Assignment2", 50);

    // Assign grades
    gb.assignGrade(101, "Assignment1", 85);
    gb.assignGrade(101, "Assignment2", 40);
    gb.assignGrade(102, "Assignment1", 90);
    gb.assignGrade(102, "Assignment2", 45);

    // Print the report
    gb.printReport();

    cout << "\nProgram closing." << endl;

    return 0;
}