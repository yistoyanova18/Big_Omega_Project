#pragma once
#include <string>
#include <vector>
#include "BackEnd.h"
using namespace std;

//Printing of students, teachers, teams

//Prints a student on standard output
void printStudent(SCHOOL& sch, size_t num=0);
//Prints a teacher on standard output
void printTeacher(SCHOOL& sch, size_t num = 0, size_t n = 1);
//Prints a team on standard output
void printTeam(SCHOOL& sch, size_t num = 0, size_t n = 1);

bool mainMenu(SCHOOL& sch);