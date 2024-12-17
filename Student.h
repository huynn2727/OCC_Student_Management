/*
	Nguyen, Daniel (Team Leader)
	Dang, Jayson
	Nguyen, Huy

	Project: Grade Report
	CS A250
	Fall 2023
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"

#include <string>
#include <map>

class Student
{
public:
	Student() : studentID(0), firstName("N/A"), lastName("N/A"),
		numberOfCourses(0), tuitionWasPaid(false) {}
	
	void setStudent(const Student& otherStudent);
	void setStudentInfo(int aStudentID, const std::string& aFirstName,
		const std::string& aLastName, bool paid, const std::multimap<Course, 
		char>& allCourseInfo);

	int getID() const;
	const std::string getFirstName() const;
	const std::string getLastName() const;
	void getName(std::string& first, std::string& last) const;
	int getNumberOfCourses() const;
	int getUnitsCompleted() const;
	std::multimap<Course, char>& getCoursesCompleted();
	
	bool isTuitionPaid() const;
	bool isCourseCompleted(const std::string& prefix, int courseNumber) const;

	double calculateGPA() const;
	double billingAmount(double tuitionRate) const;
	
	void printStudent() const;
	void printStudentInfo(double tuitionRate) const;

	~Student() {}

private:
	int studentID;
	std::string firstName;
	std::string lastName;
	int numberOfCourses;
	bool tuitionWasPaid;
	std::multimap<Course, char> coursesCompleted;
};

#endif