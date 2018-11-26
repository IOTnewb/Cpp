#include "String.h"

String::String()
{
	len = 0;
	str = NULL;
}

String::String(const char* s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String()
{
	if (str != NULL)		// �ٸ��� : NULL üũ ����� ��
		delete str;
}

String& String::operator=(const String& s)
{
	if (str != NULL)		// �ٸ��� : NULL üũ ����� ��
		delete str;

	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String String::operator+(const String& s)
{
	char *copy = new char[s.len + len - 1];					// �ٸ��� : NULL���� 2���� �ϳ� ���ߴ�
	strcpy(copy, str);
	strcat(copy, s.str);
	String temp(copy);											// �ٸ��� : ���ο� ��ü �����ؼ� ����
	delete[]copy;

	return temp;
}

String& String::operator+=(const String& s)
{
	len += (s.len - 1);
	char *copy = new char[len];
	strcpy(copy, str);
	strcat(copy, s.str);

	if (str != NULL)
		delete[]str;

	str = copy;
	return *this;

}

bool String::operator==(const String& s)
{
	return
		strcmp(str, s.str) ? false : true;
}
