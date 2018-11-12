#include <iostream>
#include <cstring>
using namespace std;

/*
	- 나는 과일장수에게 5000원어치 사과 구매한다.
	- obj 후보
		과일장수, 과일구매자
*/

/*
	1. 정보 은닉 잘하자
	2. 출력만 하는 함수는 const 화
	3. 객체간 정보 공유를 참조자를 이용해서

*/

/*
	캡슐화 - 범위
	oop는 재사용성 유지보수 생각
	만들어 보세요
	감기 환자와 감기 약
*/

/* 소 멸 자 */
class Person
{
private:
	char *name;
	int age;
public:
	// constructor
	Person(char *myName, int myAge)
	{
		int len = strlen(myName) + 1;
		name = new char[len];
		strcpy(name, myName);
		age = myAge;
	}
	//출 력 함 수
	void ShowPersonInfo()
	{
		cout << "이 름 : " << name << endl;
		cout << "나 이 : " << age << endl;
	}
	// destructor
	~Person()
	{
		delete[]name;
	}
};


/* 객 체 배 열 */

/* this pointer */

/* 과 제 2 번 */

/* 캡슐화 - 범위(감기환자, 감기약);*/

// 종합 갬기약


//콧물 약 케슐
class SinivelCap
{
public:
	void Take()
	{
		cout << "콧물이 멈춰" << endl;
	}
};
//재채기약 캡슐
class SneezeCap
{
public:
	void Take()
	{
		cout << "재채기가 멈춰" << endl;
	}
};

//코막힘 약 캡슐
class SnuffCap
{
public:
	void Take()
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
	/* 캡 슐 화 - 범 위 */
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