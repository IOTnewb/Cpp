#pragma once

#include "Account.h"


class NormalAccount : public Account
{
private:
	double basicRatio;
public:
	NormalAccount(const char *name, int cash, int ID, double ratio);

	NormalAccount(const NormalAccount &copy, double ratio);

	void PrintAccount() const;

	double GetRatio() const;

	void AddCash(int add_cash);

	void SubCash(int sub_cash);
};
