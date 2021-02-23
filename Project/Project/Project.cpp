#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BackEnd.h"
#include "Interface.h"
using namespace std;

int main()
{
    LOG log;
    log.logLevel = SEVERITY::DEBUG;
    SCHOOL school;
    if (log.openFile("log.txt"))
    {
        do
        {

        } while (mainMenu(school,log));
    }
    log.closeFile();
}