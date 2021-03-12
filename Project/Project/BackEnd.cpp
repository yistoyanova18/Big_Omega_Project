#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "BackEnd.h"
using namespace std;
int idSt = 0;
int idTeach = 0;
int idTeam = 0;
int idSch = 1;

string Add0BeforeIntSmallerThan10(int num)
{
	string st = "";
	if (num < 10 and num >= 0)
		st += L'0';
	st += to_string(num);
	return st;
}
bool LOG::openFile(string filename)
{
	logFile.open(filename, ios::out | ios::app);
	return logFile.is_open();
}
void LOG::closeFile()
{
	logFile.close();
}
void LOG::createLog(string msg, SEVERITY sev)
{
	tm ltm = LOGTIME::getTimeDate();
	LOGTIME time = { ltm.tm_sec,ltm.tm_min,ltm.tm_hour,ltm.tm_mday,ltm.tm_mon,ltm.tm_year + 1900 };
	string sever;
	switch (sev)
	{
	case INFO:
		sever = "INFO    ";
		break;
	case WARNING:
		sever = "WARNING ";
		break;
	case ERROR:
		sever = "ERROR   ";
		break;
	case CRITICAL:
		sever = "CRITICAL";
		break;
	case DEBUG:
		sever = "DEBUG   ";
		break;
	default:
		break;
	}
	if (sev <= logLevel)
		logFile << Add0BeforeIntSmallerThan10(time.y) << '-' << Add0BeforeIntSmallerThan10(time.mo) << '-' << Add0BeforeIntSmallerThan10(time.md) << " "
		<< Add0BeforeIntSmallerThan10(time.h) << ':' << Add0BeforeIntSmallerThan10(time.m) << ':' << Add0BeforeIntSmallerThan10(time.s) << " "
		<< sever << " "
		<< msg << endl;
}
void LOG::debug(string msg, SEVERITY sev)
{
	LOG::createLog(msg, sev);
}
void LOG::info(string msg, SEVERITY sev)
{
	LOG::createLog(msg, sev);
}
void LOG::warning(string msg, SEVERITY sev)
{
	LOG::createLog(msg, sev);
}
void LOG::error(string msg, SEVERITY sev)
{
	LOG::createLog(msg, sev);
}
void LOG::critical(string msg, SEVERITY sev)
{
	LOG::createLog(msg, sev);
}

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
		student.status = "Free";
		break;
	case 1:
		student.status = "In team";
		break;
	case 2:
		student.status = "Unavailable";
		break;
	case 3:
		student.status = "Looking";
		break;
	default:
		throw "Incorrect input";
		break;
	}
	cin >> temp;
	switch (temp)
	{
	case 0:
		student.teamRole = "Scrum trainer";
		break;
	case 1:
		student.teamRole = "Backend developer";
		break;
	case 2:
		student.teamRole = "Frontend developer";
		break;
	case 3:
		student.teamRole = "QA Engineer";
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
	t.id = idTeach;
	idTeach++;
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
	team.id = idTeam;
	idTeam++;
	int temp;
	cout << "ID of teacher: "; cin >> temp;
	team.teacher = sch.teachers[temp];
	cout << "How many students are in the team? "; cin >> temp;
	int a;
	for (int i = 0; i < temp; i++)
	{
		cout << "ID of student: "; cin >> a;
		sch.students[a].status = "In team";
		team.participants.push_back(a);
	}
	cin >> team.desc;

	tm ltm = LOGTIME::getTimeDate();
	team.dateOfCreation.s = ltm.tm_sec;
	team.dateOfCreation.m = ltm.tm_min;
	team.dateOfCreation.h = ltm.tm_hour;
	team.dateOfCreation.d = ltm.tm_mday;
	team.dateOfCreation.mo = ltm.tm_mon;
	team.dateOfCreation.y = (ltm.tm_year+1900);
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

STUDENT editStudent(STUDENT student, LOG& log)
{
	STUDENT newStudent = student;
	int temp;
	
	system("CLS");
	cout << endl << endl << endl;
	cout << "                ________________________ " << endl;
	cout << "               |     EDITING STUDENT    |" << endl;
	cout << "               |  1. Name               |" << endl;
	cout << "               |  2. Age                |" << endl;
	cout << "               |  3. Grade              |" << endl;
	cout << "               |  4. Status             |" << endl;
	cout << "               |  5. Team role          |" << endl;
	cout << "               |  6. E-mail             |" << endl;
	cout << "               |________________________|" << endl;

	cout << "       Enter your choice: ";
	do
	{
		cin >> temp;
		switch (temp)
		{
		case 1:
			cout << "\n";
			cin >> newStudent.name.firstName >> newStudent.name.lastName;
			break;
		case 2:
			cin >> newStudent.age;
			break;
		case 3:
			cin >> newStudent.grade;
			break;
		case 4:
			cin >> temp;
			switch (temp)
			{
			case 0:
				newStudent.status = "Free";
				break;
			case 1:
				newStudent.status = "In team";
				break;
			case 2:
				newStudent.status = "Unavailable";
				break;
			case 3:
				newStudent.status = "Looking";
				break;
			default:
				log.error("Incorrect input in student edit func");
				break;
			}
			break;
		case 5:
			cin >> temp;
			switch (temp)
			{
			case 0:
				newStudent.teamRole = "Scrum trainer";
				break;
			case 1:
				newStudent.teamRole = "Backend developer";
				break;
			case 2:
				newStudent.teamRole = "Frontend developer";
				break;
			case 3:
				newStudent.teamRole = "QA Engineer";
				break;
			default:
				log.error("Incorrect input in student edit func");
				break;
			}
			break;
		case 6:
			cin >> newStudent.email;
			break;
		default:
			log.error("Incorrect input in student edit func");
			break;
		}
		
		system("CLS");
		cout << endl << endl << endl;
		cout << "                ________________________ " << endl;
		cout << "               |    Would you like to   |" << endl;
		cout << "               |   edit anything else?  |" << endl;
		cout << "               |  1. Yes                |" << endl;
		cout << "               |  0. No                 |" << endl;
		cout << "               |________________________|" << endl;

		cout << "       Enter your choice: ";
		
		cin >> temp;
	} while (temp);
	return newStudent;
}
void saveEditedStudent(SCHOOL& sch, size_t n,LOG& log)
{
	sch.students[n] = editStudent(sch.students[n],log);
	log.info("Successfully edited student");
}

TEACHER editTeacher(TEACHER teacher, LOG& log)
{
	TEACHER newTeacher = teacher;
	int temp;
	system("CLS");
	cout << endl << endl << endl;
	cout << "                ________________________ " << endl;
	cout << "               |     EDITING TEACHER    |" << endl;
	cout << "               |  1. Name               |" << endl;
	cout << "               |  2. E-mail             |" << endl;
	cout << "               |________________________|" << endl; 
	cout << "       Enter your choice: "; cin >> temp;
	switch (temp)
	{
	case 1:
		cin >> newTeacher.name.firstName >> newTeacher.name.lastName;
		break;
	case 2:
		cin >> newTeacher.email;
		break;
	default:
		log.error("Incorrect input in teacher function");
		break;
	}
	return newTeacher;
}
void saveEditedTeacher(SCHOOL& sch, size_t n, LOG& log)
{
	sch.teachers[n] = editTeacher(sch.teachers[n], log);
	log.info("Successfully edited student");
}

TEAM editTeam(SCHOOL& sch, TEAM team, LOG& log)
{
	TEAM newTeam = team;
	int temp;
	cout << "What do you want to edit?\n1. Teacher\n2. Description\n3. Status\n4. Participants\n\n:";
	system("CLS");
	cout << endl << endl << endl;
	cout << "                ________________________ " << endl;
	cout << "               |      EDITING TEAM      |" << endl;
	cout << "               |  1. Teacher            |" << endl;
	cout << "               |  2. Description        |" << endl;
	cout << "               |  3. Status             |" << endl;
	cout << "               |  4. Participants       |" << endl;
	cout << "               |________________________|" << endl;

	cout << "       Enter your choice: ";
	cin >> temp;
	switch (temp)
	{
	case 1:
		cout << endl << "ID of new teacher: "; cin >> temp;
		newTeam.teacher = sch.teachers[temp];
		break;
	case 2:
		cout << endl << "New description of team: \n"; cin >> temp;
		newTeam.desc = temp;
		break;
	case 3:
		cout << endl << "New Status of team(1,2,3): " << endl;
		cout << "       1. Not active " << endl;
		cout << "       2. In use " << endl;
		cout << "       3. Archived " << endl;
		cout << "       Enter your choice: ";
		cin >> temp;
		switch (temp)
		{
		case 1:
			newTeam.status = STATUS::NOT_ACTIVE;
			break;
		case 2:
			newTeam.status = STATUS::IN_USE;
			break;
		case 3:
			newTeam.status = STATUS::ARCHIVED;
			break;
		default:
			log.error("Incorrect input in teacher edit function");
			break;
		}
		break;
	case 4:
		int temp1;
		cout << endl << " Enter the ID of the student you want to change that is currently in the team: "; cin >> temp; 
		cout << endl << " Enter the ID of a student from the scholl that will be the new participant: "; cin >> temp1;
		newTeam.participants[temp] = sch.students[temp1].id;
	default:
		log.error("Incorrect input in teacher edit function");
		break;
	}
	return newTeam;
}
void saveEditedTeam(SCHOOL& sch, size_t n, LOG& log)
{
	sch.teams[n] = editTeam(sch, sch.teams[n], log);
	log.info("Successfully edited student");
}
void deleteStudent(SCHOOL& sch, int n)
{
	sch.students.erase(sch.students.begin() + n);
}
void deleteTeacher(SCHOOL& sch, int n)
{
	sch.teachers.erase(sch.teachers.begin() + n);
}
void deleteTeam(SCHOOL& sch, int n)
{
	sch.teams.erase(sch.teams.begin() + n);
}