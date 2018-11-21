#include <iostream>
#include <cstring>
using namespace std;


/*--------------------- 배열 클래스 주의 사항?--------------- -*/
//
//class Point
//{
//private:
//	int xpos, ypos;
//	/* 기본 대입 연산자 오버로딩 */
//	/* 동일 객체 시스템 내 존재하는 것 방지 */
//	Point &operator=(const Point &ref);
//	/* 복사 생성자의 경우도 같은 일이 발생할 수 있음 */
//	Point(const Point &ref){}
//public:
//	Point(int x=0, int y=0)
//		: xpos(x), ypos(y)
//	{}
//	void ShowData() const
//	{
//		cout << "x : " << xpos << ",  ";
//		cout << "y : " << ypos << endl;
//	}
//};
///* 배열을 저장하기 위한 포인터? */
//class BoundCheckPointArray
//{
//private:
//	Point *array;
//	int arrayLen;
//	/* 배열도 복사 생성/대입 연산자 문제가 발생할 수 있음 */
//	//BoundCheckPointArray(const BoundCheckPointArray &arr){} - 복사생성
//	//BoundCheckPointArray &operator=(const BoundCheckPointArray &arr){} //- 대입연산
//	
//public:
//	BoundCheckPointArray(int len)
//		: arrayLen(len)
//	{
//		array = new Point[len];
//	}
//	//연산자오버로딩
//	Point &operator[](int index)
//	{
//		if (index <0 || index > arrayLen)
//		{
//			cout << "배열 범위 벗어남." << endl;
//			exit(1);
//		}
//		return array[index];
//	}
//
//	~BoundCheckPointArray()
//	{
//		delete[]array;
//	}
//};

/* --------------- 예외처리 --------------------------------- */
/* 예외 던지기 */
void Divide(int num1, int num2)
{
	try
	{
		if (num2 == 0)
			throw 0;
		cout << "목 : " << num1 / num2 <<endl;
		cout << "나머지 : " << num1 % num2 <<endl;
	}
	catch(int expn)
	{
		cout << "first catch" << endl;
		throw;
	}
}

int main(void)
{
	/*--------------------- 배열 클래스 주의 사항?--------------- -*/
	/* 객체의 저장을 위한 배열 클래스 정의 */
	//BoundCheckPointArray arr(3);

	///* 객체 간 메모리 맵 그려보기 */
	//arr[0] = Point(3, 4);
	//arr[1] = Point(5, 6);
	//arr[2] = Point(7, 8);
	///* ------------ 고려 사항 -----------------*/
	///* 연산자 오버로딩 + (***디폴트 대입 연산자 호출***) */
	///* 사원 관리 시스템에서 동일 인물 생성 되면 안됨 */

	//arr[0].ShowData();
	//arr[1].ShowData();
	//arr[2].ShowData();

	///* 배열 복 사 */
	//BoundCheckPointArray cpy(3);
	//cpy = arr;

	/* --------------- 예외처리 --------------------------------- */
	try
	{
		Divide(9, 2);
		Divide(3, 0);
	}
	catch (int expn)
	{
		cout << "second catch" << endl;
		cout << "Error Code : " << expn << endl;
	}
	/* 외부 함수에서 try~catch 쓰고 throw 한거 메인에서 그대로 받아서 또 하고.. */
	return 0;
}