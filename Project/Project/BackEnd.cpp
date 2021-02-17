#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "BackEnd.h"
using namespace std;
int idSt = 0;
int idTeach = 0;
int idTeam = 0;
int idSch = 1;
STUDENT makeNewStudent()
{
	int temp;
	STUDENT student;
	student.id = idSt;
	idSt++;
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

TEACHER makeNewTeacher()
{
	TEACHER t;
	cin >> t.name.firstName;
	cin >> t.name.lastName;
	cin >> t.email;
	return t;
}
void insertNewTeacher(SCHOOL& sch, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		sch.teachers.push_back(makeNewTeacher());
	}
}
TEAM makeNewTeam(SCHOOL& sch)
{
	TEAM team;
	int temp;
	cout << "ID of teacher: "; cin >> temp;
	team.teacher = sch.teachers[temp];
	cout << "How many students in team? "; cin >> temp;
	int a;
	for (int i = 0; i < temp; i++)
	{
		cout << "ID of student: "; cin >> a;
		team.participants.push_back(sch.students[a]);
	}
	cin >> team.desc;
	time_t curr_time;
	curr_time = time(NULL);
	tm* ltm = new tm;
	localtime_s(ltm,&curr_time);
	team.dateOfCreation.s = ltm->tm_sec;
	team.dateOfCreation.m = ltm->tm_min;
	team.dateOfCreation.h = ltm->tm_hour;
	team.dateOfCreation.d = ltm->tm_mday;
	team.dateOfCreation.mo = ltm->tm_mon;
	team.dateOfCreation.y = ltm->tm_year;
	cin >> temp;
	switch (temp)
	{
	case 0:
		team.status = NOT_ACTIVE;
		break;
	case 1:
		team.status = IN_USE;
		break;
	case 2:
		team.status = ARCHIVED;
		break;
	default:
		throw "Incorrect input";
		break;
	}
	return team;
}
void insertNewTeam(SCHOOL& sch, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		sch.teams.push_back(makeNewTeam(sch));
	}
}