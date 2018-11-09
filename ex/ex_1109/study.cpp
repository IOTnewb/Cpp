#include "Car.h"

/* 자 동 차 ( 소유자,연료량,현재속도 )
using namespace std;
namespace CAR_CONST
{
	//	const int ID_LEN = 20; // 열거자 쓰기 싫으면 사용
	enum
	{
		ID_LEN = 20,
		MAX_SPEED = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};

}

class Car
	{
	public:
		void InitMember(const char *ID, int fuel);
		void ShowCarstate();
		void Accel();
		void Break();
	private:
		char gamerID[CAR_CONST::ID_LEN];
		int fuelGauge;
		int curSpeed;
	};

	void Car::InitMember(const char *ID, int fuel)
	{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
	}

	void Car::ShowCarstate()
	{
	cout << "소유자 : " << gamerID << endl;
	cout << "연료량 : " << fuelGauge << endl;
	cout << "속   도 : " << curSpeed << endl;
	};

	void Car::Accel()
	{
	//연료량 체크
	if (fuelGauge <= 0)
	return;
	else
	fuelGauge -= CAR_CONST::FUEL_STEP;
	//최대 속도 체크
	if(curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPEED)
	{
	curSpeed = CAR_CONST::MAX_SPEED;
	return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
	};

	void Car::Break()
	{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
	curSpeed = 0;
	return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
	}


/*
#define ID_LEN  20
#define MAX_SPEED  200
#define FUEL_STEP  2
#define ACC_STEP  10
#define BRK_STEP  10
*/

/*
	Car 구조체 -> 클래스
	1. 캡슐화(정보은닉, 범위)
		- 정보은닉
			( 접근 제어 지시자 )
			public,		 어디서든 접근가능
			private,		 클래스 내에서만 접근 가능
			protected	 상속관계에서만 접근 가능
		- 범위설정 ( 겁 나 어 렵 습 니 다 )
			개발자의 분석 후 정의하기 나름

*/





/*
void SwapByRef(int &ref1, int &ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int& RefRetFuncOne(int &ref)
{
	ref++;
	return ref;
}
*/

int main(void)
{
	// Car 구조체 사용 초기화
	Car run9;
	run9.InitMember("run9", 100);
	run9.Accel();
	run9.Accel();
	run9.Accel();
	run9.ShowCarstate();
	run9.Break();
	run9.ShowCarstate();


	Car run8;// = { "run8", 100, 0 };
	run8.InitMember("run8", 100);
	run8.Accel();
	run8.Accel();
	run8.Break();
	run8.ShowCarstate();

	/* 반환형이 참조자인 경우
	int num2 = 1;
	int &num3 = RefRetFuncOne(num2);
	// int &num3 = num2;
	num2++;
	num3++;

	cout << "num2 :" << num2 << endl;
	cout << "num3 :" << num3 << endl;


	/* 참조자 이용한 call by reference
	int val2 = 10;
	int val3 = 20;

	SwapByRef(val2, val3);

	cout << "val2 : " << val2 << endl;
	cout << "val3 : " << val3 << endl;
	
	/*
	call by value - 값을 인자로 전달하는 함수 호출방식
	call by reference - 주소 값을 인자로 전달하는 함수 호출방식
	

	/* 포인터 변수를 대상으로 한 참조자

	int num = 12;
	int *ptr = &num;
	int **dptr = &ptr;

	int &ref = num;
	int *(&pref) = ptr;
	int **(&dpref) = dptr;

	cout << ref << endl;
	cout << *pref << endl;
	cout << **dpref << endl;


	/* 배열요소 대상 참조자
	int arr[3] = { 1,2,3 };
	int &ref1 = arr[0];
	int &ref2 = arr[1];
	int &ref3 = arr[2];

	cout << ref1 << endl;
	cout << ref2 << endl;
	cout << ref3 << endl;

	/* 일반 변수대상 참조자
	int num1 = 1020;
	int &num2 = num1;
	int &num3 = num2;
	int &num4 = num3;

	/* 참조자 선언시 주의 사항
	int &ref = 20;
	int &ref;
	int &ref = NULL;
	
	num2 = 3047;

	cout << "VAL : " << num1 << endl;
	cout << "REF : " << num2 << endl;
	cout << "REF num3: " << num3 << endl;
	cout << "REF num4: " << num4 << endl;

	cout << "VAL : " << &num1 << endl;
	cout << "REF : " << &num2 << endl;
	cout << "REF num3: " << &num3 << endl;
	cout << "REF num4: " << &num4 << endl;
	*/
	return 0;
}