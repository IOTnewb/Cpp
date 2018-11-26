#include "Exception.h"

DepositException::DepositException(int money)	: Depmoney(money){}

WithdrawException::WithdrawException(int money)	: Withmoney(money){}

void DepositException::ShowExceptionReason()
{	
	cout << " 잘못된 값입니다. " << endl;
}

void WithdrawException::ShowExceptionReason()
{
	if (Withmoney < 0)
		cout << " 잘못된 값입니다. " << endl;
	else
	{
		cout << " 잔액이 부족합니다." << endl;
		cout << " 잔액 : " << Withmoney << endl;
	}

}