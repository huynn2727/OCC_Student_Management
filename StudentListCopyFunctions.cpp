/*
	Nguyen, Daniel (Team Leader)
	Dang, Jayson
	Nguyen, Huy

	Project: Grade Report
	CS A250
	Fall2023
*/

#include "StudentList.h"

#include <iostream>

using namespace std;

StudentList::StudentList(const StudentList& otherStudent)
{
	first = nullptr;
	last = nullptr;
	count = 0;

	Node* otherCurrent = otherStudent.first;
	Node* current = nullptr;
	while (otherCurrent != nullptr)
	{
		Node* newNode = new Node(otherCurrent->getStudent(), nullptr);

		if (first == nullptr)
		{
			first = newNode;
			last = newNode;
			current = first;
		}
		else
		{
			current->setNext(newNode);
			current = newNode;
			last = newNode;
		}

		otherCurrent = otherCurrent->getNext();
		count++;
	}
}

StudentList& StudentList::operator=(const StudentList& otherStudent)
{
	if (this == &otherStudent)
	{
		cerr << "Attempted assignment to itself." << endl;
	}
	else if (otherStudent.count == 0)
	{
		clearStudentList();
	}
	else if (this->count == 0)
	{
		copyCallingObjIsEmpty(otherStudent);
	}
	else if (this->count == otherStudent.count)
	{
		copyObjectsSameLength(otherStudent);
	}
	else if (this->count > otherStudent.count)
	{
		copyCallingObjLonger(otherStudent);
	}
	else if (this->count < otherStudent.count)
	{
		copyCallingObjShorter(otherStudent);
	}

	return *this;
}

void StudentList::copyCallingObjIsEmpty(const StudentList& otherStudent)
{
	first = nullptr;
	last = nullptr;
	count = 0;

	Node* otherCurrent = otherStudent.first;
	Node* current = nullptr;

	while (otherCurrent != nullptr)
	{
		Node* newNode = new Node(otherCurrent->getStudent(), nullptr);

		if (first == nullptr)
		{
			first = newNode;
			last = newNode;
			current = first;
		}
		else
		{
			current->setNext(newNode);
			current = newNode;
			last = newNode;
		}

		otherCurrent = otherCurrent->getNext();
		count++;
	}
}

void StudentList::copyObjectsSameLength(const StudentList& otherStudent)
{
	Node* otherCurrent = otherStudent.first;
	Node* current = first;

	while (otherCurrent != nullptr && current != nullptr)
	{
		current->setStudent(otherCurrent->getStudent());
		last = current;

		otherCurrent = otherCurrent->getNext();
		current = current->getNext();
	}
}

void StudentList::copyCallingObjLonger(const StudentList& otherStudent)
{
	Node* otherCurrent = otherStudent.first;
	Node* current = first;

	while (otherCurrent != nullptr)
	{

		current->setStudent(otherCurrent->getStudent());
		last = current;

		current = current->getNext();
		otherCurrent = otherCurrent->getNext();
	}

	while (current != nullptr)
	{
		Node* temp = current;
		current = current->getNext();
		delete temp;
	}
	last->setNext(nullptr);
}

void StudentList::copyCallingObjShorter(const StudentList& otherStudent)
{
	Node* otherCurrent = otherStudent.first;
	Node* current = first;

	while (current != nullptr)
	{
		last = current;

		current = current->getNext();
		otherCurrent = otherCurrent->getNext();
	}

	while (otherCurrent != nullptr)
	{
		Node* newNode = new Node();
		last->setNext(newNode);
		last = newNode;

		otherCurrent = otherCurrent->getNext();
	}
	copyObjectsSameLength(otherStudent);
}