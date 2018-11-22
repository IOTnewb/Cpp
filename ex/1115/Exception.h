#pragma once
#include "main.h"

class DepositException
{
private:
	int Depmoney;
public:
	DepositException(int money);
	void ShowExceptionReason();
};

class WithdrawException
{
private:
	int Withmoney;
public:
	WithdrawException(int money);
	void ShowExceptionReason();
};
