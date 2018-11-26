#include "Exception.h"

DepositException::DepositException(int money)	: Depmoney(money){}

WithdrawException::WithdrawException(int money)	: Withmoney(money){}

void DepositException::ShowExceptionReason()
{	
	cout << " �߸��� ���Դϴ�. " << endl;
}

void WithdrawException::ShowExceptionReason()
{
	if (Withmoney < 0)
		cout << " �߸��� ���Դϴ�. " << endl;
	else
	{
		cout << " �ܾ��� �����մϴ�." << endl;
		cout << " �ܾ� : " << Withmoney << endl;
	}

}