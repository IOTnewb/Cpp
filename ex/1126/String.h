#pragma once
#include "bankmain.h"

class String
{
private:
	int len;
	char* str;
public:
	String();									// 매개변수가 없는 생성자
	String(const char* s);			// 매개변수가 있는 생성자
	String(const String& s);	// 복사 생성자
	~String();
	String& operator=(const String& s);
	String operator+(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	friend ostream& operator<<(ostream& os, const String s);
	friend istream& operator>>(istream& is, String& s);
};