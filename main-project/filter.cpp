#include "filter.h"
#include <cstring>
#include <iostream>

Banking_operation** filter(Banking_operation* array[], int size, bool (*check)(Banking_operation* element), int& result_size)
{
	Banking_operation** result = new Banking_operation * [size];
	result_size = 0;

	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_banking_operation_by_kind_operation(Banking_operation* element)
{
	return element->kindOperation == "������";
}

bool check_banking_operation_by_date(Banking_operation* element)
{
	return element->date.month == "11" && element->date.year == "2021";
}

int partition_by_discription(Banking_operation** array, int low, int high)
{
    int pivot_length = array[high]->discription.length();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j]->discription.length() <= pivot_length)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void start_quick_sort_by_discription(Banking_operation** array, int low, int high)
{
    if (low < high) {
        int pi = partition_by_discription(array, low, high);

        start_quick_sort_by_discription(array, low, pi - 1);
        start_quick_sort_by_discription(array, pi + 1, high);
    }
}

Banking_operation** get_copy(Banking_operation* array[], int size)
{
    Banking_operation** result = new Banking_operation * [size];

    for (int i = 0; i < size; i++) {
        result[i] = array[i];
    }

    return result;
}


Banking_operation** selection_sort_by_discription(Banking_operation* array[], int size)
{
    Banking_operation** result = get_copy(array, size);

    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < size; j++) {
            if (strcmp(result[j]->discription.c_str(), result[min_idx]->discription.c_str()) == -1) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            swap(result[min_idx], result[i]);
        }
    }

    return result;
}

Banking_operation** quick_sort_by_discription(Banking_operation* array[], int size)
{
    Banking_operation** result = get_copy(array, size);
    start_quick_sort_by_discription(result, 0, size - 1);
    return result;
}

bool compare_operations(Banking_operation* a, Banking_operation* b) {
    if (a->bankAccount != b->bankAccount) {
        return a->bankAccount < b->bankAccount;
    }
    if (a->kindOperation != b->kindOperation) {
        return a->kindOperation < b->kindOperation;
    }
    return a->amount > b->amount;  // �������� �� �����
}

Banking_operation** selection_sort_by_account_and_operation(Banking_operation* array[], int size) {
    Banking_operation** result = get_copy(array, size);

    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (compare_operations(result[j], result[min_idx])) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(result[min_idx], result[i]);
        }
    }
    return result;
}

int partition_by_account_and_operation(Banking_operation** array, int low, int high) {
    Banking_operation* pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare_operations(array[j], pivot)) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void start_quick_sort_by_account_and_operation(Banking_operation** array, int low, int high) {
    if (low < high) {
        int pi = partition_by_account_and_operation(array, low, high);
        start_quick_sort_by_account_and_operation(array, low, pi - 1);
        start_quick_sort_by_account_and_operation(array, pi + 1, high);
    }
}

Banking_operation** quick_sort_by_account_and_operation(Banking_operation* array[], int size) {
    Banking_operation** result = get_copy(array, size);
    start_quick_sort_by_account_and_operation(result, 0, size - 1);
    return result;
}