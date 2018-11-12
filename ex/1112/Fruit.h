#pragma once
#include "study.h"
/*
- ���� ����������� 5000����ġ ��� �����Ѵ�.
- obj �ĺ�
�������, ���ϱ�����


/*
1. ���� ���� ������ *****
2. ��¸� �ϴ� �Լ��� const ȭ
3. ��ü�� ���� ������ �����ڸ� �̿��ؼ�
*/

class FruitSeller
{
private:
	// �ܰ�	int apple_Price;
	const int APPLE_PRICE;
	// ���
	int numOfApples;
	// �Ǹ� ����
	int myMoney;

public:
	// ��� ���� �ʱ�ȭ -> ������
	FruitSeller(int price, int num, int money);
		
	// ��� �Ǹ�
	int SalesApples(int money);
	// ���� ���� Ȯ��
	void ShowSalesResult() const;
};

class FruitBuyer
{
private:
	// �ܰ�
	int buyerMoney;
	// ��� ����
	int numApple;


public:
	// ��� ���� �ʱ�ȭ
	FruitBuyer(int money);
	// ��� ����
	void BuyApples(FruitSeller &fruit, int money);
	// ���� �� ����
	void ShowMyResult() const;
};
