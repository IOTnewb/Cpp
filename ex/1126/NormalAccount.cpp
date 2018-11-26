#include "NormalAccount.h"

NormalAccount::NormalAccount(const char *name, int cash, int ID, double ratio)
	: Account(name, cash, ID), basicRatio(ratio)
{}

NormalAccount::NormalAccount(const NormalAccount &copy, double ratio)
	: Account(copy), basicRatio(ratio)
{}

void NormalAccount::PrintAccount() const
{
	cout << "----NormalAccount----" << endl;
	PrintAccountInfo();
	cout << "Ratio : " << basicRatio << "%" << endl;
}

double NormalAccount::GetRatio() const {	return basicRatio;}

void NormalAccount::AddCash(int add_cash)
{
	upcash((int)(add_cash + ((add_cash*basicRatio) / 100)));
}

void NormalAccount::SubCash(int sub_cash)
{
	downcash(sub_cash);
}