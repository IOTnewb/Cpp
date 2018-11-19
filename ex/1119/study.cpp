#include <iostream>

using namespace std;

class SoSimple
{
private:
	int num1;
	mutable int num2;

public:
	SoSimple(int n, int m) : num1(n)
	{}
	void ShowSimpleData() const
	{
		cout << num1 << ", " << num2 << endl;
	}

	void CopyToNum2() const
	{
		num2 = num1;
	}
};


/* static 함수(클래스 함수)
class SoSimple
{
private:
	int num1;
	static int num2;
public:
	SoSimple(int n) : num1(n)
	{}
	static void Adder(int n)	//class func
	{
//		num1+=n;
		num2+=n;
	}
};

int SoSimple::num2 = 0;
*/
/* const static 변수 
class CountryArea
{
public:
	const static int RUSSIA = 8976;				//선언 동시 초기화?
	const static int SOUTH_KOREAD = 7877;

};


/* static 변수 (클래스 변수) 

//int simObjCnt = 0;
//int comObjCnt = 0;

class SoSimple
{
private:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};

class SoComplx
{
private:
	static int comObjCnt;
public:
	SoComplx()
	{
		comObjCnt++;
		cout << comObjCnt << "번째 SoComplx 객체" << endl;
	}
};

int SoSimple::simObjCnt = 0;		// 밖에서 1번만 초기화
int SoComplx::comObjCnt = 0;	


/* 정 적 지 역 변 수 
void Counter()		// C 언 어 에 서
{
	static int cnt;
	cnt++;
	cout << "Current cnt : " << cnt << endl;
}
*/



/* friend 선언 - 함수인 경우
class Point;

class PointOp
{
private:
	int opCnt;
public:
	PointOp() : opCnt(0)
	{}
	Point PointAdd(const Point &, const Point &);
	Point PointSub(const Point &, const Point &);

	~PointOp()
	{
		cout << "Operation Times : " << opCnt << endl;
	}
};
/*
class Point
{
private:
	int x;
	int y;
public:
	Point(const int &xpos, const int &ypos) : x(xpos), y(ypos)
	{}
	friend Point PointOp::PointAdd(const Point &, const Point &); // friend 함수
	friend Point PointOp::PointSub(const Point &, const Point &); // friend 함수
	friend void ShowPointPos(const Point &); // friend 전역함수 ***
};

Point PointOp::PointAdd(const Point &pt1, const Point &pt2)
{
	opCnt++;
	return Point(pt1.x + pt2.x, pt1.y + pt2.y);
}

Point PointOp::PointSub(const Point &pt1, const Point &pt2)
{
	opCnt++;
	return Point(pt1.x - pt2.x, pt1.y - pt2.y);
}

void ShowPointPos(const Point &pt) // 왜 얘는 앞에 Point:: 안붙이는데 되지 - 전역함수
{
	cout << "x : " << pt.x << ", ";
	cout << "y : " << pt.y << endl;
}
*/

/* friend 선언 - class 경우 
class Girl;

class Boy
{
private:
	int height;
	friend class Girl;
public:
	Boy(int len) : height(len)
	{}

	void ShowYourFriendInfo(Girl &fnd);
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char *num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy &fnd);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl &fnd)
{
	cout << "Her phone number : " << fnd.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy &fnd)
{
	cout << "His Height : " << fnd.height << endl;
}

*/

/* const 함수 오버로딩
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{}

	SoSimple &AddNum(int n)
	{
		num += n;
		return *this;
	}

	void SimpleFunc()
	{
		cout << "SimpleFunc : " << num << endl;
	}

	void SimpleFunc() const
	{
		cout << "Const SimpleFunc : " << num << endl;
	}

};
*/
/* 
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{}

	SoSimple &AddNum(int n)
	{
		num += n;
		return *this;
	}

	void ShowData() const
	{
		cout << "Num : " << num << endl;
	}
};
*/
int main(void)
{
	/*
	const 함수 오버로딩 
	- 함수 오버로딩 조건에서 const 포함

	SoSimple obj1(7);
	const SoSimple obj2(10);

	obj1.SimpleFunc();
	obj2.SimpleFunc();
	*/
	/* const 객체 
	SoSimple generalobj(10);
	generalobj.AddNum(10);
	generalobj.ShowData();

	const SoSimple constobj(100);
	constobj.ShowData();

	// constobj.AddNum(200);	// ****** const 객체는 const 함수만 사용 가능하다.
	*/
	
	/* 
	friend 선언 - class의 경우
	- friend 선언은 객체지향의 캡슐화에서 정보은닉을 위배하는 문법임.
	- 따라서, friend 선언은 필요한 상황에서만 사용해야함.
	- 연산자 오버로딩에서 전역 함수를 선언시 사용
	
	Boy boy(180);
	Girl girl("010-1234-5678");

	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	*/

	/*
	friend 선언 - 함수의 경우


	Point pos1(1, 2);
	Point pos2(3, 4);

	PointOp op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos1, pos2));
	*/

	/* C언어에서의 static 변수 (클래스 변수) 
	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	*/

	/* static 변수 (클래스 변수) 
	SoSimple sim1;
	SoSimple sim2;

	SoComplx com1;
	SoComplx com2;
	SoComplx com3;
	*/


	/* const static 변수 (클래스 변수) 
	cout << "러시아 면적 : " << CountryArea::RUSSIA << endl;
	cout << "한국 면적 : " << CountryArea::SOUTH_KOREAD << endl;
	*/

	/* static 함수 (class 함수)
	- 선언된 클래스의 모든 객체가 공유
	- public으로 선언이 되면, 클래스의 이름을 이용해서 호출이 가능
	- 객체의 멤버로 존재하는 것이 아님.
	*/

	/* mutable 키워드 (cf. explicit) (explicit -> 자동 형변환을 하지 않게 해주는)
	- const 함수 내에서 멤버변수 값의 변경을 예외적으로 허용

	*/
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();
	return 0;
}