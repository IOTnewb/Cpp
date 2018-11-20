#include <iostream>
#include <cstring>

using namespace std;



//	class Second	: public First
//{
//private:
//	int num3;
//	int num4;
//public:
//	Second(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0)
//		: First(n1, n2), num3(n3), num4(n4)
//	{}
//	void ShowData()
//	{
//		First::ShowData();
//		cout << "[" << num3 << ", " << num4 << "]" << endl;
//	}
//	/*		���� ������ �����ε�	
//			- �θ�, �ڽİ� ������ ���Կ����� �����ε��� ������
//			- �ڽ��� ���Կ����� �����ε��� ȣ��
//			- �ڽ� ���Կ����� �����ε� �ȿ� �θ� ���Կ����� �����ε� �Լ� ȣ��
//	*/
//	Second &operator=(const Second &cpy)
//	{
//		First::operator=(cpy);		// ������ (��Ӱ��谡 is A ����)
//		cout << "Second &operator=()" << endl;
//		num3 = cpy.num3;
//		num4 = cpy.num4;
//
//		return *this;
//	}
//};

 //����Ʈ ���� �������� ������ 
//class Person
//{
//private:
//	char *name;
//	int age;
//public:
//	Person(const char *myName, int myAge)
//		: age(myAge)
//	{
//		int len = strlen(myName) + 1;
//		name = new char[len];
//		strcpy(name, myName);
//	}
//
//	void ShowPerson()
//	{
//		cout << "�̸� : " << name << endl;
//		cout << "���� : " << age << endl;
//	}
//
//	Person &operator=(const Person &cpy)
//	{
//		delete[] name;										// �޸� ���� ����
//		int len = strlen(cpy.name) + 1;
//		name = new char[len];
//		strcpy(name, cpy.name);
//		age = cpy.age;
//		return *this;
//	}
//
//	~Person()
//	{
//		delete[] name;
//		cout << "called Destruct" << endl;
//	}
//};


/*class First
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
};*/

//class Second
//{
//private:
//	int num3;
//	int num4;
//public:
//	Second(int n3=0, int n4=0)
//		: num3(n3), num4(n4)
//	{}
//	void ShowData()
//	{
//		cout << "[" << num3 << ", " << num4 << "]" << endl;
//	}
//	// ���� ������ �����ε�
//	Second &operator=(const Second &cpy)
//	{
//		cout << "Second& operator=()" << endl;
//		num3 = cpy.num3;
//		num4 = cpy.num4;
//		return *this;
//	}
//};

/*		��� ���迡���� ���� ������
class A					|		class B
int num1 num2		int num3 num4
class B : public A
- �θ� class ���� �����ڰ� �ڵ����� �ҷ�����?
*/

/*	 ��� ���迡�� �⺻ ���� ������ ȣ�� */
/*class First
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

First &operator=(const First &cpy)
{
cout << "First &operator=()" << endl;
num1 = cpy.num1;
num2 = cpy.num2;
return *this;
}
};*/

	/* �迭 ���� ������ �����ε�*/
//class BoundCheckIntArray
//{
//private:
//	int *arr;
//	int arrlen;
//public:
//	BoundCheckIntArray(int len)
//		: arrlen(len)
//	{
//		arr = new int[len];
//	}
//
//	int Getlen() const
//	{
//		return arrlen;
//	}
//
//	int &operator[](int idx) const
//	{
//		// �迭 ���� üũ
//		if (idx < 0 || idx >= arrlen)
//		{
//			cout << "�迭 ������ �����" << endl;
//			exit(1);
//		}
//
//		return arr[idx];
//	}
//
//	int &operator[](int idx)
//	{
//		// �迭 ���� üũ
//		if (idx < 0 || idx >= arrlen)
//		{
//			cout << "�迭 ������ �����" << endl;
//			exit(1);
//		}
//
//		return arr[idx];
//	}
//
//	~BoundCheckIntArray()
//	{
//		delete[]arr;
//	}
//};
//
//void ShowAllData(const BoundCheckIntArray &cpy)
//{
//	for (int i = 0; i < cpy.Getlen(); i++)
//	{
//		cout << cpy[i] << endl;
//	}
//}

/* ���� ó�� - Exception Handling */


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
	

		point pos1(5, 7);
		point pos2(9, 10);
		pos2 = pos1; -> pos2.operator=(pos1);
		�� ��� ������ �����ε��� �ʿ��ϴ�.
	*/

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

	/*		����Ʈ ���� �������� ������ 
			1. ������ ���� �����Ϸ���
			2. man2 ���� ������ �ȵ�
			==> ������ �����ε� �ʿ�
	*/
	//Person man1("dnjswn", 25);
	//Person man2("qhdwn", 30);

	//man2 = man1;
	//// man2.operator=(man1);

	//man1.ShowPerson();
	//man2.ShowPerson();

	/*	 ��� ���迡�� �⺻ ���� ������ ȣ�� */
	/*Second second(111, 222, 333, 444);
	Second secpy;

	secpy = second;

	secpy.ShowData();
	second.ShowData();
	*/

	/* �迭 �ε��� ������ �����ε� */

	//arrobject[2];

	//complier view
	//arrobject.operator[](2)

	//programmer view
	/*BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i + 1) * 11;
	}*/
	
	/*for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << endl;
	}*/
	
	//ShowAllData(arr);

	/* ���� ó�� - Exception Handling in C++ */
	//try ��� - �� �� �� ��
	//catch ��� - �� �� ó ��
	//throw ��� - �� �� ó �� �� ��
	int num1, num2;
	cout << "�� ���� ���� �Է� : ";
	cin >> num1 >> num2;		// �� �� �� ��

	try
	{
		if (num2 == 0)					// �� �� �c
			throw num2;
		else
		{
			cout << "�������� �� : " << num1 / num2 << endl;
			cout << "�������� ������ : " << num1 % num2 << endl;
		}
	}
	catch(int expn)			// try���� throw �� ������ Ÿ������ �޾ƾߵȴ�.
	{
		cout << "������ " << expn <<"�� �� �� �����ϴ�." << endl;
		cout << "���α׷� ����Ÿ��" << endl;
	}
	

	/* ���� ó�� - Exception Handling in C */
	//int num1, num2;
	//cout << "�� ���� ���� �Է� : ";
	//cin >> num1 >> num2;		// �� �� �� ��
	//
	//if (num2 == 0)					// �� �� �c
	//{												// �� �� ó ��
	//	cout << "������ 0�� �� �� �����ϴ�." << endl;
	//	cout << "���α׷� ����Ÿ��" << endl;
	//}
	//else
	//{
	//	cout << "�������� �� : " << num1 / num2 << endl;
	//	cout << "�������� ������ : " << num1 % num2 << endl;

	//}
	return 0;
}