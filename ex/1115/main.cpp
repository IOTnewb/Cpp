#include "main.h"
#include "AccountManager.h"

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
	AccountManager copy = manager;
	int sel;

	while (1)
	{
		printmenu();
		cin >> sel;

		if (sel == 1)
			manager.Register_Client();
		else if (sel == 2)
		{
			while(1)
			{
				try
				{
					manager.deposit();
					break;
				}
				catch(DepositException &expn)
				{
					expn.ShowExceptionReason();
				}
			}
		}
		else if (sel == 3) 
		{
			while (1)
			{
				try
				{
					manager.withDraw();
					break;
				}
				catch (WithdrawException &expn)
				{
					expn.ShowExceptionReason();
				}
			}
		}
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