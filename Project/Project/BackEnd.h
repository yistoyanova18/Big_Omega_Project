#pragma once
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

enum SEVERITY {
	CRITICAL = 0,
	ERROR = 1,
	WARNING = 2,
	INFO = 3,
	DEBUG = 4
};

struct LOGTIME {
	int s;
	int m;
	int h;
	int md;
	int mo;
	int y;
	static tm getTimeDate()
	{
		time_t t = time(NULL);
		tm* ltm = new tm;
		localtime_s(ltm, &t);
		return *ltm;
	}
};

enum STATUS {
	IN_USE,
	NOT_ACTIVE,
	ARCHIVED
};

struct TIME {
	short int s;
	short int m;
	short int h;
	short int d;
	short int mo;
	short int y;
};
enum ROLE {
	SCRUM_TRAINER,
	BACKEND_DEV,
	FRONTEND_DEV,
	QA_ENGI
};

struct NAMES {
	string firstName;
	string lastName;
};

struct STUDENT {
	int id;
	NAMES name;
	short int age;
	char grade;
	string status;
	string teamRole;
	string email;
};

struct TEACHER {
	int id;
	NAMES name;
	string email;
};

struct TEAM {
	int id;
	TEACHER teacher;
	vector<int> participants;
	string desc;//desc = description
	TIME dateOfCreation;
	STATUS status;
};

struct SCHOOL {
	string name = "PGKPI";
	string city = "Burgas";
	vector<TEAM> teams;
	vector<STUDENT> students;
	vector<TEACHER> teachers;
};

struct LOG {
	string date;
	string time;
	fstream logFile;
	SEVERITY logLevel;
	bool openFile(string filename);
	void closeFile();
	void createLog(string msg, SEVERITY sev);
	void debug(string msg, SEVERITY sev = DEBUG);
	void info(string msg, SEVERITY sev = INFO);
	void warning(string msg, SEVERITY sev = WARNING);
	void error(string msg, SEVERITY sev = ERROR);
	void critical(string msg, SEVERITY sev = CRITICAL);
};

//Creation of students, teachers, teams

//Makes a new student structure
STUDENT makeNewStudent();
//Inserts new student into school's student array
void insertNewStudent(SCHOOL& sch, size_t n = 1);
//Makes a new teacher structure
TEACHER makeNewTeacher();
//Inserts new teacher into school's teacher array
void insertNewTeacher(SCHOOL& sch, size_t n = 1);
//Makes a new team structure
TEAM makeNewTeam(SCHOOL& sch);
//Inserts new team into school's team array
void insertNewTeam(SCHOOL& sch, size_t n = 1);
//Edit an existing student
STUDENT editStudent(STUDENT student, LOG& log);
//Save edited student
void saveEditedStudent(SCHOOL& sch, size_t n,LOG& log);
//Edit an existing teacher
TEACHER editTeacher(TEACHER teacher, LOG& log);
//Save edited teacher
void saveEditedTeacher(SCHOOL& sch, size_t n, LOG& log);
//Edit an existing team
TEAM editTeam(SCHOOL& sch, TEAM team,LOG& log);
//Save edited team
void saveEditedTeam(SCHOOL& sch, size_t n, LOG& log);

void deleteStudent(SCHOOL& sch, int n);
void deleteTeacher(SCHOOL& sch, int n);
void deleteTeam(SCHOOL& sch, int n);
string Add0BeforeIntSmallerThan10(int num);
