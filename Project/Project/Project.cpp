#include <iostream>
#include <string>
#include <vector>
#include "BackEnd.h"
#include "Interface.h"
using namespace std;



int main()
{
    SCHOOL school;
    insertNewStudent(school);
    printStudent(school);
}