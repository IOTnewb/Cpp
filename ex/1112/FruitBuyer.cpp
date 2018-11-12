#include "Fruit.h"

FruitBuyer::FruitBuyer(int money)
	: buyerMoney(money),
	numApple(0)
{	/*
	buyerMoney = money;
	numApple = 0;
	*/
}

void FruitBuyer::BuyApples(FruitSeller &fruit, int money)//C������ FruitSeller *fruit ��� (������ ����)
{
	numApple += fruit.SalesApples(money);
	buyerMoney -= money;
}

// ���� �� ����
void FruitBuyer::ShowMyResult() const
{
	cout << "�ܰ� : " << buyerMoney << endl;
	cout << "��� ���� : " << numApple << endl;
}