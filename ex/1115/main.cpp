#include <iostream>

using namespace std;



class Account
{
private:
	const char *name;
	int cash;
	int ID;
public:
	Account(const char *name, int cash, int ID)
		: name(name), cash(cash), ID(ID)
	{}

	void PrintAccountInfo() const
	{
		cout << "�̸� : " << name << endl;
		cout << "����ID : " << ID << endl;
		cout << "�ܾ� : " << cash << endl;
	}
	
	int GetID()
	{
		return ID;
	}

	void upcash(int cashh)
	{
		cash += cashh;
	}

	void downcash(int cashh)
	{
		cash -= cashh;
	}

	virtual void AddCash(int add_cash)
	{
	}

	virtual void SubCash(int sub_cash)
	{
	}

	virtual void PrintAccount() const
	{

	}

};

class NormalAccount : public Account
{
private:
	double basicRatio;
public:
	NormalAccount(const char *name, int cash, int ID, double ratio)
		: Account(name, cash, ID), basicRatio(ratio)
	{}

	void PrintAccount() const
	{
		cout << "NormalAccount" << endl;
		PrintAccountInfo();
		cout << "Ratio : " << basicRatio << "%" << endl;
	}

	double GetRatio() const
	{
		return basicRatio;
	}

	void AddCash(int add_cash)
	{
		upcash((int)(add_cash + (add_cash*basicRatio)));
	}

	void SubCash(int sub_cash)
	{
		downcash(sub_cash);
	}
};

class HighCreditAccount : public NormalAccount
{
private:
	double addRatio;
public:
	HighCreditAccount(const char *name, int cash, int ID, double ratio, double addratio)
		: NormalAccount(name, cash, ID, ratio), addRatio(addratio)
	{}

	void PrintAccount() const
	{
		cout << "HighCreditAccount" << endl;
		PrintAccountInfo();
		cout << "Total Ratio : " << GetRatio() + addRatio << "%" << endl;
	}

	void AddCash(int add_cash)
	{
		upcash((int)(add_cash + (add_cash*((addRatio+GetRatio())/100))));
	}

	void SubCash(int sub_cash)
	{
		downcash(sub_cash);
	}
};

class AccountManager
{
private:
	Account *client[100];
	int count;
	enum
	{
		LEVEL_A = 1,
		LEVEL_B = 2,
		LEVEL_C = 3,
		LEVEL_A_RATIO = 7,
		LEVEL_B_RATIO = 4,
		LEVEL_C_RATIO = 2,
		NORMAL = 1,
		CREDIT = 2
	};
public:
	AccountManager()
		: count(0)
	{}
	void Register_Client()
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
				if(CreditLevel == LEVEL_A)
					client[count] = new HighCreditAccount(nameptr, Mcash, MID, Mratio, LEVEL_A_RATIO);
				else if(CreditLevel == LEVEL_B)
					client[count] = new HighCreditAccount(nameptr, Mcash, MID, Mratio, LEVEL_B_RATIO);
				else if (CreditLevel == LEVEL_C)
					client[count] = new HighCreditAccount(nameptr, Mcash, MID, Mratio, LEVEL_C_RATIO);
				count++;
				cout << "�����Ǿ����ϴ�. " << endl;
			}
		}
		else;

		
	}

	void deposit()
	{
		int DID;
		int Dcash;
		int x = 0;

		cout << "[�Ա�]" << endl;
		cout << "����ID : ";
		cin >> DID;
		for (int i=0; i < count; i++)
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
		if(x == count)
			cout << "�������� �ʴ� ID�Դϴ�. " << endl << endl;
	}

	void withDraw()
	{
		int WID;
		int Wcash;
		int x=0;
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

	void PrintAllAccount()
	{
		cout << "[��ü ���]" << endl;
		cout << "������ ��ü ���� �� : " << count << endl;

		for (int i = 0; i < count; i++)
		{
			client[i]->PrintAccount();
		}
	}

	void exit()
	{
		for (int i = 0; i < count; i++)
		{
			delete client[i];
		}
	}
};

void printmenu()
{
	std::cout << "----------- MENU --------------" << std::endl;
	std::cout << "1.���� ����" << std::endl;
	std::cout << "2.�Ա�" << std::endl;
	std::cout << "3.���" << std::endl;
	std::cout << "4.�������� ��ü ���" << std::endl;
	std::cout << "5.���α׷� ����\n" << std::endl;
	std::cout << "���� : ";
}


int main(void)
{
	AccountManager manager;
	int sel;

	while (1)
	{
		printmenu();
		cin >> sel;

		if (sel == 1)
			manager.Register_Client();
		else if (sel == 2)
				manager.deposit();
		else if (sel == 3)
				manager.withDraw();
		else if (sel == 4)
				manager.PrintAllAccount();
		else if (sel == 5)
				{
					manager.exit();
					break;
				}
		
	}
	return 0;
}