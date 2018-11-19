#include <iostream>

using namespace std;

class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(int x = 0, int y = 0)
		: xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

	Point &operator++()
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}

	// ++���� ������ �����ε�
	Point operator++(int)
	{
		/* �� */
		const Point retobj(xpos, ypos);	// ���� �� ����� ������ �༮ ����
		xpos += 1;								// ���� ���� ++
		ypos += 1;								// ���� ���� ++
		return retobj;								// ���� �� ��� ��ȯ ( �׷��� ���� ����ó�� �Ǵϱ� )
	}

	// �ڷ����� �ٸ� ��� ������ �����ε�
	Point operator*(int times) // �ٸ� �ڷ����� Ÿ���� �Ű������� ���ش�?
	{
		Point pos(xpos*times, ypos*times);
		return pos;
	}


	// --���� ������ �����ε�
	friend Point &operator--(Point &ref);
	friend Point operator--(Point &ref, int);

};

// -- ���� ������ �����ε�
// �� �� �� ��
Point &operator--(Point &ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

// -- ���� ���� �����ε�
Point operator--(Point &ref, int)
{
	const Point post(ref);	// ���� �� ����� ������ �༮ ����
	ref.xpos -= 1;			// ���� ���� --
	ref.ypos -= 1;			// ���� ���� --
	return post;				// ���� �� ��� ��ȯ ( �׷��� ���� ����ó�� �Ǵϱ� )
}

/*
class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(int x = 0, int y = 0)
		: xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

	/* ������ �����ε� - ��� �Լ��� ���� ������ �����ε� 
	Point operator+(const Point &ref) const
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
	
	// ���� �Լ��� ���� ������ �����ε�
	//friend Point operator+(const Point &pt1, const Point &pt2);

};
*/
/*
Point operator+(const Point &pt1, const Point &pt2)
{
	Point pos(pt1.xpos + pt2.xpos, pt1.ypos + pt2.ypos);
	return pos;
}
*/

/*
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
*/

/* static �Լ�(Ŭ���� �Լ�)
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
/* const static ���� 
class CountryArea
{
public:
	const static int RUSSIA = 8976;				//���� ���� �ʱ�ȭ?
	const static int SOUTH_KOREAD = 7877;

};


/* static ���� (Ŭ���� ����) 

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
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
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
		cout << comObjCnt << "��° SoComplx ��ü" << endl;
	}
};

int SoSimple::simObjCnt = 0;		// �ۿ��� 1���� �ʱ�ȭ
int SoComplx::comObjCnt = 0;	


/* �� �� �� �� �� �� 
void Counter()		// C �� �� �� ��
{
	static int cnt;
	cnt++;
	cout << "Current cnt : " << cnt << endl;
}
*/



/* friend ���� - �Լ��� ���
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
	friend Point PointOp::PointAdd(const Point &, const Point &); // friend �Լ�
	friend Point PointOp::PointSub(const Point &, const Point &); // friend �Լ�
	friend void ShowPointPos(const Point &); // friend �����Լ� ***
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

void ShowPointPos(const Point &pt) // �� ��� �տ� Point:: �Ⱥ��̴µ� ���� - �����Լ�
{
	cout << "x : " << pt.x << ", ";
	cout << "y : " << pt.y << endl;
}
*/

/* friend ���� - class ��� 
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

/* const �Լ� �����ε�
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
	const �Լ� �����ε� 
	- �Լ� �����ε� ���ǿ��� const ����

	SoSimple obj1(7);
	const SoSimple obj2(10);

	obj1.SimpleFunc();
	obj2.SimpleFunc();
	*/
	/* const ��ü 
	SoSimple generalobj(10);
	generalobj.AddNum(10);
	generalobj.ShowData();

	const SoSimple constobj(100);
	constobj.ShowData();

	// constobj.AddNum(200);	// ****** const ��ü�� const �Լ��� ��� �����ϴ�.
	*/
	
	/* 
	friend ���� - class�� ���
	- friend ������ ��ü������ ĸ��ȭ���� ���������� �����ϴ� ������.
	- ����, friend ������ �ʿ��� ��Ȳ������ ����ؾ���.
	- ������ �����ε����� ���� �Լ��� ����� ���
	
	Boy boy(180);
	Girl girl("010-1234-5678");

	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	*/

	/*
	friend ���� - �Լ��� ���


	Point pos1(1, 2);
	Point pos2(3, 4);

	PointOp op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos1, pos2));
	*/

	/* C������ static ���� (Ŭ���� ����) 
	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	*/

	/* static ���� (Ŭ���� ����) 
	SoSimple sim1;
	SoSimple sim2;

	SoComplx com1;
	SoComplx com2;
	SoComplx com3;
	*/


	/* const static ���� (Ŭ���� ����) 
	cout << "���þ� ���� : " << CountryArea::RUSSIA << endl;
	cout << "�ѱ� ���� : " << CountryArea::SOUTH_KOREAD << endl;
	*/

	/* static �Լ� (class �Լ�)
	- ����� Ŭ������ ��� ��ü�� ����
	- public���� ������ �Ǹ�, Ŭ������ �̸��� �̿��ؼ� ȣ���� ����
	- ��ü�� ����� �����ϴ� ���� �ƴ�.
	*/

	/* mutable Ű���� (cf. explicit) (explicit -> �ڵ� ����ȯ�� ���� �ʰ� ���ִ�)
	- const �Լ� ������ ������� ���� ������ ���������� ���

	*/
	/*
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();
	*/

	/* ������ �����ε� 
		- ���� : �����ڰ� �����ε� �Ǹ�, �ǿ������� ������ ���� ���� ����� �޶����� ��
		- ����Լ��� ���� �����ε�
		- �����Լ��� ���� �����ε�
	*/
	/*
	Point pos1(3, 4);
	Point pos2(10, 10);

	 //�� �� �� �� �� �� �� - ����Լ��� ���� �����ε� 
	Point pos3 = pos1 + pos2;
	/*	
	Point pos3 = pos1.operator+(pos2);
	Point pos3 = pos2.operator+(pos1);
	
	pos1.ShowPosition();
	pos2.ShowPosition();
	
	/* ������ �����ε� ��� 
	pos3.ShowPosition();
	*/


	/* ���� ������ �����ε� (����) 
	Point pos(1, 2);
	++pos; //					(���� ������)
	//pos.operator++();	(����Լ��� ���)
	//operator++(pos);	(�����Լ��� ���)
	pos.ShowPosition();
	--pos;
	//pos.operator--();	(����Լ��� ���)
	//operator--(pos);	(�����Լ��� ���)
	pos.ShowPosition();

	++(++pos);
	pos.ShowPosition();
	--(--pos);
	pos.ShowPosition();

	*/

	/* ���� ���� ������ ���� 
	int num = 10;

	cout << num++ << endl;	// 10(���� ��� �� �� ����)
	cout << ++num << endl;	// 12(���� �� ���� �� ���)

	*/

	/* ���� ������ �����ε� (����) 
	-	++pos, --pos �� ��
		pos.operator++();
		pos.operator--();
	-	pos++, pos-- �� ��
		pos.operator++(int);
		pos.operator--(int);
	
	Point pos2(3, 5);
	Point cp;

	cp =	pos2++;
	pos2.ShowPosition();
	cp.ShowPosition();

	cp = pos2--;
	pos2.ShowPosition();
	cp.ShowPosition();
	*/

	/* �ڷ����� �ٸ� ��� �����ε� */
	Point pos(1, 2);
	Point cpy;

	cpy = pos * 3;

	cpy.ShowPosition();

	return 0;
}