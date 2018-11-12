#include <iostream>
#include <cstring>
using namespace std;

/*
	- ���� ����������� 5000����ġ ��� �����Ѵ�.
	- obj �ĺ�
	�������, ���ϱ�����


/*
	1. ���� ���� ������ *****
	2. ��¸� �ϴ� �Լ��� const ȭ
	3. ��ü�� ���� ������ �����ڸ� �̿��ؼ�
*/

/*
	ĸ��ȭ - ���� (ex �⺻ ������ comtax)
	oop�� ���뼺 �������� ����
	����� ������
	���� ȯ�ڿ� ���� ��
*/

/*
	�����ڵ� �Լ��ϱ� �����ε� ����
	�� ü �� �� - ��ü ��ü�� ����Ǵ� �迭
	�� ü �� �� �� �� �� - ��ü�� ����Ű�� �����Ͱ� ����Ǵ� �迭
	��ü�����͹迭�� �޸� ȿ���� ��뿡 �� ����
*/


/* �� �� �� */
class Person
{
private:
	char *name;
	int age;

public:
	// �Ű� ������ ���� constructor
	Person()
	{
		name = NULL;
		age = 0;
		cout << "Person() call" << endl;
	}
	// �Ű� ������ �ִ� constructor
	Person(const char *myName, int myAge)
	{
		int len = strlen(myName) + 1;
		name = new char[len];
		strcpy(name, myName);
		age = myAge;
	}
	//��� ���� ���� �Լ�
	void SetPersonInfo(char *myName, int myAge)
	{
		name = myName;
		age = myAge;
	}


	//�� �� �� ��
	void ShowPersonInfo() const
	{
		cout << "�� �� : " << name << endl;
		cout << "�� �� : " << age << endl;
	}
	// destructor
	~Person()
	{
		delete[]name;
		cout << "�� �� �� ��" << endl;
	}
};


/* �� ü �� �� - ��ü�� �迭ó�� ���� */


/* �� ü �� �� �� �� �� - ��ü�� �迭ó�� ���� */



/* this pointer */

/* �� �� 2 �� */

/* ĸ��ȭ - ����(����ȯ��, �����);*/

// ���� �����


//�๰ �� �ɽ�
class SinivelCap
{
public:
	void Take() const
	{
		cout << "�๰�� ����" << endl;
	}
};
//��ä��� ĸ��
class SneezeCap
{
public:
	void Take() const
	{
		cout << "��ä�Ⱑ ����" << endl;
	}
};

//�ڸ��� �� ĸ��
class SnuffCap
{
public:
	void Take() const
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
	/* �� ü �� �� �� �� �� - ��ü�� �迭ó�� ���� */
	Person *personParray[3];

	char namestr[100];
	char *strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
		cin >> age;

		personParray[i] = new Person(namestr, age); // ��ü�� �ּҰ� ���ϵȴ�.
	}

	personParray[0]->ShowPersonInfo();
	personParray[1]->ShowPersonInfo();
	personParray[2]->ShowPersonInfo();

	delete personParray[0];
	delete personParray[1];
	delete personParray[2];
	// new ���ų� �����Ҵ� �ϰų�

	/* �� ü �� �� - �����Ϸ��� Ŭ���� ���� ���� ������ �׷��ڱ��� �ϰ� ���絥��
	Person PersonArray[3];

	char namestr[100];
	char *strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
		cin >> age;

		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		PersonArray[i].SetPersonInfo(strptr, age);
	}

	PersonArray[0].ShowPersonInfo();
	PersonArray[1].ShowPersonInfo();
	PersonArray[2].ShowPersonInfo();

	/* �� �� �� 
	Person man1("A MU GAE", 25);
	Person man2("GAE MU GAE", 29);

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	/* ĸ �� ȭ - �� �� 
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