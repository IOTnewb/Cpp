#include <iostream>
#include <cstring>

class account
{
private:
	char *name;
	int ID;
	int cash;

public:
	account()
	{
		ID = 0;
		cash = 0;
		name = 0;
	}

	account(char *name, int ID, int cash)
	{
		this->name = name;
		this->ID= ID;
		this->cash = cash;
	}

	~account()
	{
	}

	int getID()
	{
		return ID;
	}

	int getcash()
	{
		return cash;
	}

	void pushcash(int cash_)
	{
		cash += cash_;
	}

	void pullcash(int cash_)
	{
		cash -= cash_;
	}

	char* getname()
	{
		return name;
	}
};


int makeaccount(account **client, int i)
{
	char Mname[10];
	char *nameptr;
	int Mcash;
	int MID;
	int j;
	int x = 0;
	int len = 0;

	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌ID : ";
	std::cin >> MID;
	for (j = 0; j < i; j++)
	{
		if (MID == client[j]->getID())
		{
			std::cout << "이미 존재하는 ID입니다." << std::endl;
			x++;
		}
	}
	if (x != 1)
	{
		std::cout << "이름 : ";
		std::cin >> Mname;
		std::cout << "입금액 : ";
		std::cin >> Mcash;
		std::cout << "개설완료 되었습니다." << std::endl;
		len = strlen(Mname);
		nameptr = new char[len];
		strcpy(nameptr, Mname);
		client[i] = new account(nameptr, MID, Mcash);
		return 0;
	}
	else
		return -1;
}

void deposit(account** client, int i)
{
	int j;
	int x = 0;
	int DID;
	int Dcash;
	std::cout << "[입금]" << std::endl;
	std::cout << "계좌ID : ";
	std::cin >> DID;
	for (j = 0; j < i; j++)
	{
		if (DID == client[j]->getID())
		{
			while (1)
			{
				std::cout << "입금액 : ";
				std::cin >> Dcash;
				if (Dcash < 0)
				{
					std::cout << "잘못된 값입니다.";
				}
				else
				{
					client[j]->pushcash(Dcash);
					std::cout << "입금완료 되었습니다." << std::endl;
					break;
				}
			}
		}
		else x++;
	}
	if (x == 100)
		std::cout << "존재하지 않는 계좌입니다." << std::endl;
}

void withdraw(account** client, int i)
{
	int j;
	int x = 0;
	int WID;
	int Wcash;
	std::cout << "[출금]" << std::endl;
	std::cout << "계좌ID : ";
	std::cin >> WID;

	for (j = 0; j < i; j++)
	{
		if (client[j]->getID() == WID)
		{
			std::cout << "출금액 : ";
			std::cin >> Wcash;
			if (client[j]->getcash() - Wcash < 0)
				std::cout << "잔액부족입니다." << std::endl;
			else
			{
				client[j]->pullcash(Wcash);
				std::cout << "출금완료 되었습니다." << std::endl;
			}
		}
		else x++;
	}
	if (x == 100)
		std::cout << "존재하지 않는 계좌입니다." << std::endl;
}

void printaccount(account** client, int i)
{
	int j;
	std::cout << "[전체 출력]" << std::endl;
	std::cout << "개설된 전체 계좌 수 : " << i << std::endl;

	for (j = 0; j < i; j++)
	{
		std::cout << "계좌 ID : " << client[j]->getID() << std::endl;
		std::cout << "이름	  : " << client[j]->getname() << std::endl;
		std::cout << "입금액  : " << client[j]->getcash() << std::endl;
	}
}

void exitbank(account** client, int i)
{
	int k;
	for (k = 0; k < i; k++)
	{
		delete(client[k]);
	}
}

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
	account *client[100];
	int select;
	int i = 0;
	int value;

	while (1)
	{
		printmenu();
		std::cin >> select;

		if (select == 1)
		{
			if (i == 100)
				std::cout << "개설 최대치입니다." << std::endl;
			else
			{
				value = makeaccount(client, i);
				if (value == 0)
					i++;
				else;
			}
		}
		else if (select == 2)
			deposit(client, i);
		else if (select == 3)
			withdraw(client, i);
		else if (select == 4)
			printaccount(client, i);
		else if (select == 5)
		{
			exitbank(client,i);
			break;
		}
		else
			std::cout << "올바른 값을 입력하세요." << std::endl;
	}

	return 0;
}