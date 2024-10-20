#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

 //Note: This gradebook class contains a map and two vectors each with their own structures defined above. 
 //The idea is to create a map of a map, which is a map which contains IDs of students, 
 //and then each ID has a map of the assignments, which in turn have grades. 
 //This is an idea that I thought was very neat, and hoped to implement successfully. 
 //The toughest thing was creating appropriate tests, so I will run the tests as best as possible in the driver.

struct Student {
    string firstName;
    string lastName;
    int studentID;
};

struct Assignment {
    string name;
    double totalPoints;
};

class Gradebook {
private:
    vector<Student> students;
    vector<Assignment> assignments;
    map<int, map<string, double>> grades;  // studentID -> (assignmentName -> grade)

public:
    void addStudent(const string& firstName, const string& lastName, int studentID);
    void addAssignment(const string& name, double totalPoints);
    void assignGrade(int studentID, const string& assignmentName, double grade);
    void printReport() const;
    bool assignmentExists(const string& name) const;  // Checks if assignment exists
};