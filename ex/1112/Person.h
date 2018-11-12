#pragma once
#include "study.h"

/*
�����ڵ� �Լ��ϱ� �����ε� ����
�� ü �� �� - ��ü ��ü�� ����Ǵ� �迭
�� ü �� �� �� �� �� - ��ü�� ����Ű�� �����Ͱ� ����Ǵ� �迭
��ü�����͹迭�� �޸� ȿ���� ��뿡 �� ����
*/


class Person
{
private:
	char *name;
	int age;

public:
	// �Ű� ������ ���� constructor
	Person();
	// �Ű� ������ �ִ� constructor
	Person(const char *myName, int myAge);
	//��� ���� ���� �Լ�
	void SetPersonInfo(char *myName, int myAge);


	//�� �� �� ��
	void ShowPersonInfo() const;
	// destructor	/* �� �� �� */
	~Person();
};