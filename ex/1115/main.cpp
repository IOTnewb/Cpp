#include <iostream>

using namespace std;

#define LEVEL_A				1
#define LEVEL_B				2
#define LEVEL_C				3
#define LEVEL_A_RATIO		7
#define LEVEL_B_RATIO		4
#define LEVEL_C_RATIO		2
#define NORMAL				1
#define CREDIT					2

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
	void PrintAccountInfo()
	{
		cout << "이름 : " << name << endl;
		cout << "계좌ID : " << ID << endl;
		cout << "잔액 : " << cash << endl;
	}

	int GetID()
	{
		return ID;
	}

};

class NormalAccount : public Account
{
private:
	double basicRatio;
public:
	NormalAccount(const char *name, int cash, int ID)
		: Account(name, cash, ID), basicRatio(0.75)
	{}

	void PrintAccount()
	{
		cout << "NormalAccount" << endl;
		PrintAccountInfo();
	}

};

class HighCreditAccount : public NormalAccount
{
private:
	double addRatio;
public:
	HighCreditAccount(const char *name, int cash, int ID, int addratio)
		: NormalAccount(name, cash, ID), addRatio(addratio)
	{}

	void PrintAccount()
	{
		cout << "HighCreditAccount" << endl;
		PrintAccountInfo();
	}

};

class AccountManager
{
private:
	Account *client[100];
	int count;
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
				client[count] = new NormalAccount(nameptr, Mcash, MID);
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
				cout << "신용 등급 : (1,2,3) ";
				cin >> CreditLevel;
				len = strlen(Mname);
				nameptr = new char[len];
				strcpy(nameptr, Mname);
				if(CreditLevel == LEVEL_A)
					client[count] = new HighCreditAccount(nameptr, Mcash, MID, LEVEL_A_RATIO);
				else if(CreditLevel == LEVEL_B)
					client[count] = new HighCreditAccount(nameptr, Mcash, MID, LEVEL_B_RATIO);
				else if (CreditLevel == LEVEL_C)
					client[count] = new HighCreditAccount(nameptr, Mcash, MID, LEVEL_C_RATIO);
				count++;
				cout << "개설되었습니다. " << endl;
			}
		}

		
	}

	void deposit()
	{
		int DID;
		int Dcash;

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
						std::cout << "잘못된 값입니다.";
					}
					else
					{
						client[i]->pushcash(Dcash);
						cout << "입금완료 되었습니다." << endl;
						break;
					}
				}
			}
		}
	}

	void withDraw()
	{

	}

	void PrintAllAccount()
	{

	}

	void exit()
	{

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
		/*	else if (sel == 2)
				manager.deposit();
			else if (sel == 3)
				manager.deposit();
			else if (sel == 4)
				manager.deposit();
			else if (sel == 5)
				{
					manager.exit();
					break;
				}*/
		else
			break;
	}
	return 0;
}