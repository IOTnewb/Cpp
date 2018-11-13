#include "study.h"
#include "Fruit.h"
#include "medicine.h"
#include "Person.h"

/* 객 체 배 열 - 객체를 배열처럼 관리 */
/* 객 체 포 인 터 배 열 - 객체를 배열처럼 관리 */

/* this pointer */

/* 과 제 2 번 */

/* 캡슐화 - 범위(감기환자, 감기약);*/

int main(void)
{
	/* 객 체 포 인 터 배 열 - 객체를 배열처럼 관리 */
	Person *personParray[3];

	char namestr[100];
	char *strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;

		personParray[i] = new Person(namestr, age); // 객체의 주소가 리턴된다.
	}

	personParray[0]->ShowPersonInfo();
	personParray[1]->ShowPersonInfo();
	personParray[2]->ShowPersonInfo();

	delete personParray[0];
	delete personParray[1];
	delete personParray[2];
	// new 쓰거나 동적할당 하거나

	/* 객 체 배 열 - 컴파일러가 클래스 스윽 보고 딱봐도 그렇겠구나 하고 만든데요
	Person PersonArray[3];

	char namestr[100];
	char *strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;

		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		PersonArray[i].SetPersonInfo(strptr, age);
	}

	PersonArray[0].ShowPersonInfo();
	PersonArray[1].ShowPersonInfo();
	PersonArray[2].ShowPersonInfo();

	/* 소 멸 자 
	Person man1("A MU GAE", 25);
	Person man2("GAE MU GAE", 29);

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	/* 캡 슐 화 - 범 위 
	SinivelCap sp;
	SneezeCap snp;
	SnuffCap snup;
	compact600 comcap;	//	한번에 약 다먹기

	Cold patient;

	patient.TakeSinivelCap(sp);
	patient.TakeSneezeCap(snp);
	patient.TakeSnuffCap(snup);

	patient.TakeCompactCap(comcap);

	/*
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);

	

	//사과 거래 발생
	buyer.BuyApples(seller, 2000);


	cout << "과일 장수 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자 현황" << endl;
	buyer.ShowMyResult();
	*/
	return 0;
}