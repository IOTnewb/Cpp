#include "Fruit.h"

FruitBuyer::FruitBuyer(int money)
	: buyerMoney(money),
	numApple(0)
{	/*
	buyerMoney = money;
	numApple = 0;
	*/
}

void FruitBuyer::BuyApples(FruitSeller &fruit, int money)//C에서는 FruitSeller *fruit 사용 (포인터 변수)
{
	numApple += fruit.SalesApples(money);
	buyerMoney -= money;
}

// 현재 내 상태
void FruitBuyer::ShowMyResult() const
{
	cout << "잔고 : " << buyerMoney << endl;
	cout << "사과 수량 : " << numApple << endl;
}