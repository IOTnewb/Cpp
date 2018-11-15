#include <iostream>

using namespace std;

/*
얕 은 복 사 (Shallow Copy), 깊 은 복 사 (Deep Copy) 
- 얕은 복사의 문제가 발생하는 타이밍
1. " = "

2. call by value 방식의 함수 호출과정에서
	객체를 인자로 전달할 때

3. 객체를 반환할 때 참조형으로 반환하지 않는 경우

*/
class Person
{
private:
	char *name;
	int age;

public:
	Person(const char *myName, int myAge)
		:age(myAge)
	{
		int len = strlen(myName) + 1;
		name = new char[len];
		strcpy(name, myName);
	}

	Person(const Person &copy)
		:age(copy.age)
	{
		/* 깊 은 복 사 */
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);

	}
	//멤버 변수 수정 함수
	void SetPersonInfo(char *myName, int myAge)
	{
		name = myName;
		age = myAge;
	}

	//출 력 함 수
	void ShowPersonInfo() const
	{
		cout << "이 름 : " << name << endl;
		cout << "나 이 : " << age << endl;
	}
	// destructor	/* 소 멸 자 */
	~Person()
	{
		delete[]name;
		cout << "파 괴 한 다" << endl;
	}
};


/*
class SoSimple
{
private:
	int num;
	int num1;
public:
	SoSimple(int n, int n1)
		:num(n), num1(n1)
	{}
	/* 복 사 생 성 자 (Copy Constructor)
	explicit SoSimple(SoSimple &copy)
		: num(copy.num), num1(copy.num1)
	{
		cout << "Copy Constructor Called" << endl;
	}

	void ShowSimpleData()
	{
		cout << num << endl;
		cout << num1 << endl;
	}
};
*/
int main(void)
{
	/* 얕 은 복 사 (Shallow Copy) - 캐릭터형 배열 생성*/
	Person man1("Lee", 25);
	Person man2 = man1; // 같은 메모리 바라봄
	
	man1.ShowPersonInfo();
	/* 같은 메모리 바라보니 먼저 해제시키면 뒤에서 붕 떠버림 */

	/* 복 사 생 성 자 
	SoSimple sim1(20, 50);
	//SoSimple sim2 = sim1;
	SoSimple sim2(sim1);
	sim2.ShowSimpleData();
	*/
	return 0;
}

