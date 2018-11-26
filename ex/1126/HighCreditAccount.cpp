#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(const char *name, int cash, int ID, double ratio, double addratio)
	: NormalAccount(name, cash, ID, ratio), addRatio(addratio)
{}

HighCreditAccount::HighCreditAccount(HighCreditAccount &copy, double addratio)
	: NormalAccount(copy), addRatio(addratio)
{}
void HighCreditAccount::PrintAccount() const
{
	cout << "HighCreditAccount" << endl;
	PrintAccountInfo();
	cout << "Total Ratio : " << GetRatio() + addRatio << "%" << endl;
}

void HighCreditAccount::AddCash(int add_cash)
{
	upcash((int)(add_cash + (add_cash*((addRatio + GetRatio()) / 100))));
}

void HighCreditAccount::SubCash(int sub_cash)
{
	downcash(sub_cash);
}