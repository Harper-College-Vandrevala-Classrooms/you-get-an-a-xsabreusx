#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

struct Student {
    std::string firstName;
    std::string lastName;
    int studentID;
};

struct Assignment {
    std::string name;
    double totalPoints;
};

class Gradebook 
{
private:
    std::vector<Student> students;
    std::vector<Assignment> assignments;
    std::map<int, std::map<std::string, double>> grades;  // studentID -> (assignmentName -> grade)

public:
    void addStudent(const std::string& firstName, const std::string& lastName, int studentID);
    void addAssignment(const std::string& name, double totalPoints);
    void assignGrade(int studentID, const std::string& assignmentName, double grade);
    void printReport() const;
};

#endif  // GRADEBOOK_H