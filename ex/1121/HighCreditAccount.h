#pragma once
#include "Account.h"
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	double addRatio;
public:
	HighCreditAccount(const char *name, int cash, int ID, double ratio, double addratio);

	HighCreditAccount(HighCreditAccount &copy, double addratio);

	void PrintAccount() const;

	void AddCash(int add_cash);

	void SubCash(int sub_cash);
};
