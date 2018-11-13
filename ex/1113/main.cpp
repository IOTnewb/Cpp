#include <iostream>

using namespace std;

/*self reference 이해*/
class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "객 체 생 성" << endl;
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
	객체 자기자신을 가리키는 용도.

/*
class SoSimple
{
	int num;

public:
	SoSimple(int n) : num(n) // 생성자 + 멤버 이니셜라이즈
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
	/*self reference 이해
		자기 자신 참조하는 함수는
		리턴값을 *this? 합미다.
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