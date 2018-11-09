#include <iostream>

using namespace std;

int main(void)
{
	//포인터 변수를 대상으로 한 참조자

	int num = 12;
	int *ptr = &num;



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