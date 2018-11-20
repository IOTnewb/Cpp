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

int Adder(int num1 = 1, int num2 = 2);	// 디폴트 매개변수 - 매개변수로 넘기면서 초기화 가능

void MyFunc(void)						// 함수 오버로딩
{
	std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c)					// 이름이 같은 함수를 매개변수만 다르게 재정의 가능
{
	std::cout << "MyFunc(char a) called" << std::endl;
}

void MyFunc(int a, int b)			// 컴파일러가 매개변수를 확인하고 해당 함수의 내용을 실행
{
	std::cout << "MyFunc(int a, int b) called" << std::endl;
}

int main(void)
{
	char *str = MakeStrAdtr(20);	// 함수로 생성된 공간의 주소를 받음
	strcpy(str, "I am tired");
	std::cout << str << std::endl;		// std 라는 namespace 에 있는 cout, endl 사용
	delete(str);										// 종료 전 할당받은 메모리 해제


	/* boolean	- true, false 만 가지는 1비트 자료형
	std::cout << "true : " << true << std::endl;
	std::cout << "false : " << false << std::endl;

	/* inline func - 프로그램의 실행 속도를 높이기 위해 추가된 기능
	- 어디서 가져올거 없이 매크로적인거 바로 가져다 써서 속도면에서 좋다. 디버깅이 용이하다.

	std::cout << SQUARE(5) << std::endl;
			//-> ((5)*(5))
	std::cout << SQUARE(5.5) << std::endl;
			
	/* 다중 namespace 사용의 예
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	// namespace 재정의?
	namespace ABC = AAA::BBB::CCC;

	std::cout << ABC::num1 << std::endl;
	std::cout << ABC::num2 << std::endl;


	/*
	using BestComIpml::SimpleFunc;		// using 사용한 namespace 생략 ( **남발하면 가독성 저해** )

	SimpleFunc();
	ProgComlmpl::SimpleFunc();


	/* 함수 재정의 - 매개변수에 따라 다른 함수 실행
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

	
	// C++은 Cin Cout 사용해서 입 출력 하는데
	// >> 및 << 의 재정의가 잘되어 있어서 타입을 알아서 찾아냄
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
