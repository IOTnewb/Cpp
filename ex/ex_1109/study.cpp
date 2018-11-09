#include <iostream>

using namespace std;

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

int main(void)
{
	// 반환형이 참조자인 경우
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