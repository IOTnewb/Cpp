#pragma once
#include "main.h"

class Account
{
private:
	char *name;
	int cash;
	int ID;
public:
	Account(const char *name, int cash, int ID);

	Account(const Account &copy);


	void PrintAccountInfo() const;

	int GetID();

	void upcash(int cashh);

	void downcash(int cashh);

	virtual void AddCash(int add_cash);

	virtual void SubCash(int sub_cash);

	virtual void PrintAccount() const;

};