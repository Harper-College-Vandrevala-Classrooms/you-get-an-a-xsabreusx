#include "Gradebook.hpp"

void Gradebook::addStudent(const std::string& firstName, const std::string& lastName, int studentID) {
    students.push_back({firstName, lastName, studentID});
}

void Gradebook::addAssignment(const std::string& name, double totalPoints) {
    assignments.push_back({name, totalPoints});
}

void Gradebook::assignGrade(int studentID, const std::string& assignmentName, double grade) {
    grades[studentID][assignmentName] = grade;
}

void Gradebook::printReport() const {
    std::cout << "\nGradebook Report:\n";
    std::cout << "--------------------------------------------------\n";

    // Print header
    std::cout << "Student ID  Name           ";
    for (const auto& assignment : assignments) {
        std::cout << assignment.name << " ";
    }
    std::cout << "\n--------------------------------------------------\n";

    // Print each student's grades
    for (const auto& student : students) {
        std::cout << student.studentID << "  " 
                  << student.firstName << " " << student.lastName << "  ";
        
        for (const auto& assignment : assignments) {
            double grade = grades.at(student.studentID).count(assignment.name) 
                           ? grades.at(student.studentID).at(assignment.name) 
                           : 0.0;
            std::cout << grade << "/" << assignment.totalPoints << "  ";
        }
        std::cout << "\n";
    }
}