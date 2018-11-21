#include "main.h"
#include "AccountManager.h"

void printmenu()
{
	cout << "----------- MENU --------------" << endl;
	cout << "1.계좌 개설" << endl;
	cout << "2.입금" << endl;
	cout << "3.출금" << endl;
	cout << "4.계좌정보 전체 출력" << endl;
	cout << "5.프로그램 종료\n" << endl;
	cout << "선택 : ";
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