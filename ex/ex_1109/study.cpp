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
	// ��ȯ���� �������� ���
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