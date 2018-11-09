#include "Car.h"

/* �� �� �� ( ������,���ᷮ,����ӵ� )
using namespace std;
namespace CAR_CONST
{
	//	const int ID_LEN = 20; // ������ ���� ������ ���
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
	cout << "������ : " << gamerID << endl;
	cout << "���ᷮ : " << fuelGauge << endl;
	cout << "��   �� : " << curSpeed << endl;
	};

	void Car::Accel()
	{
	//���ᷮ üũ
	if (fuelGauge <= 0)
	return;
	else
	fuelGauge -= CAR_CONST::FUEL_STEP;
	//�ִ� �ӵ� üũ
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
	Car ����ü -> Ŭ����
	1. ĸ��ȭ(��������, ����)
		- ��������
			( ���� ���� ������ )
			public,		 ��𼭵� ���ٰ���
			private,		 Ŭ���� �������� ���� ����
			protected	 ��Ӱ��迡���� ���� ����
		- �������� ( �� �� �� �� �� �� �� )
			�������� �м� �� �����ϱ� ����

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
	// Car ����ü ��� �ʱ�ȭ
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

	/* ��ȯ���� �������� ���
	int num2 = 1;
	int &num3 = RefRetFuncOne(num2);
	// int &num3 = num2;
	num2++;
	num3++;

	cout << "num2 :" << num2 << endl;
	cout << "num3 :" << num3 << endl;


	/* ������ �̿��� call by reference
	int val2 = 10;
	int val3 = 20;

	SwapByRef(val2, val3);

	cout << "val2 : " << val2 << endl;
	cout << "val3 : " << val3 << endl;
	
	/*
	call by value - ���� ���ڷ� �����ϴ� �Լ� ȣ����
	call by reference - �ּ� ���� ���ڷ� �����ϴ� �Լ� ȣ����
	

	/* ������ ������ ������� �� ������

	int num = 12;
	int *ptr = &num;
	int **dptr = &ptr;

	int &ref = num;
	int *(&pref) = ptr;
	int **(&dpref) = dptr;

	cout << ref << endl;
	cout << *pref << endl;
	cout << **dpref << endl;


	/* �迭��� ��� ������
	int arr[3] = { 1,2,3 };
	int &ref1 = arr[0];
	int &ref2 = arr[1];
	int &ref3 = arr[2];

	cout << ref1 << endl;
	cout << ref2 << endl;
	cout << ref3 << endl;

	/* �Ϲ� ������� ������
	int num1 = 1020;
	int &num2 = num1;
	int &num3 = num2;
	int &num4 = num3;

	/* ������ ����� ���� ����
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