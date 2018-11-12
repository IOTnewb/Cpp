#include <iostream>
#include <cstring>
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

/* �� �� �� */
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
	//�� �� �� ��
	void ShowPersonInfo()
	{
		cout << "�� �� : " << name << endl;
		cout << "�� �� : " << age << endl;
	}
	// destructor
	~Person()
	{
		delete[]name;
	}
};


/* �� ü �� �� */

/* this pointer */

/* �� �� 2 �� */

/* ĸ��ȭ - ����(����ȯ��, �����);*/

// ���� �����


//�๰ �� �ɽ�
class SinivelCap
{
public:
	void Take()
	{
		cout << "�๰�� ����" << endl;
	}
};
//��ä��� ĸ��
class SneezeCap
{
public:
	void Take()
	{
		cout << "��ä�Ⱑ ����" << endl;
	}
};

//�ڸ��� �� ĸ��
class SnuffCap
{
public:
	void Take()
	{
		cout << "�ڰ� �շ�" << endl;
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
	//�๰ ����� ����
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
	void prescribe(int nose, int couph, int close, int heat)					// ������ �´� �� ó��
	{
		if (nose)
		{
			nosemed++;
			cout << "�๰ �� ó��" << endl;
		}
		if (couph)
		{
			couphmed++;
			cout << "��ħ �� ó��" << endl;
		}
		if (close)
		{
			closemed++;
			cout << "�ڸ��� �� ó��" << endl;
		}
		if (heat)
		{
			heatmed++;
			cout << "�ؿ��� ó��" << endl;
		}

	}
};

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
	/* ĸ �� ȭ - �� �� */
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

	

	//��� �ŷ� �߻�
	buyer.BuyApples(seller, 2000);


	cout << "���� ��� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� ������ ��Ȳ" << endl;
	buyer.ShowMyResult();
	*/
	return 0;
}