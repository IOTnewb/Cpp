#include "Fruit.h"

FruitSeller::FruitSeller(int price, int num, int money)
	: APPLE_PRICE(price)/* 멤버 이니셜라이즈
						numOfApples(num),		멤버 이니셜라이즈
						myMoney(money)			멤버 이니셜라이즈*/
{
	//APPLE_PRICE = price;
	numOfApples = num;
	myMoney = money;
}

int FruitSeller::SalesApples(int money)
{
	int num = money / APPLE_PRICE;
	numOfApples -= num;
	myMoney += money;
	return num;
}

void FruitSeller::ShowSalesResult() const
{
	cout << "사과 재고 : " << numOfApples << endl;
	cout << "판매 수익 : " << myMoney << endl;
}