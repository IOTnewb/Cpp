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
	if (str != NULL)		// 다른점 : NULL 체크 해줘야 함
		delete str;
}

String& String::operator=(const String& s)
{
	if (str != NULL)		// 다른점 : NULL 체크 해줘야 함
		delete str;

	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String String::operator+(const String& s)
{
	char *copy = new char[s.len + len - 1];					// 다른점 : NULL문자 2개라서 하나 빼야댐
	strcpy(copy, str);
	strcat(copy, s.str);
	String temp(copy);											// 다른점 : 새로운 객체 생성해서 리턴
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
