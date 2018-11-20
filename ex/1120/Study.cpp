#include <iostream>
#include <cstring>

using namespace std;

/*¿¹¿Ü Å¬·¡½º¸¦ À§ÇÑ ¿¹¿ÜÃ³¸®*/
//ÀÔ±Ý ¿¹¿Ü Ã³¸®
class DepositException	: public Account
{
private:
	int deMoney;	// ÀÔ±Ý¾×
public:
	DepositException(const char *number, int money, int Dmoney)
		: Account(number, money), deMoney(Dmoney)
	{}
	void ShowExceptionReason()
	{
		cout << "¿¹¿Ü¸Þ¼¼Áö : " << deMoney << "´Â ÀÔ±ÝºÒ°¡ÇÕ´Ï´Ù." << endl;
	}
};

class WithdrawException : public Account
{
private:
	int balance;		// ÀÜ¾×
public:
	WithdrawException(const char *number, int money, int cash)
		: Account(number, money), balance(cash)
	{}
	void ShowExceptionReason()
	{
		cout << "¿¹¿Ü¸Þ¼¼Áö : ÀÜ¾× " << balance << ", ÀÜ¾×ºÎÁ·" << endl;
	}
};

class Account
{
private:
	char accNum[50];
	int balance;
public:
	Account(const char *number, int money)
		: balance(money)
	{
		strcpy(accNum, number);
	}
	//ÀÔ±Ý
	void Deposit(int money)	
		throw (DepositException)	// ¹®¹ý, °¡µ¶¼ºÀ» À§ÇØ »ç¿ëÇÔ
	{
		if (money < 0)
		{
			DepositException expn(Account);
			throw expn;
		}
		else
			balance += money;
	}
	//Ãâ±Ý
	void Withdraw(int money)
		throw (WithdrawException)
	{
		if (balance < money)
		{
			WithdrawException expn(Account);
			throw expn;
		}
		else
			balance -= money;
	}
	virtual void ShowExceptionReason()
	{

	}

	//ÀÜ¾×Á¶È¸
	void ShowMyAccount()
	{
		cout << "ÀÜ¾× : " << balance << endl << endl;
	}
};



///* ¿¹¿Ü ´Ù Áß À§ ÀÓ */
//void SimpleFuncOne(void);
//void SimpleFuncTwo(void);
//void SimpleFuncThree(void);
//
//void SimpleFuncOne(void)
//{
//	cout << "SimpleFuncOne(void)" << endl;
//	SimpleFuncTwo();
//}
//
//void SimpleFuncTwo(void)
//{
//	cout << "SimpleFuncTwo(void)" << endl;
//	SimpleFuncThree();
//}
//
//void SimpleFuncThree(void)
//{
//	cout << "SimpleFuncThree(void)" << endl;
//	throw - 1;
//}


/* ¿¹¿ÜÀÇ Àü´Þ(À§ÀÓ) */
//void Divide(int num1, int num2)
//{
//	if (num2 == 0)
//		throw num2;
//
//	cout << "³ª´°¼ÀÀÇ ¸ò : " << num1 / num2 << endl;
//	cout << "³ª´°¼ÀÀÇ ³ª¸ÓÁö : " << num1 % num2 << endl;
//}



//	class Second	: public First
//{
//private:
//	int num3;
//	int num4;
//public:
//	Second(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0)
//		: First(n1, n2), num3(n3), num4(n4)
//	{}
//	void ShowData()
//	{
//		First::ShowData();
//		cout << "[" << num3 << ", " << num4 << "]" << endl;
//	}
//	/*		´ëÀÔ ¿¬»êÀÚ ¿À¹ö·Îµù	
//			- ºÎ¸ð, ÀÚ½Ä°£ µ¿ÀÏÇÑ ´ëÀÔ¿¬»êÀÚ ¿À¹ö·ÎµùÀÌ ÀÖÀ¸¸é
//			- ÀÚ½ÄÀÇ ´ëÀÔ¿¬»êÀÚ ¿À¹ö·Îµù¸¸ È£Ãâ
//			- ÀÚ½Ä ´ëÀÔ¿¬»êÀÚ ¿À¹ö·Îµù ¾È¿¡ ºÎ¸ð ´ëÀÔ¿¬»êÀÚ ¿À¹ö·Îµù ÇÔ¼ö È£Ãâ
//	*/
//	Second &operator=(const Second &cpy)
//	{
//		First::operator=(cpy);		// ´ÙÇü¼º (»ó¼Ó°ü°è°¡ is A °ü°è)
//		cout << "Second &operator=()" << endl;
//		num3 = cpy.num3;
//		num4 = cpy.num4;
//
//		return *this;
//	}
//};

 //µðÆúÆ® ´ëÀÔ ¿¬»êÀÚÀÇ ¹®Á¦Á¡ 
//class Person
//{
//private:
//	char *name;
//	int age;
//public:
//	Person(const char *myName, int myAge)
//		: age(myAge)
//	{
//		int len = strlen(myName) + 1;
//		name = new char[len];
//		strcpy(name, myName);
//	}
//
//	void ShowPerson()
//	{
//		cout << "ÀÌ¸§ : " << name << endl;
//		cout << "³ªÀÌ : " << age << endl;
//	}
//
//	Person &operator=(const Person &cpy)
//	{
//		delete[] name;										// ¸Þ¸ð¸® ´©¼ö ¸·±â
//		int len = strlen(cpy.name) + 1;
//		name = new char[len];
//		strcpy(name, cpy.name);
//		age = cpy.age;
//		return *this;
//	}
//
//	~Person()
//	{
//		delete[] name;
//		cout << "called Destruct" << endl;
//	}
//};


/*class First
{
private:
	int num1;
	int num2;
public:
	First(int n1=0, int n2=0)
		: num1(n1), num2(n2)
	{}
	void ShowData()
	{
		cout << "[" << num1 << ", " << num2 << "]" << endl;
	}
};*/

//class Second
//{
//private:
//	int num3;
//	int num4;
//public:
//	Second(int n3=0, int n4=0)
//		: num3(n3), num4(n4)
//	{}
//	void ShowData()
//	{
//		cout << "[" << num3 << ", " << num4 << "]" << endl;
//	}
//	// ´ëÀÔ ¿¬»êÀÚ ¿À¹ö·Îµù
//	Second &operator=(const Second &cpy)
//	{
//		cout << "Second& operator=()" << endl;
//		num3 = cpy.num3;
//		num4 = cpy.num4;
//		return *this;
//	}
//};

/*		»ó¼Ó °ü°è¿¡¼­ÀÇ ´ëÀÔ ¿¬»êÀÚ
class A					|		class B
int num1 num2		int num3 num4
class B : public A
- ºÎ¸ð class ´ëÀÔ ¿¬»êÀÚ°¡ ÀÚµ¿À¸·Î ºÒ·¯Áö³ª?
*/

/*	 »ó¼Ó °ü°è¿¡¼­ ±âº» ´ëÀÔ ¿¬»êÀÚ È£Ãâ */
/*class First
{
private:
int num1;
int num2;
public:
First(int n1=0, int n2=0)
: num1(n1), num2(n2)
{}
void ShowData()
{
cout << "[" << num1 << ", " << num2 << "]" << endl;
}

First &operator=(const First &cpy)
{
cout << "First &operator=()" << endl;
num1 = cpy.num1;
num2 = cpy.num2;
return *this;
}
};*/

	/* ¹è¿­ ¼±¾ð ¿¬»êÀÚ ¿À¹ö·Îµù*/
//class BoundCheckIntArray
//{
//private:
//	int *arr;
//	int arrlen;
//public:
//	BoundCheckIntArray(int len)
//		: arrlen(len)
//	{
//		arr = new int[len];
//	}
//
//	int Getlen() const
//	{
//		return arrlen;
//	}
//
//	int &operator[](int idx) const
//	{
//		// ¹è¿­ ¹üÀ§ Ã¼Å©
//		if (idx < 0 || idx >= arrlen)
//		{
//			cout << "¹è¿­ ¹üÀ§¸¦ ¹þ¾î³µ¤¨" << endl;
//			exit(1);
//		}
//
//		return arr[idx];
//	}
//
//	int &operator[](int idx)
//	{
//		// ¹è¿­ ¹üÀ§ Ã¼Å©
//		if (idx < 0 || idx >= arrlen)
//		{
//			cout << "¹è¿­ ¹üÀ§¸¦ ¹þ¾î³µ¤¨" << endl;
//			exit(1);
//		}
//
//		return arr[idx];
//	}
//
//	~BoundCheckIntArray()
//	{
//		delete[]arr;
//	}
//};
//
//void ShowAllData(const BoundCheckIntArray &cpy)//*******
//{
//	for (int i = 0; i < cpy.Getlen(); i++)
//	{
//		cout << cpy[i] << endl;
//	}
//}

/* ¿¹¿Ü Ã³¸® - Exception Handling */



/* ¿¹¿Ü ´Ù Áß À§ ÀÓ */

int main(void)
{
	
/*		¾ÆÄ§ ¼ö¾÷
		1. ´ëÀÔ ¿¬»êÀÚÀÇ ¿À¹ö·Îµù
		- º¹»ç »ý¼ºÀÚ¿Í ºñ½Á
		Ex) º¹»ç »ý¼ºÀÚ
		Point pos1(3, 5);
		Point pos2 = pos1;		<- º¹»ç »ý¼ºÀÚ	
		(= Point pos2(pos1);) <- ÄÄÆÄÀÏ·¯°¡ ÄÚµå º¯°æ
		´ÜÁ¡ = ¾èÀº º¹»ç°¡ ÀÏ¾î³­´Ù.
		¾èÀºº¹»ç : ¸â¹ö ´ë ¸â¹ö º¹»ç -> ±íÀºº¹»ç
	

		point pos1(5, 7);
		point pos2(9, 10);
		pos2 = pos1; -> pos2.operator=(pos1);
		ÀÌ °æ¿ì ¿¬»êÀÚ ¿À¹ö·ÎµùÀÌ ÇÊ¿äÇÏ´Ù.
	*/

	//First first(111, 222);
	//First cpy;
	//Second second(333, 444);
	//Second secpy;
	//cpy = first;
	//cpy.ShowData();
	//first.ShowData();
	//secpy = second;				// ´ëÀÔ ¿¬»êÀÚ ¿À¹ö·Îµù È£Ãâ
	//second.ShowData();
	//secpy.ShowData();

	/*		µðÆúÆ® ´ëÀÔ ¿¬»êÀÚÀÇ ¹®Á¦Á¡ 
			1. ÇØÁ¦ÇÒ ¿µ¿ª ÇØÁ¦ÇÏ·Á°í
			2. man2 ¿µ¿ª ÇØÁ¦°¡ ¾ÈµÊ
			==> ¿¬»êÀÚ ¿À¹ö·Îµù ÇÊ¿ä
	*/
	//Person man1("dnjswn", 25);
	//Person man2("qhdwn", 30);

	//man2 = man1;
	//// man2.operator=(man1);

	//man1.ShowPerson();
	//man2.ShowPerson();

	/*	 »ó¼Ó °ü°è¿¡¼­ ±âº» ´ëÀÔ ¿¬»êÀÚ È£Ãâ */
	/*Second second(111, 222, 333, 444);
	Second secpy;

	secpy = second;

	secpy.ShowData();
	second.ShowData();
	*/

	/* ¹è¿­ ÀÎµ¦½º ¿¬»êÀÚ ¿À¹ö·Îµù - °ü¸®°¡ µÇ´Â°Ô Àç¹Õ¾î¾ß */

	//arrobject[2];

	//complier view
	//arrobject.operator[](2)

	//programmer view
	/*BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i + 1) * 11;
	}*/
	
	/*for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << endl;
	}*/
	
	//ShowAllData(arr);

	/* ¿¹¿Ü Ã³¸® - Exception Handling in C */
	//int num1, num2;
	//cout << "µÎ °³ÀÇ ¼ýÀÚ ÀÔ·Â : ";
	//cin >> num1 >> num2;		// ¿¹ ¿Ü ¹ß »ý
	//
	//if (num2 == 0)					// ¿¹ ¿Ü ®c
	//{												// ¿¹ ¿Ü Ã³ ¸®
	//	cout << "Á¦¼ö´Â 0ÀÌ µÉ ¼ö ¾ø½À´Ï´Ù." << endl;
	//	cout << "ÇÁ·Î±×·¥ ¸®½ºÅ¸¶Ç" << endl;
	//}
	//else
	//{
	//	cout << "³ª´°¼ÀÀÇ ¸ò : " << num1 / num2 << endl;
	//	cout << "³ª´°¼ÀÀÇ ³ª¸ÓÁö : " << num1 % num2 << endl;

	//}

	/* ¿¹¿Ü Ã³¸® - Exception Handling in C++ */
	//try ºí·Ï - ¿¹ ¿Ü ¹ß °ß
	//catch ºí·Ï - ¿¹ ¿Ü Ã³ ¸®
	//throw ºí·Ï - ¿¹ ¿Ü Ã³ ¸® À§ ÀÓ
	//int num1, num2;
	//cout << "µÎ °³ÀÇ ¼ýÀÚ ÀÔ·Â : ";
	//cin >> num1 >> num2;		// ¿¹ ¿Ü ¹ß »ý

	/* ¿¹¿ÜÀÇ Àü´Þ(À§ÀÓ) */
	
	//try
	//{
	//	Divide(num1, num2);
	//	//if (num2 == 0)					// ¿¹ ¿Ü ®c
	//	//	throw num2;
	//}
	//catch (int expn)			// try¿¡¼­ throw µÈ µ¥ÀÌÅÍ Å¸ÀÔÀ¸·Î ¹Þ¾Æ¾ßµÈ´Ù.
	//{
	//	cout << "Á¦¼ö´Â " << expn << "ÀÌ µÉ ¼ö ¾ø½À´Ï´Ù." << endl;
	//	cout << "ÇÁ·Î±×·¥ ¸®½ºÅ¸¶Ç" << endl;
	//}

	/* ¿¹¿Ü ´Ù Áß À§ ÀÓ */
// ¿¹¿Ü°¡ Ã³¸®µÇÁö ¾Ê¾Æ¼­, Exception ÀÌ main ÇÔ¼ö±îÁö µµ´ÞÇß´Âµ¥, mainÇÔ¤µ¿¡¼­ Á¶Â÷ ¿¹¿Ü¸¦ Ã³¸®ÇÏÁö ¾ÊÀ¸¸é
//	 terminate È£ÃâµÇ¸ç³Ê

//try
//{
//	SimpleFuncOne();
//}
//catch(int expn)
//{
//	cout << "[¿¹¿ÜÄÚµå] << " << expn << endl;
//
//
//}

/*¿¹¿Ü Å¬·¡½º¸¦ À§ÇÑ ¿¹¿ÜÃ³¸®*/
Account client1("123", 5000);

try
{
	client1.Deposit(2000);
	client1.Deposit(-300);
}
catch (Account &expn)
{
	expn.ShowExceptionReason();
}

try
{
	client1.Withdraw(1000);
	client1.Withdraw(10000);
}
catch (Account &expn)
{
	expn.ShowExceptionReason();
}

client1.ShowMyAccount();


	return 0;
}