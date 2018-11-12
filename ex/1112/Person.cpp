#include "Person.h"

Person::Person()
{
	name = NULL;
	age = 0;
	cout << "Person() call" << endl;
}
// �Ű� ������ �ִ� constructor
Person::Person(const char *myName, int myAge)
{
	int len = strlen(myName) + 1;
	name = new char[len];
	strcpy(name, myName);
	age = myAge;
}
//��� ���� ���� �Լ�
void Person::SetPersonInfo(char *myName, int myAge)
{
	name = myName;
	age = myAge;
}


//�� �� �� ��
void Person::ShowPersonInfo() const
{
	cout << "�� �� : " << name << endl;
	cout << "�� �� : " << age << endl;
}
// destructor
Person::~Person()
{
	delete[]name;
	cout << "�� �� �� ��" << endl;
}