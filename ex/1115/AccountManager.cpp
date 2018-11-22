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

	cout << "[���°���] -> ";
	cin >> Index;
	if (Index == NORMAL)
	{
		cout << "[�Ϲݰ���]" << endl;
		cout << "����ID : ";
		cin >> MID;
		for (int i = 0; i < list->Getcount(); i++)
		{
			if ((list->Getclient())[i]->GetID() == MID)
			{
				cout << "�̹� �����ϴ� ID�Դϴ�." << endl;
				except++;
			}
		}
		if (except != 1)
		{
			cout << "�̸� : ";
			cin >> Mname;
			cout << "�ݾ� : ";
			cin >> Mcash;
			len = strlen(Mname);
			nameptr = new char[len];
			strcpy(nameptr, Mname);
			(list->Getclient())[list->Getcount()] = new NormalAccount(nameptr, Mcash, MID, 0.75);
			list->Addcount();
			cout << "�����Ǿ����ϴ�. " << endl;
		}
	}
	else if (Index == CREDIT)
	{
		cout << "[�ſ����]" << endl;
		cout << "����ID : ";
		cin >> MID;
		for (int i = 0; i < list->Getcount(); i++)
		{
			if ((list->Getclient())[i]->GetID() == MID)
			{
				cout << "�̹� �����ϴ� ID�Դϴ�." << endl;
				except++;
			}
		}
		if (except != 1)
		{
			cout << "�̸� : ";
			cin >> Mname;
			cout << "�ݾ� : ";
			cin >> Mcash;
			cout << "���� : ";
			cin >> Mratio;
			cout << "�ſ� ��� : (1,2,3) ";
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
			cout << "�����Ǿ����ϴ�. " << endl;
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

	cout << "[�Ա�]" << endl;
	cout << "����ID : ";
	cin >> DID;
	for (int i = 0; i < list->Getcount(); i++)
	{
		if ((list->Getclient())[i]->GetID() == DID)
		{
			while (1)
			{
				cout << "�Աݾ� : ";
				cin >> Dcash;
					if (Dcash < 0)
					{
						DepositException expn(Dcash);
						throw expn;
					}
					else
					{
						(list->Getclient())[i]->AddCash(Dcash);
						cout << "�ԱݿϷ� �Ǿ����ϴ�." << endl;
						break;
					}
				}
		}
		else
			x++;
	}
	if (x == list->Getcount())
		cout << "�������� �ʴ� ID�Դϴ�. " << endl << endl;
}

void AccountManager::withDraw()
	throw (WithdrawException)
{
	int WID;
	int Wcash;
	int x = 0;
	cout << "[���]" << endl;
	cout << "����ID : ";
	cin >> WID;
	for (int i = 0; i < list->Getcount(); i++)
	{
		if ((list->Getclient())[i]->GetID() == WID)
		{
			while (1)
			{
				cout << "��ݾ� : ";
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
						cout << "��ݿϷ� �Ǿ����ϴ�." << endl;
						break;
					}
			}
		}
		else
			x++;
	}
	if (x == list->Getcount())
		cout << "�������� �ʴ� ID�Դϴ�. " << endl << endl;
}

void AccountManager::PrintAllAccount()
{
	cout << "[��ü ���]" << endl;
	cout << "������ ��ü ���� �� : " << list->Getcount() << endl;

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