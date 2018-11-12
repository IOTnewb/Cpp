#include <iostream>
#include <cstring>
using namespace std;

/*
	- 나는 과일장수에게 5000원어치 사과 구매한다.
	- obj 후보
	과일장수, 과일구매자


/*
	1. 정보 은닉 잘하자 *****
	2. 출력만 하는 함수는 const 화
	3. 객체간 정보 공유를 참조자를 이용해서
*/

/*
	캡슐화 - 범위 (ex 기본 감기약과 comtax)
	oop는 재사용성 유지보수 생각
	만들어 보세요
	감기 환자와 감기 약
*/

/*
	생성자도 함수니까 오버로딩 가능
	객 체 배 열 - 객체 자체가 저장되는 배열
	객 체 포 인 터 배 열 - 객체를 가리키는 포인터가 저장되는 배열
	객체포인터배열이 메모리 효율적 사용에 더 좋다
*/


/* 소 멸 자 */
class Person
{
private:
	char *name;
	int age;

public:
	// 매개 변수가 없는 constructor
	Person()
	{
		name = NULL;
		age = 0;
		cout << "Person() call" << endl;
	}
	// 매개 변수가 있는 constructor
	Person(const char *myName, int myAge)
	{
		int len = strlen(myName) + 1;
		name = new char[len];
		strcpy(name, myName);
		age = myAge;
	}
	//멤버 변수 수정 함수
	void SetPersonInfo(char *myName, int myAge)
	{
		name = myName;
		age = myAge;
	}


	//출 력 함 수
	void ShowPersonInfo() const
	{
		cout << "이 름 : " << name << endl;
		cout << "나 이 : " << age << endl;
	}
	// destructor
	~Person()
	{
		delete[]name;
		cout << "파 괴 한 다" << endl;
	}
};


/* 객 체 배 열 - 객체를 배열처럼 관리 */


/* 객 체 포 인 터 배 열 - 객체를 배열처럼 관리 */



/* this pointer */

/* 과 제 2 번 */

/* 캡슐화 - 범위(감기환자, 감기약);*/

// 종합 갬기약


//콧물 약 케슐
class SinivelCap
{
public:
	void Take() const
	{
		cout << "콧물이 멈춰" << endl;
	}
};
//재채기약 캡슐
class SneezeCap
{
public:
	void Take() const
	{
		cout << "재채기가 멈춰" << endl;
	}
};

//코막힘 약 캡슐
class SnuffCap
{
public:
	void Take() const
	{
		cout << "코가 뚫려" << endl;
	}
};


class compact600
{
private:
	SinivelCap scap;
	SneezeCap snecap;
	SnuffCap snucap;
public:
	void Take()
	{
		scap.Take();
		snecap.Take();
		snucap.Take();
	}
};

class Cold
{
public:
	//콧물 감기약 복용
	void TakeSinivelCap(SinivelCap &cap)
	{
		cap.Take();
	}
	void TakeSneezeCap(SneezeCap &cap)
	{
		cap.Take();
	}
	void TakeSnuffCap(SnuffCap &cap)
	{
		cap.Take();
	}
	void TakeCompactCap(compact600 &cap)
	{
		cap.Take();
	}

};

class med
{
	int nosemed;
	int couphmed;
	int closemed;
	int heatmed;
	int commed;

public:
	void prescribe(int nose, int couph, int close, int heat)					// 증세에 맞는 약 처방
	{
		if (nose)
		{
			nosemed++;
			cout << "콧물 약 처방" << endl;
		}
		if (couph)
		{
			couphmed++;
			cout << "기침 약 처방" << endl;
		}
		if (close)
		{
			closemed++;
			cout << "코막힘 약 처방" << endl;
		}
		if (heat)
		{
			heatmed++;
			cout << "해열제 처방" << endl;
		}

	}
};

class FruitSeller
{
private:
	// 단가	int apple_Price;
	const int APPLE_PRICE;
	// 재고
	int numOfApples;
	// 판매 수익
	int myMoney;

public:
	// 멤버 변수 초기화 -> 생성자
	FruitSeller(int price, int num, int money)
		: APPLE_PRICE(price)/* 멤버 이니셜라이즈
		numOfApples(num),		멤버 이니셜라이즈
		myMoney(money)			멤버 이니셜라이즈*/		
	{
		//APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	// 사과 판매
	int SalesApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	// 현재 상태 확인
	void ShowSalesResult() const
	{
		cout << "사과 재고 : " << numOfApples << endl;
		cout << "판매 수익 : " << myMoney << endl;
	}
};

class FruitBuyer
{
private:
	// 잔고
	int buyerMoney;
	// 사과 수량
	int numApple;

	
public:
	// 멤버 변수 초기화
	FruitBuyer(int money)
		: buyerMoney(money),
		numApple(0)
	{	/*
		buyerMoney = money;
		numApple = 0;
		*/
	}
	// 사과 구입
	void BuyApples(FruitSeller &fruit, int money)//C에서는 FruitSeller *fruit 사용 (포인터 변수)
	{
		numApple += fruit.SalesApples(money);
		buyerMoney -= money;
	}
	// 현재 내 상태
	void ShowMyResult() const
	{
		cout << "잔고 : " << buyerMoney << endl;
		cout << "사과 수량 : " << numApple << endl;
	}
};

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
	compact600 comcap;

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