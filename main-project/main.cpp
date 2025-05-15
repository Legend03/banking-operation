#include <iostream>
#include <iomanip>

using namespace std;

#include "banking-operation.h"
#include "file-reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа #1. GIT\n";
    cout << "Вариант #7. Банковские операции\n";
    cout << "Автор: Влад Пундалов\n\n";

    Banking_operation* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;

    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << "--------------------------------------------------------------------------------------------------" << endl;
            cout << "| " << subscriptions[i]->date.day << '.';
            cout << subscriptions[i]->date.month << '.';
            cout << subscriptions[i]->date.year << " | ";
            cout << subscriptions[i]->time.hours << ':';
            cout << subscriptions[i]->time.minutes << " | ";
            cout << subscriptions[i]->kindOperation << " | ";
            cout << subscriptions[i]->bankAccount << " | ";
            cout << setw(8) << subscriptions[i]->amount << " | ";
            cout << setw(30) << subscriptions[i]->discription << " | ";
            cout << '\n';
        }
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}