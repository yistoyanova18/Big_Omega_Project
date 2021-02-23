#pragma once
#include <string>
#include <fstream>
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
enum STATE {
	FREE,
	IN_TEAM,
	UNAVAILABLE,
	LOOKING
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
	STATE status;
	ROLE teamRole;
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
	vector<STUDENT> participants;
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

string Add0BeforeIntSmallerThan10(int num);
