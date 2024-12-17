/*
	Nguyen, Daniel (Team Leader)
	Dang, Jayson
	Nguyen, Huy

	Project: Grade Report
	CS A250
	Fall 2023
*/

#include "Student.h"

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void Student::setStudent(const Student& otherStudent)
{
	studentID = otherStudent.studentID;
	firstName = otherStudent.firstName;
	lastName = otherStudent.lastName;
	numberOfCourses = otherStudent.numberOfCourses;
	tuitionWasPaid = otherStudent.tuitionWasPaid;
	coursesCompleted = otherStudent.coursesCompleted;
}

void Student::setStudentInfo(int aStudentID, const string& aFirstName,
	const string& aLastName, bool paid, const multimap<Course, 
	char>& allCourseInfo)
{
	studentID = aStudentID;
	firstName = aFirstName;
	lastName = aLastName;
	numberOfCourses = static_cast<int>(allCourseInfo.size());
	tuitionWasPaid = paid;
	coursesCompleted = allCourseInfo;
}

int Student::getID() const
{
	return studentID;
}

const string Student::getFirstName() const
{
	return firstName;
}

const string Student::getLastName() const
{
	return lastName;
}

void Student::getName(string& first, string& last) const
{
	first = firstName;
	last = lastName;
}

int Student::getNumberOfCourses() const
{
	return numberOfCourses;
}

int Student::getUnitsCompleted() const
{
	int sum = 0;
	for (auto courseInfo : coursesCompleted)
	{
		sum += courseInfo.first.getCourseUnits();
	}
	return sum;
}

multimap<Course, char>& Student::getCoursesCompleted()
{
	return coursesCompleted;
}

bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

bool Student::isCourseCompleted(const string& prefix, int courseNumber) const
{
	if (coursesCompleted.size() == 0)
	{
		return false;
	}
	else
	{
		for (auto courseInfo : coursesCompleted)
		{
			if (courseInfo.first.getCoursePrefix() == prefix &&
				courseInfo.first.getCourseNumber() == courseNumber)
				return true;
		}
	}

	return false;
}

double Student::calculateGPA() const
{
	double sum = 0.00;
	for (auto courseInfo : coursesCompleted)
	{
		if (courseInfo.second == 'A')
			sum += (4.00 * courseInfo.first.getCourseUnits());
		else if (courseInfo.second == 'B')
			sum += (3.00 * courseInfo.first.getCourseUnits());
		else if (courseInfo.second == 'C')
			sum += (2.00 * courseInfo.first.getCourseUnits());
		else if (courseInfo.second == 'D')
			sum += (1.00 * courseInfo.first.getCourseUnits());
	}
	return sum / getUnitsCompleted();
}

double Student::billingAmount(double tuitionRate) const
{
	return static_cast<double>(coursesCompleted.size()) * tuitionRate;
}

void Student::printStudent() const
{
	cout << studentID << " - " << lastName << ", " << firstName << endl;
}

void Student::printStudentInfo(double tuitionRate) const
{
	cout << "Student Name: " << lastName << ", " << firstName << "\n"
		<< "Student ID: " << studentID << "\n"
		<< "Number of courses completed: " << coursesCompleted.size()
		<< "\n\n" << "CourseNo  Units  Grade\n";

	for (auto courseInfo : coursesCompleted)
	{
		cout << left << setw(5) << courseInfo.first.getCoursePrefix()
			<< courseInfo.first.getCourseNumber() << right << setw(5)
			<< courseInfo.first.getCourseUnits()<< setw(7) 
			<< courseInfo.second << endl;
	}

	cout << "\nTotal number of credit hours: " << getUnitsCompleted() << endl;
		
	if (tuitionWasPaid)
		cout << "Current Term GPA: " << fixed << setprecision(2) << calculateGPA();
	else
		cout << "*** Grades are being held for not paying tuition. ***\n"
			<< "Amount Due: $" << fixed << setprecision(2) << billingAmount(tuitionRate);
	cout << "\n\n" << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n";
}