#include <iostream>
#include <cstring>
#include <stdlib.h>

char * MakeStrAdtr(int len)		// C++ MemoryAllocation
{
	//char * str = (char*)malloc(sizeof(char)*len); // in C
	char *str = new char[len];
	return str;
}

//#define SQUARE(x) ((x)*(x))

template <typename T>

inline T SQUARE(T x)
{
	return x * x;
}

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

int Adder(int num1 = 1, int num2 = 2);	// ����Ʈ �Ű����� - �Ű������� �ѱ�鼭 �ʱ�ȭ ����

void MyFunc(void)						// �Լ� �����ε�
{
	std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c)					// �̸��� ���� �Լ��� �Ű������� �ٸ��� ������ ����
{
	std::cout << "MyFunc(char a) called" << std::endl;
}

void MyFunc(int a, int b)			// �����Ϸ��� �Ű������� Ȯ���ϰ� �ش� �Լ��� ������ ����
{
	std::cout << "MyFunc(int a, int b) called" << std::endl;
}

int main(void)
{
	char *str = MakeStrAdtr(20);	// �Լ��� ������ ������ �ּҸ� ����
	strcpy(str, "I am tired");
	std::cout << str << std::endl;		// std ��� namespace �� �ִ� cout, endl ���
	delete(str);										// ���� �� �Ҵ���� �޸� ����


	/* boolean	- true, false �� ������ 1��Ʈ �ڷ���
	std::cout << "true : " << true << std::endl;
	std::cout << "false : " << false << std::endl;

	/* inline func - ���α׷��� ���� �ӵ��� ���̱� ���� �߰��� ���
	- ��� �����ð� ���� ��ũ�����ΰ� �ٷ� ������ �Ἥ �ӵ��鿡�� ����. ������� �����ϴ�.

	std::cout << SQUARE(5) << std::endl;
			//-> ((5)*(5))
	std::cout << SQUARE(5.5) << std::endl;
			
	/* ���� namespace ����� ��
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	// namespace ������?
	namespace ABC = AAA::BBB::CCC;

	std::cout << ABC::num1 << std::endl;
	std::cout << ABC::num2 << std::endl;


	/*
	using BestComIpml::SimpleFunc;		// using ����� namespace ���� ( **�����ϸ� ������ ����** )

	SimpleFunc();
	ProgComlmpl::SimpleFunc();


	/* �Լ� ������ - �Ű������� ���� �ٸ� �Լ� ����
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

	
	// C++�� Cin Cout ����ؼ� �� ��� �ϴµ�
	// >> �� << �� �����ǰ� �ߵǾ� �־ Ÿ���� �˾Ƽ� ã�Ƴ�
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
