#ifndef PROCESSING_H
#define PROCESSING_H

#include "banking-operation.h"

Banking_operation** selection_sort_by_discription(Banking_operation* array[], int size);

Banking_operation** quick_sort_by_discription(Banking_operation* array[], int size);

Banking_operation** selection_sort_by_account_and_operation(Banking_operation* array[], int size);

Banking_operation** quick_sort_by_account_and_operation(Banking_operation* array[], int size);

#endif