#include "Exception.h"

DepositException::DepositException(int money)
	: Depmoney(money)
{}

WithdrawException::WithdrawException(int money)
	: Withmoney(money)
{}

void DepositException::ShowExceptionReason()
{
	cout << " 잘못된 값입니다. " << endl;
}

void WithdrawException::ShowExceptionReason()
{
	cout << " 잘못된 값입니다. " << endl;
}