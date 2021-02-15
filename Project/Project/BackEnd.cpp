#include <iostream>
#include <string>
#include <vector>
#include "BackEnd.h"
using namespace std;

STUDENT makeNewStudent()
{
	int temp;
	STUDENT student;
	cin >> student.name.firstName;
	cin >> student.name.lastName;
	cin >> student.age;
	cin >> student.grade;
	cin >> temp;
	switch (temp)
	{
	case 0:
		student.status = FREE;
		break;
	case 1:
		student.status = IN_TEAM;
		break;
	case 2:
		student.status = UNAVAILABLE;
		break;
	case 3:
		student.status = LOOKING;
		break;
	default:
		throw "Incorrect input";
		break;
	}
	cin >> temp;
	switch (temp)
	{
	case 0:
		student.teamRole = SCRUM_TRAINER;
		break;
	case 1:
		student.teamRole = BACKEND_DEV;
		break;
	case 2:
		student.teamRole = FRONTEND_DEV;
		break;
	case 3:
		student.teamRole = QA_ENGI;
		break;
	default:
		throw "Incorrect input";
		break;
	}
	cin >> student.email;
	return student;

}

void insertNewStudent(SCHOOL& sch, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		sch.students.push_back(makeNewStudent());
	}
}