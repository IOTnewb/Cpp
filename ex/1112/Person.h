#pragma once
#include "study.h"

/*
생성자도 함수니까 오버로딩 가능
객 체 배 열 - 객체 자체가 저장되는 배열
객 체 포 인 터 배 열 - 객체를 가리키는 포인터가 저장되는 배열
객체포인터배열이 메모리 효율적 사용에 더 좋다
*/


class Person
{
private:
	char *name;
	int age;

public:
	// 매개 변수가 없는 constructor
	Person();
	// 매개 변수가 있는 constructor
	Person(const char *myName, int myAge);
	//멤버 변수 수정 함수
	void SetPersonInfo(char *myName, int myAge);


	//출 력 함 수
	void ShowPersonInfo() const;
	// destructor	/* 소 멸 자 */
	~Person();
};