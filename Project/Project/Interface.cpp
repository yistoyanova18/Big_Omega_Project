#include <iostream>
#include <fstream>
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
	cout << "Status: " + sch.students[num].status + "\n";
	cout << "Prefered Role: "+ sch.students[num].teamRole+"\n";
	cout << sch.students[num].email << endl;
}

void printTeacher(SCHOOL& sch, size_t num)
{
	cout << "ID: "; cout<< sch.teachers[num].id;
	cout << endl << sch.teachers[num].name.firstName<<" "<<sch.teachers[num].name.lastName;
	cout << endl << sch.teachers[num].email;
}

void printTeam(SCHOOL& sch, size_t num)
{
	cout << "ID: "; cout << sch.teams[num].id;
	cout << endl <<"Creation Date:"<< sch.teams[num].dateOfCreation.d << "/" << sch.teams[num].dateOfCreation.mo << "/" << sch.teams[num].dateOfCreation.y<<"       ";
	switch (sch.teams[num].status)
	{
	case IN_USE:
		cout << "Team in use"; break;
	case NOT_ACTIVE:
		cout << "Team is inactive"; break;
	case ARCHIVED:
		cout << "Team is archived"; break;
	default:
		break;
	}
	cout << endl << sch.teams[num].desc;
	cout << endl << "Teacher: " << sch.teams[num].teacher.name.firstName + " " + sch.teams[num].teacher.name.lastName;
	cout << "\n-----------------";
	for (size_t i = 0; i < sch.teams[num].participants.size(); i++)
	{
		cout << endl << sch.students[sch.teams[num].participants[i]].name.firstName+" "+ sch.students[sch.teams[num].participants[i]].name.lastName+"\nRole: "+ sch.students[sch.teams[num].participants[i]].teamRole + "\n";
	}
}

bool mainMenu(SCHOOL& sch, LOG &log)
{
	size_t temp;
	cout << "---------------+\n";
	cout << "  1. Printing  |\n";
	cout << "  2. Adding    |\n";
	cout << "  3. Editing   |\n";
	cout << "  4. Deletion  |\n";
	cout << "  0. Exit      |\n---------------+\n:";
	cin >> temp;
	system("CLS");
	switch (temp)
	{
	case 1:
		cout << "1. Print Student/s\n";
		cout << "2. Print Teacher/s\n";
		cout << "3. Print Team/s\n";
		cout << "0. Exit\n\n:";
		cin >> temp;
		switch (temp)
		{
		case 1:
			cout << "0.One/1.Multiple/2.All students? "; cin >> temp;
			switch (temp)
			{
			case 0:
				cout << "ID: "; cin >> temp;
				printStudent(sch, temp);
				log.info("Successfully printed one student");
				break;
			case 1:
				int a;
				cout << "How many? "; cin >> temp;
				for (size_t i = 0; i < temp; i++)
				{
					cout << "ID: "; cin >> a;
					printStudent(sch, a);
					cout << "\n------------------";
				}
				log.info("Successfully printed students");
				break;
			case 2:
				for (size_t i = 0; i < sch.students.size(); i++)
				{
					printStudent(sch, i);
					cout << "\n------------------";
				}
				log.info("Successfully printed all students");
				break;
			default:
				log.error("Incorrect input in student print func");
				log.info("Going back to main menu");
				return true;
				break;
			}
			cout << "\nPress a button to go back to main menu";
			_getch();
			system("CLS");
			return true;
			break;
		case 2:
			cout << "0.One/1.Multiple/2.All teachers? "; cin >> temp;
			switch (temp)
			{
			case 0:
				cout << "ID: "; cin >> temp;
				printTeacher(sch, temp);
				log.info("Successfully printed one teacher");
				break;
			case 1:
				int a;
				cout << "How many? "; cin >> temp;
				for (size_t i = 0; i < temp; i++)
				{
					cout << "ID: "; cin >> a;
					printTeacher(sch, a);
					cout << "\n------------------";
				}
				log.info("Successfully printed teachers");
				break;
			case 2:
				for (size_t i = 0; i < sch.teachers.size(); i++)
				{
					printTeacher(sch, i);
					cout << "\n------------------";
				}
				log.info("Successfully printed all teachers");
				break;
			default:
				log.error("Incorrect input in teacher print");
				log.info("Going back to main menu");
				return true;
				break;
			}
			cout << "\nPress a button to go back to main menu";
			_getch();
			system("CLS");
			return true;
			break;
		case 3:
			cout << "0.One/1.Multiple/2.All teams? "; cin >> temp;
			switch (temp)
			{
			case 0:
				cout << "ID: "; cin >> temp;
				printTeam(sch, temp);
				log.info("Successfully printed one team");
				break;
			case 1:
				int a;
				cout << "How many? "; cin >> temp;
				for (size_t i = 0; i < temp; i++)
				{
					cout << "ID: "; cin >> a;
					printTeam(sch, a);
					cout << "\n------------------";
				}
				log.info("Successfully printed teams");
				break;
			case 2:
				for (size_t i = 0; i < sch.teams.size(); i++)
				{
					printTeam(sch, i);
					cout << "\n------------------";
				}
				log.info("Successfully printed all teams");
				break;
			default:
				break;
			}
			cout << "\nPress a button to go back to main menu";
			_getch();
			system("CLS");
			return true;
			break;
		case 0:
			log.info("Going back to main menu");
			return true;
			break;
		default:
			log.error("Incorrect input in printing menu");
			log.info("Going back to main menu");
			return true;
			break;
		}
		break;
	case 2:
		cout << "1. Add Student/s\n";
		cout << "2. Add Teacher/s\n";
		cout << "3. Add Team/s\n";
		cout << "0. Exit\n\n:";
		cin >> temp;
		switch (temp)
		{
		case 1:
			cout << "Multiple students? (0/1)";
			cin >> temp;
			if (temp)
			{
				cout << "How many?\n"; cin >> temp;
				for (size_t i = 0; i < temp; i++)
				{
					insertNewStudent(sch);
				}
				log.info("Successfully created students");
			}
			else
			{
				insertNewStudent(sch);
				log.info("Successfully created one teacher");
			}
			system("CLS");
			return true;
			break;
		case 2:
			cout << "Multiple teachers?(0/1)";
			cin >> temp;
			if (temp)
			{
				cout << "How many?\n"; cin >> temp;
				for (size_t i = 0; i < temp; i++)
				{
					insertNewTeacher(sch);
				}
				log.info("Successfully created teachers");
			}
			else
			{
				insertNewTeacher(sch);
				log.info("Successfully created one teacher");
			}
			system("CLS");
			return true;
			break;
		case 3:
			cout << "Multiple teams?(0/1)";
			cin >> temp;
			if (temp)
			{
				cout << "How many?\n"; cin >> temp;
				for (size_t i = 0; i < temp; i++)
				{
					insertNewTeam(sch);
				}
				log.info("Successfully created teams");
			}
			else
			{
				insertNewTeam(sch);
				log.info("Successfully created one team");
			}
			system("CLS");
			return true;
			break;
		case 0:
			log.info("Going back to main menu\n");
			return true;
			break;
		default:
			log.error("Incorrect input in adding menu");
			log.info("Going back to main menu");
			return true;
			break;
		}
		break;
	case 3:
		cout << "1. Edit Student\n";
		cout << "2. Edit Teacher\n";
		cout << "3. Edit Team\n";
		cout << "0. Exit\n\n:";
		cin >> temp;
		switch (temp)
		{
		case 1:
			cout << "ID of student for editing: "; cin >> temp;
			saveEditedStudent(sch, temp, log);
			system("CLS");
			return true;
			break;
		case 2:
			return true;
			break;
		case 3:
			return true;
			break;
		case 0:
			log.info("Going back to main menu\n");
			return true;
			break;
		default:
			log.error("Incorrect input in editing menu");
			log.info("Going back to main menu");
			return true;
			break;
		}
		break;
	case 0:
		log.info("Exiting program\n");
		return false;
		break;
	default:
		log.error("Incorrect input in main menu menu");
		log.info("Going back to main menu");
		return true;
		break;
	}
}