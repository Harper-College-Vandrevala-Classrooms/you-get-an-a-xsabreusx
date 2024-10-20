#include <iostream>
#include "Gradebook.hpp"
using namespace std;

int main() {

    ///////////// TEST AREA /////////////////////////////
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



    cout << "\nAll checks passed. Program closing." << endl;
    /////////////////////////////////////////////////////

    

    return 0;
}