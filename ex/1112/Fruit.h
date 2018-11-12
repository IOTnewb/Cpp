#pragma once
#include "study.h"
/*
- 나는 과일장수에게 5000원어치 사과 구매한다.
- obj 후보
과일장수, 과일구매자


/*
1. 정보 은닉 잘하자 *****
2. 출력만 하는 함수는 const 화
3. 객체간 정보 공유를 참조자를 이용해서
*/

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
	FruitSeller(int price, int num, int money);
		
	// 사과 판매
	int SalesApples(int money);
	// 현재 상태 확인
	void ShowSalesResult() const;
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
	FruitBuyer(int money);
	// 사과 구입
	void BuyApples(FruitSeller &fruit, int money);
	// 현재 내 상태
	void ShowMyResult() const;
};
