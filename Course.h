/*
	Nguyen, Daniel (Team Leader)
	Dang, Jayson
	Nguyen, Huy

	Project: Grade Report
	CS A250
	Fall 2023
*/

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <map>

class Course
{
public:
	Course() : coursePrefix("N/A"), courseNumber(0), courseUnits(0) {}
	Course(const std::string& nPrefix, int nCourseNumber, int nCourseUnits) 
		: coursePrefix(nPrefix), courseNumber(nCourseNumber), courseUnits(nCourseUnits) {}

	void setCourseInfo(const std::string& aPrefix, int aNumber, int aUnits);

	std::string getCoursePrefix() const;
	int getCourseNumber() const;
	int getCourseUnits() const;

	bool operator<(const Course& otherCourse) const;

	~Course() {}

private:
	std::string coursePrefix;
	int courseNumber;
	int courseUnits;
};

#endif