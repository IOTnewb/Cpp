#include "main.h"
#include "AccountManager.h"

void printmenu()
{
	cout << "----------- MENU --------------" << endl;
	cout << "1.���� ����" << endl;
	cout << "2.�Ա�" << endl;
	cout << "3.���" << endl;
	cout << "4.�������� ��ü ���" << endl;
	cout << "5.���α׷� ����\n" << endl;
	cout << "���� : ";
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
			copy.Register_Client();
		else if (sel == 2)
			copy.deposit();
		else if (sel == 3)
			copy.withDraw();
		else if (sel == 4)
			copy.PrintAllAccount();
		else if (sel == 5)
				{
					copy.exit();
					break;
				}
		
	}
	return 0;
}