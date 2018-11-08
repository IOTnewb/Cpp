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

int Adder(int num1 = 1, int num2 = 2);	// 디폴트 매개변수

void MyFunc(void)						// 함수 오버로딩
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
	using BestComIpml::SimpleFunc;		// using 사용한 namespace 생략 ( 남발하면 가독성 저해 )

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
	
	std::cout << "이름을 입력하세요 : ";
	std::cin >> name;

	std::cout << "좋아하는 언어 : ";
	std::cin >> lang;

	std::cout << "내 이름은 " << name << "입니다. \n" << std::endl;
	std::cout << "좋아하는 언어는 " << lang << "입니다." << std::endl;

	
	int val;
	std::cout << "첫 번째 숫자를 입력 : ";
	std::cin >> val;
	
	int val2;
	std::cout << "두 번째 숫자를 입력 : ";
	std::cin >> val2;

	int result = val + val2;
	std::cout << "덧셈 결과 : " << result << std::endl;


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
