/*
	Nguyen, Daniel (Team Leader)
	Dang, Jayson
	Nguyen, Huy

	Project: Grade Report
	CS A250
	Fall 2023
*/

#include "Course.h"

using namespace std;

void Course::setCourseInfo(const string& aPrefix, int aNumber, int aUnits)
{
	coursePrefix = aPrefix;
	courseNumber = aNumber;
	courseUnits = aUnits;
}

string Course::getCoursePrefix() const
{
	return coursePrefix;
}

int Course::getCourseNumber() const 
{
	return courseNumber;
}

int Course::getCourseUnits() const
{
	return courseUnits;
}

bool Course::operator<(const Course& otherCourse) const
{
	if (coursePrefix == otherCourse.coursePrefix)
	{
		return courseNumber < otherCourse.courseNumber;
	}
	return coursePrefix < otherCourse.coursePrefix;
}