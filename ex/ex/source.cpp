#include <iostream>
#include <cstring>

namespace AAA
{
	namespace BBB
	{
		namespace CCC
		{
			int num1;
			int num2;
		}
	}
}

namespace BestComIpml {					// namespace
	void SimpleFunc(void);
}

namespace ProgComlmpl {
	void SimpleFunc(void);
}

int Adder(int num1 = 1, int num2 = 2);	// ����Ʈ �Ű�����

void MyFunc(void)						// �Լ� �����ε�
{
	std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c)
{
	std::cout << "MyFunc(char a) called" << std::endl;
}

void MyFunc(int a, int b)
{
	std::cout << "MyFunc(int a, int b) called" << std::endl;
}

int main(void)
{
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	namespace ABC = AAA::BBB::CCC;

	std::cout << ABC::num1 << std::endl;
	std::cout << ABC::num2 << std::endl;


	/*
	using BestComIpml::SimpleFunc;		// using ����� namespace ���� ( �����ϸ� ������ ���� )

	SimpleFunc();
	ProgComlmpl::SimpleFunc();


	
	std::cout << Adder() << std::endl;
	std::cout << Adder(3) << std::endl;
	std::cout << Adder(3, 5) << std::endl;

	
	MyFunc();
	MyFunc('a');
	MyFunc(12, 22);

	
	char name[100];
	char lang[200];
	
	std::cout << "�̸��� �Է��ϼ��� : ";
	std::cin >> name;

	std::cout << "�����ϴ� ��� : ";
	std::cin >> lang;

	std::cout << "�� �̸��� " << name << "�Դϴ�. \n" << std::endl;
	std::cout << "�����ϴ� ���� " << lang << "�Դϴ�." << std::endl;

	
	int val;
	std::cout << "ù ��° ���ڸ� �Է� : ";
	std::cin >> val;
	
	int val2;
	std::cout << "�� ��° ���ڸ� �Է� : ";
	std::cin >> val2;

	int result = val + val2;
	std::cout << "���� ��� : " << result << std::endl;


	int num = 20;
	std::cout << "Hello World." << std::endl;
	std::cout << "hello" << "world." << std::endl;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;
	*/
	return 0;
}

void BestComIpml::SimpleFunc(void)
{
	std::cout << "BestCom Func" << std::endl;
}

void ProgComlmpl::SimpleFunc(void)
{
	std::cout << "ProgCom Func" << std::endl;
}

int Adder(int num1, int num2)
{
	return num1 + num2;
}
