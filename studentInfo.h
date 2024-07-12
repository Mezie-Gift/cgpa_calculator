#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <limits>

struct StudentInfo
{
	std :: string name;
	int course_duration;
	int NumOfCourses;
	std :: vector<int> CreditUnit;
	std :: vector<char> grades;

	StudentInfo() : course_duration(0), NumOfCourses(0)
	{}
	StudentInfo(int numCourses) : NumOfCourses(numCourses)
	{
		CreditUnit.resize(course_duration);
		grades.resize(course_duration);
	}
};

#endif /* STUDENTINFO_H */
