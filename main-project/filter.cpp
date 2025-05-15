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
	return element->kindOperation == "приход";
}

bool check_banking_operation_by_date(Banking_operation* element)
{
	return element->date.month == "11" && element->date.year == "2021";
}