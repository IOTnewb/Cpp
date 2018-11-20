#include <iostream>
#include <cstring>

using namespace std;

/* 디폴트 대입 연산자의 문제점 */
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
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
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
	// 대입 연산자 오버로딩
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
	/*		아침 수업
			1. 대입 연산자의 오버로딩
			- 복사 생성자와 비슷
			Ex) 복사 생성자
			Point pos1(3, 5);
			Point pos2 = pos1;		<- 복사 생성자	
			(= Point pos2(pos1);) <- 컴파일러가 코드 변경
			단점 = 얕은 복사가 일어난다.
			얕은복사 : 멤버 대 멤버 복사 -> 깊은복사
	*/

	// Point pos1(5, 7);
	// Point pos2(9, 10);
	// pos2 = pos1; -> pos2.operator=(pos1);
	// 이 경우 연산자 오버로딩이 필요하다.

	//First first(111, 222);
	//First cpy;

	//Second second(333, 444);
	//Second secpy;

	//cpy = first;
	//cpy.ShowData();
	//first.ShowData();

	//secpy = second;				// 대입 연산자 오버로딩 호출
	//second.ShowData();
	//secpy.ShowData();


	return 0;
}