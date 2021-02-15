#include <iostream>
#include <string>
#include <vector>
#include "Interface.h"
using namespace std;

void printStudent(SCHOOL& sch,size_t num, size_t n)
{
	if (n==1)
	{
		cout << sch.students[num].name.firstName;
		cout << " " << sch.students[num].name.lastName<<"    ";
		cout << sch.students[num].grade;
		cout << endl << sch.students[num].age<<endl;
		switch (sch.students[num].status)
		{
		case FREE:
			cout << sch.students[num].name.lastName << " has no team\n";
			break;
		case IN_TEAM:
			cout << sch.students[num].name.lastName << " has a team\n";
			break;
		case UNAVAILABLE:
			cout << sch.students[num].name.lastName << " is unavailable\n";
			break;
		case LOOKING:
			cout << sch.students[num].name.lastName << " is looking for a team\n";
			break;
		default:
			break;
		}
		cout << "Prefered Role: ";
		switch (sch.students[num].teamRole)
		{
		case SCRUM_TRAINER:
			cout << "Scrum Trainer\n";
			break;
		case BACKEND_DEV:
			cout << "Backend Developer\n";
			break;
		case FRONTEND_DEV:
			cout << "Frontend Developer\n";
			break;
		case QA_ENGI:
			cout << "QA Engineer\n";
			break;
		default:
			break;
		}
		cout << sch.students[num].email << endl;
	}
}