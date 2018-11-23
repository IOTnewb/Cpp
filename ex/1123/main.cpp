#include <iostream>
#include <cstring>

using namespace std;

/* 5. Ŭ���� ���ø� */
//- �迭�� ���� Ŭ������ ���ø�ȭ
//- STL���� ���־�




/* 4. ���ø��� Ư��ȭ */
/*
template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template <>		// ���ø� Ư��ȭ
char* Max(char* a, char* b)
{
	cout << "char* Max" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template <>		// ���ø� Ư��ȭ
const char* Max(const char* a, const char* b)
{
	cout << "const char* Max" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main(void)
{
	char str1[] = "Simple";
	char str2[] = "Best";


	// ������ ��Ȯ�� ���,
	cout << Max(11, 15) << endl;
	cout << Max('t', 'q') << endl;
	cout << Max(3.5, 10.1) << endl;

	// ������ �ָ��� ���. �̿� �°� Ư��ȭ ������� �Ѵ�.
	cout << Max(str1,str2) << endl;						// char*
	cout << Max("Simple", "Best") << endl;			// const char*


	return 0;
}
*/


/* 3. ���ø� (Template) */
/*
	- �� : ���� -> ������.
	- �Լ� ���ø�, Ŭ���� ���ø�
	- �پ��� �ڷ����� �Լ�, Ŭ������ ����� ����
	
	int Add(int num1, int num2)
	{
		return num1 + num2;
	}
	
	��� : �� ��
	��� �ڷ��� : int �� ������

	template <typename T>		���ø� ����
	template <class T>				typename, class �� �ǹ̰� ����

	T Add(T num1, T num2)
	{
		return num1 + num2;
	}


template <class T1, class T2>
void ShowData(double num)
{
	cout << (T1)num << ", " << (T2)num << endl;
}

template <typename T>

T Add(T num1, T num2)
{
	cout << "T Add" << endl;
	return num1 + num2;
}

int Add(int num1, int num2)
{
	cout << "Add" << endl;
	return num1 + num2;
}

int main(void)
{
	//<int> : T�� int�� �ؼ� ������� �Լ��� ȣ��
	//					=> template �Լ��� ȣ��
	cout << Add<int>(15, 20) << endl;
	cout << Add(15, 20) << endl;
				//int Add(int num1, int num2)
				//{
				//	return num1 + num2;
				//}
	
	cout << Add<double>(2.8, 7.4) << endl;

	ShowData<char, int>(65);

	return 0;
}
*/


/*2. ����� ���� String class */
/*
class String
{
private:
	int len;
	char* str;
public:
	String();									// �Ű������� ���� ������
	String(const char* s);			// �Ű������� �ִ� ������
	String(const String& s);	// ���� ������
	~String();
	String& operator=(const String& s);
	String operator+(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	friend ostream& operator<<(ostream& os, const String s);
	friend istream& operator>>(istream& is, String& s);
};
/* �� ��
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
	delete str;													// ���� ���� ���� �ʿ䰡 ����
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
/* �� �� �� 
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
	if(str != NULL)		// �ٸ��� : NULL üũ ����� ��
		delete str;
}

String& String::operator=(const String& s)
{
	if(str != NULL)		// �ٸ��� : NULL üũ ����� ��
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

/*
	������� ���ؼ� iostream ������� ���
	�Է� : istream class
	��� : ostream class


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
	// C++ ǥ�� string class - �������̰� ������ ���ϴ�.

	String str1 = "I hate this.";
	String str2 = "Me Too.";
	String str3 = str1 + str2;		// ������ �����ε��� �Ǿ��ִ�.
									// str1.operator+(str2);

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;							// ������ �����ε��� �Ǿ��ִ�.

	if (str1 == str3)
		cout << "���� ���ڿ�" << endl;
	else
		cout << "�ٸ� ���ڿ�" << endl;

	String str4;
	cout << "���ڿ� �Է� : ";
	cin >> str4;
	cout << "�Էµ� ���ڿ� : " << str4 << endl;

	return 0;
}
*/


/* 1. C++ ǥ�� string class */
/*
#include <string>
int main(void)
{
	// C++ ǥ�� string class - �������̰� ������ ���ϴ�.

	string str1 = "I hate this.";
	string str2 = "Me Too.";
	string str3 = str1 + str2;		// ������ �����ε��� �Ǿ��ִ�.
														// str1.operator+(str2);

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;							// ������ �����ε��� �Ǿ��ִ�.

	if (str1 == str3)
		cout << "���� ���ڿ�" << endl;
	else
		cout << "�ٸ� ���ڿ�" << endl;

	string str4;
	cout << "���ڿ� �Է� : ";
	cin >> str4;
	cout << "�Էµ� ���ڿ� : " << str4 << endl;

	return 0;
}
*/