#pragma once
#include "main.h"
#include "Account.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"

class AccountManager
{
private:
	Account *client;
	int count;
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

	AccountManager address()
	{
	}

	void Register_Client();

	void deposit();

	void withDraw();

	void PrintAllAccount();

	void exit();
};

class BoundCheckAccountArray
{
private:
	AccountManager *list;
	int count;
public:
	BoundCheckAccountArray(int num)
		: count(num)
	{
		list = new AccountManager[num];
	}

	void CopyAccount(AccountManager &client)
	{
		list[count] = client;
	}

	~BoundCheckAccountArray()
	{
		delete[]list;
	}
};

