#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/banking-operation.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	Banking_operation* build_operation(string kindOperation, string bankAccount, double amount)
	{
		Banking_operation* operation = new Banking_operation;

		operation->kindOperation = kindOperation;
		operation->bankAccount = bankAccount;
		operation->amount = amount;

		return operation;
	}

	//       
	void delete_operation(Banking_operation* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}

	TEST_CLASS(unittestproject)
	{
	public:
		
		TEST_METHOD(TestOperation)
		{
			Banking_operation* operations[3];

			operations[0] = build_operation("приход", "12000001", 1000.00);
			operations[1] = build_operation("расход", "12000001", 1000.00);
			operations[2] = build_operation("приход", "12000001", 2000.00);

			Assert::AreEqual(2000.00, calculate_final_balance(operations, 3, "12000001"));
			delete_operation(operations, 3);
		}
        TEST_METHOD(TestEmptyOperationsArray)
        {
            Banking_operation* operations[1] = { nullptr };

            Assert::AreEqual(0.00, calculate_final_balance(operations, 0, "12000001"));
        }

        TEST_METHOD(TestAccountWithOnlyOutgoingTransactions)
        {
            Banking_operation* operations[3];

            operations[0] = build_operation("расход", "12000002", 500.00);
            operations[1] = build_operation("расход", "12000002", 300.00);
            operations[2] = build_operation("расход", "12000002", 200.00);

            Assert::AreEqual(-1000.00, calculate_final_balance(operations, 3, "12000002"));
            delete_operation(operations, 3);
        }

        TEST_METHOD(TestMixedAccountsTransactions)
        {
            Banking_operation* operations[5];

            operations[0] = build_operation("приход", "12000003", 1500.00);
            operations[1] = build_operation("расход", "12000004", 800.00);
            operations[2] = build_operation("приход", "12000003", 500.00);
            operations[3] = build_operation("расход", "12000003", 300.00);
            operations[4] = build_operation("приход", "12000004", 200.00);

            Assert::AreEqual(1700.00, calculate_final_balance(operations, 5, "12000003"));
            delete_operation(operations, 5);
        }

        TEST_METHOD(TestNonexistentAccount)
        {
            Banking_operation* operations[2];

            operations[0] = build_operation("приход", "12000005", 2500.00);
            operations[1] = build_operation("расход", "12000005", 500.00);

            Assert::AreEqual(0.00, calculate_final_balance(operations, 2, "99999999"));
            delete_operation(operations, 2);
        }
	};
}
