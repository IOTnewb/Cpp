#include <iostream>

using namespace std;

/*self reference ����*/
class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "�� ü �� ��" << endl;
	}
	SelfRef& Adder(int n)
	{
		num += n;
		return *this;
	}
	SelfRef& ShowNumber()
	{
		cout << num << endl;
		return *this;
	}
};

/*this pointer app
class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1;
		this->num2 = num2;
	}

	void ShowTwoNumber()
	{
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};
*/


/* this pointer
	��ü �ڱ��ڽ��� ����Ű�� �뵵.

/*
class SoSimple
{
	int num;

public:
	SoSimple(int n) : num(n) // ������ + ��� �̴ϼȶ�����
	{
		cout << "num = " << num << endl;
		cout << "address = " << this << endl;
	}
	void ShowSimpleData()
	{
		cout << num << endl;
	}
	SoSimple *GetThisPointer()
	{
		return this;
	}
};*/


int main(void)
{
	/*self reference ����
		�ڱ� �ڽ� �����ϴ� �Լ���
		���ϰ��� *this? �չ̴�.
	*/
	SelfRef obj(3);
	SelfRef &ref = obj.Adder(2);

	obj.ShowNumber();
	ref.ShowNumber();

	/* this pointer app
	TwoNumber two1(2, 4);
	two1.ShowTwoNumber();
	/*
	SoSimple sim1(100);
	SoSimple *ptr1 = sim1.GetThisPointer();
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(100);
	SoSimple *ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	*/
	return 0;
}