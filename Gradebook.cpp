#include "Gradebook.hpp"

void Gradebook::addStudent(const string& firstName, const string& lastName, int studentID) {
    students.push_back({ firstName, lastName, studentID });
}

void Gradebook::addAssignment(const string& name, double totalPoints) {
    assignments.push_back({ name, totalPoints });
}

bool Gradebook::assignmentExists(const string& name) const {
    for (const auto& assignment : assignments) {
        if (assignment.name == name) {
            return true;
        }
    }
    return false;
}

void Gradebook::assignGrade(int studentID, const string& assignmentName, double grade) {
    if (!assignmentExists(assignmentName)) {
        cerr << "Error: Assignment \"" << assignmentName << "\" does not exist.\n";
        return;
    }
    grades[studentID][assignmentName] = grade;
}

void Gradebook::printReport() const {
    cout << "\nGradebook Report:\n";
    cout << "--------------------------------------------------\n";

    // Print the header row with assignment names
    cout << "Student ID  Name           ";
    for (const auto& assignment : assignments) {
        cout << assignment.name << " ";
    }
    cout << "\n--------------------------------------------------\n";

    // Print each student's grades safely
    for (const auto& student : students) {
        cout << student.studentID << "  "
            << student.firstName << " " << student.lastName << "  ";

        for (const auto& assignment : assignments) {
            // Safely access the grade using .find() to avoid exceptions
            auto studentGrades = grades.find(student.studentID);
            if (studentGrades != grades.end()) {
                auto gradeIt = studentGrades->second.find(assignment.name);
                if (gradeIt != studentGrades->second.end()) {
                    cout << gradeIt->second << "/" << assignment.totalPoints << "  ";
                }
                else {
                    cout << "0/" << assignment.totalPoints << "  ";  // No grade assigned
                }
            }
            else {
                cout << "0/" << assignment.totalPoints << "  ";  // No grades for this student
            }
        }
        cout << "\n";
    }
}

