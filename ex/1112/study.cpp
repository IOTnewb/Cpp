#include <iostream>
using namespace std;

/*
	- ���� ����������� 5000����ġ ��� �����Ѵ�.
	- obj �ĺ�
		�������, ���ϱ�����
*/

/*
	1. ���� ���� ������
	2. ��¸� �ϴ� �Լ��� const ȭ
	3. ��ü�� ���� ������ �����ڸ� �̿��ؼ�

*/

/*
	ĸ��ȭ - ����
	oop�� ���뼺 �������� ����
	����� ������
	���� ȯ�ڿ� ���� ��
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
	FruitSeller(int price, int num, int money)
		: APPLE_PRICE(price)/* ��� �̴ϼȶ�����
		numOfApples(num),		��� �̴ϼȶ�����
		myMoney(money)			��� �̴ϼȶ�����*/		
	{
		//APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	// ��� �Ǹ�
	int SalesApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	// ���� ���� Ȯ��
	void ShowSalesResult() const
	{
		cout << "��� ��� : " << numOfApples << endl;
		cout << "�Ǹ� ���� : " << myMoney << endl;
	}
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
	FruitBuyer(int money)
		: buyerMoney(money),
		numApple(0)
	{	/*
		buyerMoney = money;
		numApple = 0;
		*/
	}
	// ��� ����
	void BuyApples(FruitSeller &fruit, int money)//C������ FruitSeller *fruit ��� (������ ����)
	{
		numApple += fruit.SalesApples(money);
		buyerMoney -= money;
	}
	// ���� �� ����
	void ShowMyResult() const
	{
		cout << "�ܰ� : " << buyerMoney << endl;
		cout << "��� ���� : " << numApple << endl;
	}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);

	//��� �ŷ� �߻�
	buyer.BuyApples(seller, 2000);


	cout << "���� ��� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� ������ ��Ȳ" << endl;
	buyer.ShowMyResult();
	return 0;
}