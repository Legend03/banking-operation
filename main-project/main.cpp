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

bool bank_account_exist(Banking_operation* operation[], int size, string bankAccount)
{

	for (int i = 0; i < size; i++) {
		if (operation[i]->discription == bankAccount) {
			return true;
		}
	}
}


int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Лабораторная работа #1. GIT\n";
    cout << "Вариант #7. Банковские операции\n";
    cout << "Автор: Влад Пундалов\n";
    cout << "Группа: 24ПИнж\n\n";

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
		string bankAccount = operation[0]->discription;		

		int item = 1;

		while (item != 0)
		{
			cout << "\nВыберите вид, в котором Вы хотите увидеть данные:\n";
			cout << "1) Вывести все банковские приходные операции.\n";
			cout << "2) Вывести все банковские операции за ноябрь 2021 года.\n";
			cout << "3) По возрастанию назначения платежа\n";
			cout << "4) По возрастанию номера счёта\n";
			cout << "5) Итоговый баланс после всех операций по определенному счету\n";
			cout << "->";

			cin >> item;
			check_function = NULL;

			switch (item)
			{
			case 1:
				check_function = check_banking_operation_by_kind_operation; //       
				cout << "***** Все банковские приходные операции *****\n\n";
				break;
			case 2:
				check_function = check_banking_operation_by_date; //       
				cout << "***** Все банковские операции за ноябрь 2021 года *****\n\n";
				break;
			case 3:
				cout << "\nВыберите сортировку:\n";
				cout << "1)Selection sort\n";
				cout << "2)Quick sort\n";
				cout << "->";

				cin >> item;
				cout << '\n';

				switch(item)
				{
				case 1:
					cout << "***** По возрастанию назначения платежа Selection sort *****\n\n";
					filtered = selection_sort_by_discription(operation, size);
					for (int i = 0; i < size; i++)
					{
						output(filtered[i]);
					}
					delete[] filtered;
					cout << "--------------------------------------------------------------------------------------------------" << endl;
					break;
				case 2:
					cout << "***** По возрастанию назначения платежа Quick sort *****\n\n";
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
			case 4:
				cout << "\nВыберите сортировку:\n";
				cout << "1)Selection sort\n";
				cout << "2)Quick sort\n";
				cout << "->";

				cin >> item;
				cout << '\n';

				switch (item)
				{
				case 1:
					cout << "***** По возрастанию номера счёта Selection sort *****\n\n";
					filtered = selection_sort_by_account_and_operation(operation, size);
					for (int i = 0; i < size; i++)
					{
						output(filtered[i]);
					}
					delete[] filtered;
					cout << "--------------------------------------------------------------------------------------------------" << endl;
					break;
				case 2:
					cout << "***** По возрастанию номера счёта Quick sort *****\n\n";
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
			case 5:
				cout << "\nВведите номер счета\n";
				cout << "->";
				cin >> bankAccount;
				cout << '\n';

				if (bank_account_exist(operation, size, bankAccount)) 
				{
					cout << "***** Итоговый баланс после всех операций по определенному счету *****\n\n";
					cout << "Сумма по счёту " << bankAccount << " составляет: " << calculate_final_balance(operation, size, bankAccount) << "р\n";
				}

				break;
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