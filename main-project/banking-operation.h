#ifndef BOOK_SUBSCRIPTION_H
#define BOOK_SUBSCRIPTION_H

#include "constants.h"
#include <string>

using namespace std;

struct date
{
    int day;
    int month;
    int year;
};

struct time
{
    int hours;
    int minutes;
};

struct banking_operation
{
    date date;
    time time;
    string kindOperation;
    string bandAccount;
    double amount;
    string discription;
    char title[MAX_STRING_SIZE];
};

#endif