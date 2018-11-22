#include "AccountManager.h"

AccountManager::AccountManager()
{
	list = new BoundCheckAccountArray();
}

AccountManager::AccountManager(AccountManager &copy)
{}

void AccountManager::Register_Client()
{
	char Mname[10];
	char *nameptr;
	size_t len;
	int Mcash;
	int MID;
	double Mratio;
	int Index;
	int CreditLevel;
	int except = 0;

	cout << "[계좌개설] -> ";
	cin >> Index;
	if (Index == NORMAL)
	{
		cout << "[일반계좌]" << endl;
		cout << "계좌ID : ";
		cin >> MID;
		for (int i = 0; i < list->Getcount(); i++)
		{
			if ((list->Getclient())[i]->GetID() == MID)
			{
				cout << "이미 존재하는 ID입니다." << endl;
				except++;
			}
		}
		if (except != 1)
		{
			cout << "이름 : ";
			cin >> Mname;
			cout << "금액 : ";
			cin >> Mcash;
			len = strlen(Mname);
			nameptr = new char[len];
			strcpy(nameptr, Mname);
			(list->Getclient())[list->Getcount()] = new NormalAccount(nameptr, Mcash, MID, 0.75);
			list->Addcount();
			cout << "개설되었습니다. " << endl;
		}
	}
	else if (Index == CREDIT)
	{
		cout << "[신용계좌]" << endl;
		cout << "계좌ID : ";
		cin >> MID;
		for (int i = 0; i < list->Getcount(); i++)
		{
			if ((list->Getclient())[i]->GetID() == MID)
			{
				cout << "이미 존재하는 ID입니다." << endl;
				except++;
			}
		}
		if (except != 1)
		{
			cout << "이름 : ";
			cin >> Mname;
			cout << "금액 : ";
			cin >> Mcash;
			cout << "이율 : ";
			cin >> Mratio;
			cout << "신용 등급 : (1,2,3) ";
			cin >> CreditLevel;
			len = strlen(Mname);
			nameptr = new char[len];
			strcpy(nameptr, Mname);
			if (CreditLevel == LEVEL_A)
				(list->Getclient())[list->Getcount()] = new HighCreditAccount(nameptr, Mcash, MID, Mratio, LEVEL_A_RATIO);
			else if (CreditLevel == LEVEL_B)
				(list->Getclient())[list->Getcount()] = new HighCreditAccount(nameptr, Mcash, MID, Mratio, LEVEL_B_RATIO);
			else if (CreditLevel == LEVEL_C)
				(list->Getclient())[list->Getcount()] = new HighCreditAccount(nameptr, Mcash, MID, Mratio, LEVEL_C_RATIO);
			list->Addcount();
			cout << "개설되었습니다. " << endl;
		}
	}
	else;


}

void AccountManager::deposit()
	throw (DepositException)
{
	int DID;
	int Dcash;
	int x = 0;

	cout << "[입금]" << endl;
	cout << "계좌ID : ";
	cin >> DID;
	for (int i = 0; i < list->Getcount(); i++)
	{
		if ((list->Getclient())[i]->GetID() == DID)
		{
			while (1)
			{
				cout << "입금액 : ";
				cin >> Dcash;
					if (Dcash < 0)
					{
						DepositException expn(Dcash);
						throw expn;
					}
					else
					{
						(list->Getclient())[i]->AddCash(Dcash);
						cout << "입금완료 되었습니다." << endl;
						break;
					}
				}
		}
		else
			x++;
	}
	if (x == list->Getcount())
		cout << "존재하지 않는 ID입니다. " << endl << endl;
}

void AccountManager::withDraw()
	throw (WithdrawException)
{
	int WID;
	int Wcash;
	int x = 0;
	cout << "[출금]" << endl;
	cout << "계좌ID : ";
	cin >> WID;
	for (int i = 0; i < list->Getcount(); i++)
	{
		if ((list->Getclient())[i]->GetID() == WID)
		{
			while (1)
			{
				cout << "출금액 : ";
				cin >> Wcash;
					if (Wcash < 0)
					{
						WithdrawException expn(Wcash);
						throw expn;
					}
					else if (list->Getclient()[i]->Getcash() - Wcash < 0)
					{
						WithdrawException expn(list->Getclient()[i]->Getcash());
						throw expn;
					}
					else
					{
						(list->Getclient())[i]->SubCash(Wcash);
						cout << "출금완료 되었습니다." << endl;
						break;
					}
			}
		}
		else
			x++;
	}
	if (x == list->Getcount())
		cout << "존재하지 않는 ID입니다. " << endl << endl;
}

void AccountManager::PrintAllAccount()
{
	cout << "[전체 출력]" << endl;
	cout << "개설된 전체 계좌 수 : " << list->Getcount() << endl;

	for (int i = 0; i < list->Getcount(); i++)
	{
		(list->Getclient())[i]->PrintAccount();
	}
}

void AccountManager::exit()
{
	for (int i = 0; i < list->Getcount(); i++)
	{
		delete (list->Getclient())[i];
	}
}