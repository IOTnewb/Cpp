#include "study.h"
#include "Fruit.h"
#include "medicine.h"
#include "Person.h"

/* �� ü �� �� - ��ü�� �迭ó�� ���� */
/* �� ü �� �� �� �� �� - ��ü�� �迭ó�� ���� */

/* this pointer */

/* �� �� 2 �� */

/* ĸ��ȭ - ����(����ȯ��, �����);*/

int main(void)
{
	/* �� ü �� �� �� �� �� - ��ü�� �迭ó�� ���� */
	Person *personParray[3];

	char namestr[100];
	char *strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
		cin >> age;

		personParray[i] = new Person(namestr, age); // ��ü�� �ּҰ� ���ϵȴ�.
	}

	personParray[0]->ShowPersonInfo();
	personParray[1]->ShowPersonInfo();
	personParray[2]->ShowPersonInfo();

	delete personParray[0];
	delete personParray[1];
	delete personParray[2];
	// new ���ų� �����Ҵ� �ϰų�

	/* �� ü �� �� - �����Ϸ��� Ŭ���� ���� ���� ������ �׷��ڱ��� �ϰ� ���絥��
	Person PersonArray[3];

	char namestr[100];
	char *strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
		cin >> age;

		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		PersonArray[i].SetPersonInfo(strptr, age);
	}

	PersonArray[0].ShowPersonInfo();
	PersonArray[1].ShowPersonInfo();
	PersonArray[2].ShowPersonInfo();

	/* �� �� �� 
	Person man1("A MU GAE", 25);
	Person man2("GAE MU GAE", 29);

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	/* ĸ �� ȭ - �� �� 
	SinivelCap sp;
	SneezeCap snp;
	SnuffCap snup;
	compact600 comcap;	//	�ѹ��� �� �ٸԱ�

	Cold patient;

	patient.TakeSinivelCap(sp);
	patient.TakeSneezeCap(snp);
	patient.TakeSnuffCap(snup);

	patient.TakeCompactCap(comcap);

	/*
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);

	

	//��� �ŷ� �߻�
	buyer.BuyApples(seller, 2000);


	cout << "���� ��� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� ������ ��Ȳ" << endl;
	buyer.ShowMyResult();
	*/
	return 0;
}