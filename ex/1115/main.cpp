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
	BoundCheckAccountArray Array(100);
	int sel;

	while (1)
	{
		printmenu();
		cin >> sel;

		if (sel == 1)
			Array.CopyAccount(Array.list->Register_Client());
		else if (sel == 2)
			Array.list->deposit();
		else if (sel == 3)
			Array.list->withDraw();
		else if (sel == 4)
			Array.list->PrintAllAccount();
		else if (sel == 5)
				{
			Array.list->exit();
					break;
				}
		
	}
	return 0;
}