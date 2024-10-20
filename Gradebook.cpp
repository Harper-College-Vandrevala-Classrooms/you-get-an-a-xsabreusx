#include "Gradebook.hpp"

void Gradebook::addStudent(const string& firstName, const string& lastName, int studentID) 
{
    students.push_back({firstName, lastName, studentID});
}

void Gradebook::addAssignment(const string& assignmentName, double totalPoints) 
{
    assignments.push_back({assignmentName, totalPoints});
}

void Gradebook::assignGrade(int studentID, const string& assignmentName, double grade) 
{
    grades[studentID][assignmentName] = grade;
}

// Prins an aesthetically pleasing report
void Gradebook::printReport() const {
    
    cout << "\nGradebook Report:\n";
    cout << "------------------------------------------------------------------\n";

    // Print thi header
    cout << "Student ID | Name | ";
    for (const auto& assignment : assignments) {
        cout << assignment.name << " | ";
    }
    cout << "\n------------------------------------------------------------------\n";

    // Print each student's grades
    for (const auto& student : students) {
        cout << student.studentID << " | "
                  << student.firstName << " " << student.lastName << " | ";

        for (const auto& assignment : assignments) {
            double grade = grades.at(student.studentID).count(assignment.name)
                           ? grades.at(student.studentID).at(assignment.name)
                           : 0.0;
            cout << grade << "/" << assignment.totalPoints << " | ";
        }
        cout << "\n";
    }
}

bool Gradebook::assignmentExists(const string& name) const {
    for (const auto& assignment : assignments) {
        if (assignment.name == name) {
            return true;
        }
    }
    return false;
}

