/*
	Nguyen, Daniel 
	Dang, Jayson
	Nguyen, Huy

	Project: Grade Report
	CS A250
	Fall 2023
*/

#include "StudentList.h"
#include "InputHandler.h"
#include "OutputHandler.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const string FILE_NAME = "student_data.txt";

void displayMenu();
void processChoice(StudentList& list, double tuitionRate);

int main()
{
	ifstream infile;
	StudentList list;
	double tuitionRate = 0.0;

	infile.open(FILE_NAME);
	createStudentList(infile, list, tuitionRate);
	processChoice(list, tuitionRate);

	cout << endl;
	system("Pause");
	return 0;
}

void displayMenu()
{
	cout << "*** MAIN MENU ***\n\n"
		<< "Select one of the following:\n\n"
		<< "    1: Print all students\n"
		<< "    2: Print student information\n"
		<< "    3: Search student by last name\n"
		<< "    4: Print students by course\n"
		<< "    5: Print sutdents on hold\n"
		<< "    6: Print students to file\n"
		<< "    7: Modify a course number\n"
		<< "    8: To exit\n\n"
		<< "Enter your choice: ";
}

void processChoice(StudentList& list, double tuitionRate)
{
	bool exit = false;
	while (!exit)
	{
		int choice = 0;

		displayMenu();
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
		{
			list.printAllStudents(tuitionRate);
			
			system("Pause");
			cout << endl;
			break;
		}
		case 2:
		{
			int iD = 0;

			cout << "Please enter student's ID: ";
			cin >> iD;
			cout << endl;

			list.printStudentByID(iD, tuitionRate);

			system("Pause");
			cout << endl;
			break;
		}
		case 3:
		{
			string lastName;

			cout << "Please enter the student's last name: ";
			cin >> lastName;
			cout << endl;

			list.printStudentByName(lastName);

			system("Pause");
			cout << endl;
			break;
		}
		case 4:
		{
			string prefix;
			int courseNo = 0;

			cout << "Please enter the course prefix: ";
			cin >> prefix;
			cout << "Please enter the course number: ";
			cin >> courseNo;
			cout << endl;

			list.printStudentsByCourse(prefix, courseNo);

			system("Pause");
			cout << endl;
			break;
		}
		case 5:
		{
			list.printStudentsOnHold(tuitionRate);

			system("Pause");
			cout << endl;
			break;
		}
		case 6:
		{
			printAllStudentsToFile(list, tuitionRate);
			cout << endl;

			system("Pause");
			cout << endl;
			break;
		}
		case 7:
		{
			string prefix;
			int courseNo = 0;
			int newCourseNo = 0;

			cout << "Please enter the course prefix: ";
			cin >> prefix;
			cout << "Please enter the course number: ";
			cin >> courseNo;
			cout << "Please enter the new course number: ";
			cin >> newCourseNo;
			cout << endl;

			list.modifyCourseNumber(prefix, courseNo, newCourseNo);

			system("Pause");
			cout << endl;
			break;
		}
		case 8:
		{
			exit = true;
			cout << "Thank you for using the OCC Gradebook. Good-bye!\n";
			break;
		}
		default:
			cout << "Sorry. That is not a selection.\n\n";

			system("Pause");
			cout << endl;
		}
	}
}