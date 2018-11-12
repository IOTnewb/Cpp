#include "Fruit.h"

FruitSeller::FruitSeller(int price, int num, int money)
	: APPLE_PRICE(price)/* ��� �̴ϼȶ�����
						numOfApples(num),		��� �̴ϼȶ�����
						myMoney(money)			��� �̴ϼȶ�����*/
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
	cout << "��� ��� : " << numOfApples << endl;
	cout << "�Ǹ� ���� : " << myMoney << endl;
}