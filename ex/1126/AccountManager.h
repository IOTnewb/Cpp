#pragma once
#include "main.h"
#include "Account.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"
#include "Exception.h"

class BoundCheckAccountArray
{
private:
	Account * client[100];
	int count;
public:
	BoundCheckAccountArray()
		: count(0)
	{}

	Account **Getclient()
	{
		return client;
	}

	void Addcount()
	{
		count++;
	}

	int Getcount()
	{
		return count;
	}

	~BoundCheckAccountArray()
	{
		for (int i = 0; i < count; i++)
		{
			delete client[i];
		}

	}
};

class AccountManager
{
private:
	BoundCheckAccountArray * list;

	enum
	{
		LEVEL_A = 1,
		LEVEL_B = 2,
		LEVEL_C = 3,
		LEVEL_A_RATIO = 7,
		LEVEL_B_RATIO = 4,
		LEVEL_C_RATIO = 2,
		NORMAL = 1,
		CREDIT = 2
	};
public:
	AccountManager();
	AccountManager(AccountManager &copy);

	void Register_Client();

	void deposit()	throw (DepositException);

	void withDraw()	throw (WithdrawException);

	void PrintAllAccount();

	void exit();
};

