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

	std::cout << "[���°���]" << std::endl;
	std::cout << "����ID : ";
	std::cin >> MID;
	for (j = 0; j < i; j++)
	{
		if (MID == client[j]->getID())
		{
			std::cout << "�̹� �����ϴ� ID�Դϴ�." << std::endl;
			x++;
		}
	}
	if (x != 1)
	{
		std::cout << "�̸� : ";
		std::cin >> Mname;
		std::cout << "�Աݾ� : ";
		std::cin >> Mcash;
		std::cout << "�����Ϸ� �Ǿ����ϴ�." << std::endl;
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
	std::cout << "[�Ա�]" << std::endl;
	std::cout << "����ID : ";
	std::cin >> DID;
	for (j = 0; j < i; j++)
	{
		if (DID == client[j]->getID())
		{
			while (1)
			{
				std::cout << "�Աݾ� : ";
				std::cin >> Dcash;
				if (Dcash < 0)
				{
					std::cout << "�߸��� ���Դϴ�.";
				}
				else
				{
					client[j]->pushcash(Dcash);
					std::cout << "�ԱݿϷ� �Ǿ����ϴ�." << std::endl;
					break;
				}
			}
		}
		else x++;
	}
	if (x == 100)
		std::cout << "�������� �ʴ� �����Դϴ�." << std::endl;
}

void withdraw(account** client, int i)
{
	int j;
	int x = 0;
	int WID;
	int Wcash;
	std::cout << "[���]" << std::endl;
	std::cout << "����ID : ";
	std::cin >> WID;

	for (j = 0; j < i; j++)
	{
		if (client[j]->getID() == WID)
		{
			std::cout << "��ݾ� : ";
			std::cin >> Wcash;
			if (client[j]->getcash() - Wcash < 0)
				std::cout << "�ܾ׺����Դϴ�." << std::endl;
			else
			{
				client[j]->pullcash(Wcash);
				std::cout << "��ݿϷ� �Ǿ����ϴ�." << std::endl;
			}
		}
		else x++;
	}
	if (x == 100)
		std::cout << "�������� �ʴ� �����Դϴ�." << std::endl;
}

void printaccount(account** client, int i)
{
	int j;
	std::cout << "[��ü ���]" << std::endl;
	std::cout << "������ ��ü ���� �� : " << i << std::endl;

	for (j = 0; j < i; j++)
	{
		std::cout << "���� ID : " << client[j]->getID() << std::endl;
		std::cout << "�̸�	  : " << client[j]->getname() << std::endl;
		std::cout << "�Աݾ�  : " << client[j]->getcash() << std::endl;
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
	std::cout << "1.���� ����" << std::endl;
	std::cout << "2.�Ա�" << std::endl;
	std::cout << "3.���" << std::endl;
	std::cout << "4.�������� ��ü ���" << std::endl;
	std::cout << "5.���α׷� ����\n" << std::endl;
	std::cout << "���� : ";
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
				std::cout << "���� �ִ�ġ�Դϴ�." << std::endl;
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
			std::cout << "�ùٸ� ���� �Է��ϼ���." << std::endl;
	}

	return 0;
}