#include <iostream>

using namespace std;

/* friend ���� */
class Girl;

class Boy
{
private:
	int height;
	friend class Girl;
public:
	Boy(int len) : height(len)
	{}

	void ShowYourFriendInfo(Girl &fnd);
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char *num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy &fnd);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl &fnd)
{
	cout << "Her phone number : " << fnd.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy &fnd)
{
	cout << "His Height : " << fnd.height << endl;
}

/* const �Լ� �����ε�
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{}

	SoSimple &AddNum(int n)
	{
		num += n;
		return *this;
	}

	void SimpleFunc()
	{
		cout << "SimpleFunc : " << num << endl;
	}

	void SimpleFunc() const
	{
		cout << "Const SimpleFunc : " << num << endl;
	}

};
*/
/* 
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{}

	SoSimple &AddNum(int n)
	{
		num += n;
		return *this;
	}

	void ShowData() const
	{
		cout << "Num : " << num << endl;
	}
};
*/
int main(void)
{
	/*
	const �Լ� �����ε� 
	- �Լ� �����ε� ���ǿ��� const ����

	SoSimple obj1(7);
	const SoSimple obj2(10);

	obj1.SimpleFunc();
	obj2.SimpleFunc();
	*/
	/* const ��ü 
	SoSimple generalobj(10);
	generalobj.AddNum(10);
	generalobj.ShowData();

	const SoSimple constobj(100);
	constobj.ShowData();

	// constobj.AddNum(200);	// ****** const ��ü�� const �Լ��� ��� �����ϴ�.
	*/
	
	/* 
	friend ����
	- friend ������ ��ü������ ĸ��ȭ���� ���������� �����ϴ� ������.
	- ����, friend ������ �ʿ��� ��Ȳ������ ����ؾ���.
	- ������ �����ε����� ���� �Լ��� ����� ���
	*/
	Boy boy(180);
	Girl girl("010-1234-5678");

	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);

	return 0;
}