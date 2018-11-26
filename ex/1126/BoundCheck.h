#pragma once
#include "bankmain.h"
#include "Account.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"
#include "Exception.h"

class BoundCheckAccountArray
{
private:
	Account *client[100];
	int count;
public:
	BoundCheckAccountArray();
	Account **Getclient();
	void Addcount();
	int Getcount();
	~BoundCheckAccountArray();
};