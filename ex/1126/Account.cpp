#include "Account.h"

Account::Account(const char *name, int cash, int ID)
	: cash(cash), ID(ID)
{
	size_t len = strlen(name) + 1;
	this->name = new char[len];
	strcpy(this->name, name);
}

Account::Account(const Account &copy)
	: cash(cash), ID(ID)
{
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}


void Account::PrintAccountInfo() const
{
	cout << "ÀÌ¸§ : " << name << endl;
	cout << "°èÁÂID : " << ID << endl;
	cout << "ÀÜ¾× : " << cash << endl;
}

int Account::GetID()
{
	return ID;
}
int Account::Getcash()
{
	return cash;
}

void Account::upcash(int cashh)
{
	cash += cashh;
}

void Account::downcash(int cashh)
{
	cash -= cashh;
}

void Account::AddCash(int add_cash)
{
}

void Account::SubCash(int sub_cash)
{
}

void Account::PrintAccount() const
{

}