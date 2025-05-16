#include "process.h"
#include "banking-operation.h"
#include <cstring>
#include <iostream>

double calculate_final_balance(Banking_operation* array[], int size, string bankAccount)
{
	double finalBalance = 0;

	for (int i = 0; i < size; i++) 
	{
		if (array[i]->bankAccount == bankAccount)
		{
			if (array[i]->kindOperation == "приход")
			{
				finalBalance += array[i]->amount;
			}
			else if (array[i]->kindOperation == "расход")
			{
				finalBalance -= array[i]->amount;
			}
		}
	}

	return finalBalance;
}