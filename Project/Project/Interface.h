#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "BackEnd.h"
using namespace std;

//Printing of students, teachers, teams

//Prints a student on standard output
void printStudent(SCHOOL& sch, size_t num=0);
//Prints a teacher on standard output
void printTeacher(SCHOOL& sch, size_t num = 0);
//Prints a team on standard output
void printTeam(SCHOOL& sch, size_t num = 0);

bool mainMenu(SCHOOL& sch, LOG &log);