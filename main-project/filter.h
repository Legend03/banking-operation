#ifndef FILTER_H
#define FILTER_H

#include "banking-operation.h"

Banking_operation** filter(Banking_operation* array[], int size, bool (*check)(Banking_operation* element), int& result_size);

bool check_banking_operation_by_kind_operation(Banking_operation* element);

bool check_banking_operation_by_date(Banking_operation* element);

Banking_operation** selection_sort_by_discription(Banking_operation* array[], int size);

Banking_operation** quick_sort_by_discription(Banking_operation* array[], int size);

Banking_operation** selection_sort_by_account_and_operation(Banking_operation* array[], int size);

Banking_operation** quick_sort_by_account_and_operation(Banking_operation* array[], int size);

#endif