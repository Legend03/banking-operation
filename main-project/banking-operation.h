#ifndef BANKING_OPERATION_H
#define BANKING_OPERATION_H

#include "constants.h"
#include <string>

using namespace std;

struct Date
{
    string day;
    string month;
    string year;
};

struct Time
{
    string hours;
    string minutes;
};

struct Banking_operation
{
    Date date;
    Time time;
    string kindOperation;
    string bankAccount;
    double amount = 0;
    string discription;
};

#endif