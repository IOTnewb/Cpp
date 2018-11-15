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
		cout << "이름 : " << name << endl;
		cout << "계좌ID : " << ID << endl;
		cout << "잔액 : " << cash << endl;
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

		cout << "[계좌개설] -> ";
		cin >> Index;
		if (Index == NORMAL)
		{
			cout << "[일반계좌]" << endl;
			cout << "계좌ID : ";
			cin >> MID;
			for (int i = 0; i < count; i++)
			{
				if (client[i]->GetID() == MID)
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
				client[count] = new NormalAccount(nameptr, Mcash, MID, 0.75);
				count++;
				cout << "개설되었습니다. " << endl;
			}
		}
		else if (Index == CREDIT)
		{
			cout << "[신용계좌]" << endl;
			cout << "계좌ID : ";
			cin >> MID;
			for (int i = 0; i < count; i++)
			{
				if (client[i]->GetID() == MID)
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
				if(CreditLevel == LEVEL_A)
					client[count] = new HighCreditAccount(nameptr, Mcash, MID, Mratio, LEVEL_A_RATIO);
				else if(CreditLevel == LEVEL_B)
					client[count] = new HighCreditAccount(nameptr, Mcash, MID, Mratio, LEVEL_B_RATIO);
				else if (CreditLevel == LEVEL_C)
					client[count] = new HighCreditAccount(nameptr, Mcash, MID, Mratio, LEVEL_C_RATIO);
				count++;
				cout << "개설되었습니다. " << endl;
			}
		}
		else;

		
	}

	void deposit()
	{
		int DID;
		int Dcash;
		int x = 0;

		cout << "[입금]" << endl;
		cout << "계좌ID : ";
		cin >> DID;
		for (int i=0; i < count; i++)
		{
			if (DID == client[i]->GetID())
			{
				while (1)
				{
					cout << "입금액 : ";
					cin >> Dcash;
					if (Dcash < 0)
					{
						cout << "잘못된 값입니다.";
					}
					else
					{
						client[i]->AddCash(Dcash);
						cout << "입금완료 되었습니다." << endl;
						break;
					}
				}
			}
			else
				x++;
		}
		if(x == count)
			cout << "존재하지 않는 ID입니다. " << endl << endl;
	}

	void withDraw()
	{
		int WID;
		int Wcash;
		int x=0;
		cout << "[출금]" << endl;
		cout << "계좌ID" << endl;
		cin >> WID;
		for (int i = 0; i < count; i++)
		{
			if (WID == client[i]->GetID())
			{
				while (1)
				{
					cout << "출금액 : ";
					cin >> Wcash;
					if (Wcash < 0)
					{
						cout << "잘못된 값입니다.";
					}
					else
					{
						client[i]->SubCash(Wcash);
						cout << "출금완료 되었습니다." << endl;
						break;
					}
				}
			}
			else
				x++;
		}
		if (x == count)
			cout << "존재하지 않는 ID입니다. " << endl << endl;
	}

	void PrintAllAccount()
	{
		cout << "[전체 출력]" << endl;
		cout << "개설된 전체 계좌 수 : " << count << endl;

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
	std::cout << "1.계좌 개설" << std::endl;
	std::cout << "2.입금" << std::endl;
	std::cout << "3.출금" << std::endl;
	std::cout << "4.계좌정보 전체 출력" << std::endl;
	std::cout << "5.프로그램 종료\n" << std::endl;
	std::cout << "선택 : ";
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