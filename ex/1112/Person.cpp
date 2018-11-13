#include "Person.h"
/*
생성자 - 매개변수o , 매개변수x (오버로딩 가능)
소멸자 - class 소멸시 or new로 생성된 동적 메모리 제거

*/
Person::Person()
{
	name = NULL;
	age = 0;
	cout << "Person() call" << endl;
}
// 매개 변수가 있는 constructor
Person::Person(const char *myName, int myAge)
{
	int len = strlen(myName) + 1;
	name = new char[len];
	strcpy(name, myName);
	age = myAge;
}
//멤버 변수 수정 함수
void Person::SetPersonInfo(char *myName, int myAge)
{
	name = myName;
	age = myAge;
}


//출 력 함 수
void Person::ShowPersonInfo() const
{
	cout << "이 름 : " << name << endl;
	cout << "나 이 : " << age << endl;
}
// destructor
Person::~Person()
{
	delete[]name;
	cout << "파 괴 한 다" << endl;
}