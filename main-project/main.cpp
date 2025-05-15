#include <iostream>
#include <iomanip>

using namespace std;

#include "banking-operation.h"
#include "file-reader.h"
#include "constants.h"
#include "filter.h"
#include "processing.h"

void output(Banking_operation* operation)
{
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << operation->date.day << '.';
    cout << operation->date.month << '.';
    cout << operation->date.year << " | ";
    cout << operation->time.hours << ':';
    cout << operation->time.minutes << " | ";
    cout << operation->kindOperation << " | ";
    cout << operation->bankAccount << " | ";
    cout << setw(8) << operation->amount << " | ";
    cout << setw(30) << operation->discription << " | ";
    cout << '\n';
}


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ #1. GIT\n";
    cout << "������� #7. ���������� ��������\n";
    cout << "�����: ���� ��������\n";
    cout << "������: 24����\n\n";

    Banking_operation* operation[MAX_FILE_ROWS_COUNT];
    int size;

    try
    {
		read("data.txt", operation, size);
		for (int i = 0; i < size; i++)
		{
			output(operation[i]);
		}
		cout << "--------------------------------------------------------------------------------------------------" << endl;

		bool (*check_function)(Banking_operation*) = NULL;
		Banking_operation** filtered = NULL;
		

		int item = 1;

		while (item != 0)
		{
			cout << "\n�������� ���, � ������� �� ������ ������� ������:\n";
			cout << "1)������� ��� ���������� ��������� ��������.\n";
			cout << "2)������� ��� ���������� �������� �� ������ 2021 ����.\n";
			cout << "3)�� ����������� ���������� �������\n";
			cout << "4)�� ����������� ������ �����\n";
			cout << "\n->";

			cin >> item;
			check_function = NULL;
			cout << '\n';

			switch (item)
			{
			case 1:
				check_function = check_banking_operation_by_kind_operation; //       
				cout << "***** ��� ���������� ��������� �������� *****\n\n";
				break;
			case 2:
				check_function = check_banking_operation_by_date; //       
				cout << "***** ��� ���������� �������� �� ������ 2021 ���� *****\n\n";
				break;
			case 3:
			{
				cout << "\n�������� ����������:\n";
				cout << "1)Selection sort\n";
				cout << "2)Quick sort\n";
				cout << "\n->";

				cin >> item;
				cout << '\n';

				switch(item)
				{
				case 1:
					cout << "***** �� ����������� ���������� ������� Selection sort *****\n\n";
					filtered = selection_sort_by_discription(operation, size);
					for (int i = 0; i < size; i++)
					{
						output(filtered[i]);
					}
					delete[] filtered;
					cout << "--------------------------------------------------------------------------------------------------" << endl;
					break;
				case 2:
					cout << "***** �� ����������� ���������� ������� Quick sort *****\n\n";
					filtered = quick_sort_by_discription(operation, size);
					for (int i = 0; i < size; i++)
					{
						output(filtered[i]);
					}
					delete[] filtered;
					cout << "--------------------------------------------------------------------------------------------------" << endl;
					break;
				}
				break;
			}
			case 4:
			{
				cout << "\n�������� ����������:\n";
				cout << "1)Selection sort\n";
				cout << "2)Quick sort\n";
				cout << "\n->";

				cin >> item;
				cout << '\n';

				switch (item)
				{
				case 1:
					cout << "***** �� ����������� ������ ����� Selection sort *****\n\n";
					filtered = selection_sort_by_account_and_operation(operation, size);
					for (int i = 0; i < size; i++)
					{
						output(filtered[i]);
					}
					delete[] filtered;
					cout << "--------------------------------------------------------------------------------------------------" << endl;
					break;
				case 2:
					cout << "***** �� ����������� ������ ����� Quick sort *****\n\n";
					filtered = quick_sort_by_account_and_operation(operation, size);
					for (int i = 0; i < size; i++)
					{
						output(filtered[i]);
					}
					delete[] filtered;
					cout << "--------------------------------------------------------------------------------------------------" << endl;
					break;
				}
				break;
			}
			default:
				throw "  ";
			}
			if (check_function)
			{
				int new_size;
				filtered = filter(operation, size, check_function, new_size);
				for (int i = 0; i < new_size; i++)
				{
					output(filtered[i]);
				}
				delete[] filtered;
				cout << "--------------------------------------------------------------------------------------------------" << endl;
			}
		}
    }
    catch (const char* error)
    {
		cout << error << '\n';
    }
    return 0;
}