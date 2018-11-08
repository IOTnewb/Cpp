#include <iostream>
#include <cstring>

class account
{
public:
	int ID;
	int cash;
	char name[10];
	
private:

};

int makeaccount(account* client, int i)
{
	account arg;
	int j;
	int x = 0;


	std::cout << "[���°���]" << std::endl;
	std::cout << "����ID : ";
	std::cin >> arg.ID;
	for (j = 0; j < 100; j++)
	{
		if (client[j].ID == arg.ID)
			{
				std::cout << "�̹� �����ϴ� ID�Դϴ�." << std::endl;
				x++;
			}
		
	}
	if(x != 1)
	{
		std::cout << "�̸� : ";
		std::cin >> arg.name;
		std::cout << "�Աݾ� : ";
		std::cin >> arg.cash;
		std::cout << "�����Ϸ� �Ǿ����ϴ�." << std::endl;

		client[i] = arg;
		return 0;
	}
	else
		return -1;
}

void deposit(account* client)
{
	int i;
	int x=0;
	int ID;
	int cash;
	std::cout << "[�Ա�]" << std::endl;
	std::cout << "����ID : ";
	std::cin >> ID;
	for (i = 0; i < 100; i++)
	{
		if(client[i].ID == ID)
		{
			while(1)
			{ 
			std::cout << "�Աݾ� : ";
			std::cin >> cash;
				if (cash < 0)
				{
					std::cout << "�߸��� ���Դϴ�.";
				}
				else
				{
					client[i].cash += cash;
					std::cout << "�ԱݿϷ� �Ǿ����ϴ�." << std::endl;
					break;
				}
			}
		}
		else x++;
	}
	if(x==100)
		std::cout << "�������� �ʴ� �����Դϴ�." << std::endl;
}

void withdraw(account* client)
{
	int i;
	int x=0;
	int ID;
	int cash;
	std::cout << "[���]" << std::endl;
	std::cout << "����ID : ";
	std::cin >> ID;
	
	for (i = 0; i < 100; i++)
	{
		if (client[i].ID == ID)
		{
			std::cout << "��ݾ� : ";
			std::cin >> cash;
			if (client[i].cash - cash < 0)
				std::cout << "�ܾ׺����Դϴ�." << std::endl;
			else
			{
				client[i].cash -= cash;
				std::cout << "��ݿϷ� �Ǿ����ϴ�." << std::endl;
			}
		}
		else x++;
	}
	if(x==100)
		std::cout << "�������� �ʴ� �����Դϴ�." << std::endl;
}

void printaccount(account* client, int i)
{
	int j;
	std::cout << "[��ü ���]" << std::endl;
	std::cout << "������ ��ü ���� �� : " << i << std::endl;

	for (j = 0; j < i; j++)
	{
		std::cout << "���� ID : " << client[j].ID << std::endl;
		std::cout << "�̸�	  : " << client[j].name << std::endl;
		std::cout << "�Աݾ�  : " << client[j].cash << std::endl;
	}
}

int main(void)
{
	int select;
	account client[100];
	int i=0;
	int value;

	while (1)
	{
		std::cout << "----------- MENU --------------" << std::endl;
		std::cout << "1.���� ����" << std::endl;
		std::cout << "2.�Ա�" << std::endl;
		std::cout << "3.���" << std::endl;
		std::cout << "4.�������� ��ü ���" << std::endl;
		std::cout << "5.���α׷� ����\n" << std::endl;
		std::cout << "���� : ";
		std::cin >> select;

		if (select == 1)
		{
			if (i == 100)
				std::cout << "���� �ִ�ġ�Դϴ�." << std::endl;
			else
			{
				value = makeaccount(client, i);
				if(value == 0)
				i++;
				else;
			}
		}					
		else if (select == 2)
			deposit(client);
		else if (select == 3)
			withdraw(client);
		else if (select == 4)
			printaccount(client, i);
		else if (select == 5)
			break;
		else
			std::cout << "�ùٸ� ���� �Է��ϼ���." << std::endl;
	}

	return 0;
}