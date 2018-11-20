#include <iostream>
#include <cstring>

using namespace std;

/*예외 클래스를 위한 예외처리*/
//입금 예외 처리
class DepositException	: public Account
{
private:
	int deMoney;	// 입금액
public:
	DepositException(const char *number, int money, int Dmoney)
		: Account(number, money), deMoney(Dmoney)
	{}
	void ShowExceptionReason()
	{
		cout << "예외메세지 : " << deMoney << "는 입금불가합니다." << endl;
	}
};

class WithdrawException : public Account
{
private:
	int balance;		// 잔액
public:
	WithdrawException(const char *number, int money, int cash)
		: Account(number, money), balance(cash)
	{}
	void ShowExceptionReason()
	{
		cout << "예외메세지 : 잔액 " << balance << ", 잔액부족" << endl;
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
	//입금
	void Deposit(int money)	
		throw (DepositException)	// 문법, 가독성을 위해 사용함
	{
		if (money < 0)
		{
			DepositException expn(Account);
			throw expn;
		}
		else
			balance += money;
	}
	//출금
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

	//잔액조회
	void ShowMyAccount()
	{
		cout << "잔액 : " << balance << endl << endl;
	}
};



///* 예외 다 중 위 임 */
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


/* 예외의 전달(위임) */
//void Divide(int num1, int num2)
//{
//	if (num2 == 0)
//		throw num2;
//
//	cout << "나눗셈의 몫 : " << num1 / num2 << endl;
//	cout << "나눗셈의 나머지 : " << num1 % num2 << endl;
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
//	/*		대입 연산자 오버로딩	
//			- 부모, 자식간 동일한 대입연산자 오버로딩이 있으면
//			- 자식의 대입연산자 오버로딩만 호출
//			- 자식 대입연산자 오버로딩 안에 부모 대입연산자 오버로딩 함수 호출
//	*/
//	Second &operator=(const Second &cpy)
//	{
//		First::operator=(cpy);		// 다형성 (상속관계가 is A 관계)
//		cout << "Second &operator=()" << endl;
//		num3 = cpy.num3;
//		num4 = cpy.num4;
//
//		return *this;
//	}
//};

 //디폴트 대입 연산자의 문제점 
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
//		cout << "이름 : " << name << endl;
//		cout << "나이 : " << age << endl;
//	}
//
//	Person &operator=(const Person &cpy)
//	{
//		delete[] name;										// 메모리 누수 막기
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
//	// 대입 연산자 오버로딩
//	Second &operator=(const Second &cpy)
//	{
//		cout << "Second& operator=()" << endl;
//		num3 = cpy.num3;
//		num4 = cpy.num4;
//		return *this;
//	}
//};

/*		상속 관계에서의 대입 연산자
class A					|		class B
int num1 num2		int num3 num4
class B : public A
- 부모 class 대입 연산자가 자동으로 불러지나?
*/

/*	 상속 관계에서 기본 대입 연산자 호출 */
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

	/* 배열 선언 연산자 오버로딩*/
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
//		// 배열 범위 체크
//		if (idx < 0 || idx >= arrlen)
//		{
//			cout << "배열 범위를 벗어났ㄸ" << endl;
//			exit(1);
//		}
//
//		return arr[idx];
//	}
//
//	int &operator[](int idx)
//	{
//		// 배열 범위 체크
//		if (idx < 0 || idx >= arrlen)
//		{
//			cout << "배열 범위를 벗어났ㄸ" << endl;
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

/* 예외 처리 - Exception Handling */



/* 예외 다 중 위 임 */

int main(void)
{
	
/*		아침 수업
		1. 대입 연산자의 오버로딩
		- 복사 생성자와 비슷
		Ex) 복사 생성자
		Point pos1(3, 5);
		Point pos2 = pos1;		<- 복사 생성자	
		(= Point pos2(pos1);) <- 컴파일러가 코드 변경
		단점 = 얕은 복사가 일어난다.
		얕은복사 : 멤버 대 멤버 복사 -> 깊은복사
	

		point pos1(5, 7);
		point pos2(9, 10);
		pos2 = pos1; -> pos2.operator=(pos1);
		이 경우 연산자 오버로딩이 필요하다.
	*/

	//First first(111, 222);
	//First cpy;
	//Second second(333, 444);
	//Second secpy;
	//cpy = first;
	//cpy.ShowData();
	//first.ShowData();
	//secpy = second;				// 대입 연산자 오버로딩 호출
	//second.ShowData();
	//secpy.ShowData();

	/*		디폴트 대입 연산자의 문제점 
			1. 해제할 영역 해제하려고
			2. man2 영역 해제가 안됨
			==> 연산자 오버로딩 필요
	*/
	//Person man1("dnjswn", 25);
	//Person man2("qhdwn", 30);

	//man2 = man1;
	//// man2.operator=(man1);

	//man1.ShowPerson();
	//man2.ShowPerson();

	/*	 상속 관계에서 기본 대입 연산자 호출 */
	/*Second second(111, 222, 333, 444);
	Second secpy;

	secpy = second;

	secpy.ShowData();
	second.ShowData();
	*/

	/* 배열 인덱스 연산자 오버로딩 - 관리가 되는게 재밌어야 */

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

	/* 예외 처리 - Exception Handling in C */
	//int num1, num2;
	//cout << "두 개의 숫자 입력 : ";
	//cin >> num1 >> num2;		// 예 외 발 생
	//
	//if (num2 == 0)					// 예 외 췤
	//{												// 예 외 처 리
	//	cout << "제수는 0이 될 수 없습니다." << endl;
	//	cout << "프로그램 리스타또" << endl;
	//}
	//else
	//{
	//	cout << "나눗셈의 몫 : " << num1 / num2 << endl;
	//	cout << "나눗셈의 나머지 : " << num1 % num2 << endl;

	//}

	/* 예외 처리 - Exception Handling in C++ */
	//try 블록 - 예 외 발 견
	//catch 블록 - 예 외 처 리
	//throw 블록 - 예 외 처 리 위 임
	//int num1, num2;
	//cout << "두 개의 숫자 입력 : ";
	//cin >> num1 >> num2;		// 예 외 발 생

	/* 예외의 전달(위임) */
	
	//try
	//{
	//	Divide(num1, num2);
	//	//if (num2 == 0)					// 예 외 췤
	//	//	throw num2;
	//}
	//catch (int expn)			// try에서 throw 된 데이터 타입으로 받아야된다.
	//{
	//	cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
	//	cout << "프로그램 리스타또" << endl;
	//}

	/* 예외 다 중 위 임 */
// 예외가 처리되지 않아서, Exception 이 main 함수까지 도달했는데, main함ㅅ에서 조차 예외를 처리하지 않으면
//	 terminate 호출되며너

//try
//{
//	SimpleFuncOne();
//}
//catch(int expn)
//{
//	cout << "[예외코드] << " << expn << endl;
//
//
//}

/*예외 클래스를 위한 예외처리*/
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