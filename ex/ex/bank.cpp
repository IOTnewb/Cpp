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


	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌ID : ";
	std::cin >> arg.ID;
	for (j = 0; j < 100; j++)
	{
		if (client[j].ID == arg.ID)
			{
				std::cout << "이미 존재하는 ID입니다." << std::endl;
				x++;
			}
		
	}
	if(x != 1)
	{
		std::cout << "이름 : ";
		std::cin >> arg.name;
		std::cout << "입금액 : ";
		std::cin >> arg.cash;
		std::cout << "개설완료 되었습니다." << std::endl;

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
	std::cout << "[입금]" << std::endl;
	std::cout << "계좌ID : ";
	std::cin >> ID;
	for (i = 0; i < 100; i++)
	{
		if(client[i].ID == ID)
		{
			while(1)
			{ 
			std::cout << "입금액 : ";
			std::cin >> cash;
				if (cash < 0)
				{
					std::cout << "잘못된 값입니다.";
				}
				else
				{
					client[i].cash += cash;
					std::cout << "입금완료 되었습니다." << std::endl;
					break;
				}
			}
		}
		else x++;
	}
	if(x==100)
		std::cout << "존재하지 않는 계좌입니다." << std::endl;
}

void withdraw(account* client)
{
	int i;
	int x=0;
	int ID;
	int cash;
	std::cout << "[출금]" << std::endl;
	std::cout << "계좌ID : ";
	std::cin >> ID;
	
	for (i = 0; i < 100; i++)
	{
		if (client[i].ID == ID)
		{
			std::cout << "출금액 : ";
			std::cin >> cash;
			if (client[i].cash - cash < 0)
				std::cout << "잔액부족입니다." << std::endl;
			else
			{
				client[i].cash -= cash;
				std::cout << "출금완료 되었습니다." << std::endl;
			}
		}
		else x++;
	}
	if(x==100)
		std::cout << "존재하지 않는 계좌입니다." << std::endl;
}

void printaccount(account* client, int i)
{
	int j;
	std::cout << "[전체 출력]" << std::endl;
	std::cout << "개설된 전체 계좌 수 : " << i << std::endl;

	for (j = 0; j < i; j++)
	{
		std::cout << "계좌 ID : " << client[j].ID << std::endl;
		std::cout << "이름	  : " << client[j].name << std::endl;
		std::cout << "입금액  : " << client[j].cash << std::endl;
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
		std::cout << "1.계좌 개설" << std::endl;
		std::cout << "2.입금" << std::endl;
		std::cout << "3.출금" << std::endl;
		std::cout << "4.계좌정보 전체 출력" << std::endl;
		std::cout << "5.프로그램 종료\n" << std::endl;
		std::cout << "선택 : ";
		std::cin >> select;

		if (select == 1)
		{
			if (i == 100)
				std::cout << "개설 최대치입니다." << std::endl;
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
			std::cout << "올바른 값을 입력하세요." << std::endl;
	}

	return 0;
}