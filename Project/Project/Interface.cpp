#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include "Interface.h"
using namespace std;

void printStudent(SCHOOL& sch,size_t num)
{
	cout << endl;
	cout << sch.students[num].name.firstName;
	cout << " " << sch.students[num].name.lastName << "    ";
	cout << sch.students[num].grade<<" Class";
	cout << endl << sch.students[num].age << endl;
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

bool mainMenu(SCHOOL& sch)
{
	int temp;
	cout << "1. Print Student/s\n";
	cout << "2. Print Teacher/s\n";
	cout << "3. Print Team/s\n";
	cout << "4. Add Student/s\n";
	cout << "5. Add Teacher/s\n";
	cout << "6. Add Team/s\n";
	cout << "7. Add School\n";
	cout << "0. Exit\n";
	cin >> temp;
	switch (temp)
	{
	case 1:
		cout << "Multiple students? "; cin >> temp;
		if (temp)
		{
			int a;
			cout << "How many? "; cin >> temp;
			for (size_t i = 0; i < temp; i++)
			{
				cout << "ID: "; cin >> a;
				printStudent(sch, a);
				wcout << L"------------------\n";
			}
			cout << "END(Press a button to go back to main menu)";
		}
		else
		{
			cout << "ID: "; cin >> temp;
			printStudent(sch, temp);
		 }
		_getch();
		system("CLS");
		return true;
		break;
	case 2:
		return true;
		break;
	case 3:
		return true;
		break;
	case 4:
		cout << "Multiple students?";
		cin >> temp;
		if (temp)
		{
			cout << "How many?\n"; cin >> temp;
			for (size_t i = 0; i < temp; i++)
			{
				insertNewStudent(sch);
			}
		}
		else
		{
			insertNewStudent(sch);
		}
		system("CLS");
		return true;
		break;
	case 5:
		return true;
		break;
	case 6:
		return true;
		break;
	case 7:
		return true;
		break;
	case 0:
		return false;
		break;
	default:
		return false;
		break;
	}
}