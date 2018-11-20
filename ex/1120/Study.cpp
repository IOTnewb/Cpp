#include <iostream>
#include <cstring>

using namespace std;

/* ����Ʈ ���� �������� ������ */
class Person
{
private:
	char *name;
	int age;
public:
	Person(const char *myName, int myAge)
		: age(myAge)
	{
		int len = strlen(myName) + 1;
		name = new char[len];
		strcpy(name, myName);
	}

	void ShowPerson()
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}

	~Person()
	{
		delete[] name;
		cout << "called Destruct" << endl;
	}
};


class First
{
private:
	int num1;
	int num2;
public:
	First(int n1=0, int n2=0)
		: num1(n1), num2(n2)
	{}
	void ShowData()
	{
		cout << "[" << num1 << ", " << num2 << "]" << endl;
	}
};

class Second
{
private:
	int num3;
	int num4;
public:
	Second(int n3=0, int n4=0)
		: num3(n3), num4(n4)
	{}
	void ShowData()
	{
		cout << "[" << num3 << ", " << num4 << "]" << endl;
	}
	// ���� ������ �����ε�
	Second &operator=(const Second &cpy)
	{
		cout << "Second& operator=()" << endl;
		num3 = cpy.num3;
		num4 = cpy.num4;

		return *this;
	}
};



int main(void)
{
	/*		��ħ ����
			1. ���� �������� �����ε�
			- ���� �����ڿ� ���
			Ex) ���� ������
			Point pos1(3, 5);
			Point pos2 = pos1;		<- ���� ������	
			(= Point pos2(pos1);) <- �����Ϸ��� �ڵ� ����
			���� = ���� ���簡 �Ͼ��.
			�������� : ��� �� ��� ���� -> ��������
	*/

	// Point pos1(5, 7);
	// Point pos2(9, 10);
	// pos2 = pos1; -> pos2.operator=(pos1);
	// �� ��� ������ �����ε��� �ʿ��ϴ�.

	//First first(111, 222);
	//First cpy;

	//Second second(333, 444);
	//Second secpy;

	//cpy = first;
	//cpy.ShowData();
	//first.ShowData();

	//secpy = second;				// ���� ������ �����ε� ȣ��
	//second.ShowData();
	//secpy.ShowData();


	return 0;
}