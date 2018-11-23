#include <iostream>
#include <cstring>

using namespace std;
/* 3. 템플릿 (Template) */
/*
	- 뜻 : 형판 -> 모형자.
	- 함수 템플릿, 클래스 템플릿
	- 다양한 자료형의 함수, 클래스를 만드는 도구
	
	int Add(int num1, int num2)
	{
		return num1 + num2;
	}
	
	기능 : 덧 셈
	대상 자료형 : int 형 데이터

	template <typename T>		템플릿 정의
	template <class T>				typename, class 는 의미가 없음

	T Add(T num1, T num2)
	{
		return num1 + num2;
	}

*/
template <typename T>

T Add(T num1, T num2)
{
	return num1 + num2;
}

int main(void)
{

	return 0;
}

/*2. 사용자 정의 String class */
/*
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
/* 실 습
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
	delete str;
}

String& String::operator=(const String& s)
{
	delete str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+(const String& s)
{
	len += s.len;
	char *copy = new char[len];
	strcpy(copy, str);
	delete str;													// 기존 값을 지울 필요가 없음
	str = copy;
	delete copy;
	strcat(str, s.str);
	return *this;
}

String& String::operator+=(const String& s)
{
	len += s.len;
	char *copy = new char[len];
	strcpy(copy, str);
	delete str;
	str = copy;
	delete copy;
	strcat(str, s.str);
	return *this;
	
}

bool String::operator==(const String& s)
{
	int count = 0;

	if (len == s.len)
	{
		for (int i = 0; i < len; i++)
		{
			if (str[i] == s.str[i])
				count++;
			else;
		}
	}
	else
		return false;

	if (count == len)
		return true;
}
*/
/* 답 안 지 
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
	if(str != NULL)		// 다른점 : NULL 체크 해줘야 함
		delete str;
}

String& String::operator=(const String& s)
{
	if(str != NULL)		// 다른점 : NULL 체크 해줘야 함
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

/*
	입출력을 위해서 iostream 헤더파일 사용
	입력 : istream class
	출력 : ostream class


ostream& operator<<(ostream& os, const String s)
{
	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s)
{
	char str[100];
	is >> str;
	s = String(str);

	return is;
}



int main(void)
{
	// C++ 표준 string class - 직관적이고 굉장히 편하다.

	String str1 = "I hate this.";
	String str2 = "Me Too.";
	String str3 = str1 + str2;		// 연산자 오버로딩이 되어있다.
									// str1.operator+(str2);

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;							// 연산자 오버로딩이 되어있다.

	if (str1 == str3)
		cout << "동일 문자열" << endl;
	else
		cout << "다른 문자열" << endl;

	String str4;
	cout << "문자열 입력 : ";
	cin >> str4;
	cout << "입력된 문자열 : " << str4 << endl;

	return 0;
}
*/


/* 1. C++ 표준 string class */
/*
#include <string>
int main(void)
{
	// C++ 표준 string class - 직관적이고 굉장히 편하다.

	string str1 = "I hate this.";
	string str2 = "Me Too.";
	string str3 = str1 + str2;		// 연산자 오버로딩이 되어있다.
														// str1.operator+(str2);

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;							// 연산자 오버로딩이 되어있다.

	if (str1 == str3)
		cout << "동일 문자열" << endl;
	else
		cout << "다른 문자열" << endl;

	string str4;
	cout << "문자열 입력 : ";
	cin >> str4;
	cout << "입력된 문자열 : " << str4 << endl;

	return 0;
}
*/