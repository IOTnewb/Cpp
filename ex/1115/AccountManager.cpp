#include "AccountManager.h"

AccountManager::AccountManager()
	: count(0)
{}

AccountManager::AccountManager(AccountManager &copy)
	: count(0)
{}

void AccountManager::Register_Client()
{
	char Mname[10];
	char *nameptr;
	int len;
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
		for (int i = 0; i < count; i++)
		{
			if (client[i]->GetID() == MID)
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
			client[count] = new NormalAccount(nameptr, Mcash, MID, 0.75);
			count++;
			cout << "�����Ǿ����ϴ�. " << endl;
		}
	}
	else if (Index == CREDIT)
	{
		cout << "[�ſ����]" << endl;
		cout << "����ID : ";
		cin >> MID;
		for (int i = 0; i < count; i++)
		{
			if (client[i]->GetID() == MID)
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
				client[count] = new HighCreditAccount(nameptr, Mcash, MID, Mratio, LEVEL_A_RATIO);
			else if (CreditLevel == LEVEL_B)
				client[count] = new HighCreditAccount(nameptr, Mcash, MID, Mratio, LEVEL_B_RATIO);
			else if (CreditLevel == LEVEL_C)
				client[count] = new HighCreditAccount(nameptr, Mcash, MID, Mratio, LEVEL_C_RATIO);
			count++;
			cout << "�����Ǿ����ϴ�. " << endl;
		}
	}
	else;


}

void AccountManager::deposit()
{
	int DID;
	int Dcash;
	int x = 0;

	cout << "[�Ա�]" << endl;
	cout << "����ID : ";
	cin >> DID;
	for (int i = 0; i < count; i++)
	{
		if (DID == client[i]->GetID())
		{
			while (1)
			{
				cout << "�Աݾ� : ";
				cin >> Dcash;
				if (Dcash < 0)
				{
					cout << "�߸��� ���Դϴ�.";
				}
				else
				{
					client[i]->AddCash(Dcash);
					cout << "�ԱݿϷ� �Ǿ����ϴ�." << endl;
					break;
				}
			}
		}
		else
			x++;
	}
	if (x == count)
		cout << "�������� �ʴ� ID�Դϴ�. " << endl << endl;
}

void AccountManager::withDraw()
{
	int WID;
	int Wcash;
	int x = 0;
	cout << "[���]" << endl;
	cout << "����ID" << endl;
	cin >> WID;
	for (int i = 0; i < count; i++)
	{
		if (WID == client[i]->GetID())
		{
			while (1)
			{
				cout << "��ݾ� : ";
				cin >> Wcash;
				if (Wcash < 0)
				{
					cout << "�߸��� ���Դϴ�.";
				}
				else
				{
					client[i]->SubCash(Wcash);
					cout << "��ݿϷ� �Ǿ����ϴ�." << endl;
					break;
				}
			}
		}
		else
			x++;
	}
	if (x == count)
		cout << "�������� �ʴ� ID�Դϴ�. " << endl << endl;
}

void AccountManager::PrintAllAccount()
{
	cout << "[��ü ���]" << endl;
	cout << "������ ��ü ���� �� : " << count << endl;

	for (int i = 0; i < count; i++)
	{
		client[i]->PrintAccount();
	}
}

void AccountManager::exit()
{
	for (int i = 0; i < count; i++)
	{
		delete client[i];
	}
}