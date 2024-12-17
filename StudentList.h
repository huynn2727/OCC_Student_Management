/*
	Nguyen, Daniel (Team Leader)
	Dang, Jayson
	Nguyen, Huy

	Project: Grade Report
	CS A250
	Fall 2023
*/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <string>

class Node
{
public:
    Node() : student(), next(nullptr) {}
    Node(Student newStudent, Node* newNext)
        : student(newStudent), next(newNext) {}
    Node* getNext() const;
    Student& getStudent();
    void setNext(Node* newNext);
    void setStudent(const Student& newStudent);
    ~Node() {}
private:
    Student student;
    Node* next;
};

class StudentList
{
public:
    StudentList() : first(nullptr), last(nullptr), count(0) {}
    StudentList(const StudentList& otherStudent);

    StudentList& operator=(const StudentList& otherStudent);

    void addStudent(const Student& aStudent);
    void modifyCourseNumber(const std::string& prefix, int courseNumber, 
        int newCourseNumber);

    int getNoOfStudents() const;

    void printStudentByID(int ID, double tuitionRate) const;
    void printStudentByName(const std::string& lastName) const;
    void printStudentsByCourse(const std::string& prefix, int courseNumber) const;
    void printAllStudents(double tuitonRate) const;
    void printStudentsOnHold(double tuitionRate) const;
    void printStudentsToFile(std::ofstream& out, double tuitionRate) const;

    void clearStudentList();

    ~StudentList();

private:
    Node* first;
    Node* last;
    int count;

    void copyCallingObjIsEmpty(const StudentList& otherStudent);
    void copyObjectsSameLength(const StudentList& otherStudent);
    void copyCallingObjLonger(const StudentList& otherStudent);
    void copyCallingObjShorter(const StudentList& otherStudent);

};

#endif