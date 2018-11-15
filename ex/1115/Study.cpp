#include <iostream>

using namespace std;

/*
�� �� �� �� (Shallow Copy), �� �� �� �� (Deep Copy) 
- ���� ������ ������ �߻��ϴ� Ÿ�̹�
1. " = "

2. call by value ����� �Լ� ȣ���������
	��ü�� ���ڷ� ������ ��

3. ��ü�� ��ȯ�� �� ���������� ��ȯ���� �ʴ� ���

*/
class Person
{
private:
	char *name;
	int age;

public:
	Person(const char *myName, int myAge)
		:age(myAge)
	{
		int len = strlen(myName) + 1;
		name = new char[len];
		strcpy(name, myName);
	}

	Person(const Person &copy)
		:age(copy.age)
	{
		/* �� �� �� �� */
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);

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
	// destructor	/* �� �� �� */
	~Person()
	{
		delete[]name;
		cout << "�� �� �� ��" << endl;
	}
};


/*
class SoSimple
{
private:
	int num;
	int num1;
public:
	SoSimple(int n, int n1)
		:num(n), num1(n1)
	{}
	/* �� �� �� �� �� (Copy Constructor)
	explicit SoSimple(SoSimple &copy)
		: num(copy.num), num1(copy.num1)
	{
		cout << "Copy Constructor Called" << endl;
	}

	void ShowSimpleData()
	{
		cout << num << endl;
		cout << num1 << endl;
	}
};
*/
int main(void)
{
	/* �� �� �� �� (Shallow Copy) - ĳ������ �迭 ����*/
	Person man1("Lee", 25);
	Person man2 = man1; // ���� �޸� �ٶ�
	
	man1.ShowPersonInfo();
	/* ���� �޸� �ٶ󺸴� ���� ������Ű�� �ڿ��� �� ������ */

	/* �� �� �� �� �� 
	SoSimple sim1(20, 50);
	//SoSimple sim2 = sim1;
	SoSimple sim2(sim1);
	sim2.ShowSimpleData();
	*/
	return 0;
}

