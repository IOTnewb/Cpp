#include <iostream>
#include <cstring>
using namespace std;


/*--------------------- �迭 Ŭ���� ���� ����?--------------- -*/
//
//class Point
//{
//private:
//	int xpos, ypos;
//	/* �⺻ ���� ������ �����ε� */
//	/* ���� ��ü �ý��� �� �����ϴ� �� ���� */
//	Point &operator=(const Point &ref);
//	/* ���� �������� ��쵵 ���� ���� �߻��� �� ���� */
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
///* �迭�� �����ϱ� ���� ������? */
//class BoundCheckPointArray
//{
//private:
//	Point *array;
//	int arrayLen;
//	/* �迭�� ���� ����/���� ������ ������ �߻��� �� ���� */
//	//BoundCheckPointArray(const BoundCheckPointArray &arr){} - �������
//	//BoundCheckPointArray &operator=(const BoundCheckPointArray &arr){} //- ���Կ���
//	
//public:
//	BoundCheckPointArray(int len)
//		: arrayLen(len)
//	{
//		array = new Point[len];
//	}
//	//�����ڿ����ε�
//	Point &operator[](int index)
//	{
//		if (index <0 || index > arrayLen)
//		{
//			cout << "�迭 ���� ���." << endl;
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

/* --------------- ����ó�� --------------------------------- */
/* ���� ������ */
void Divide(int num1, int num2)
{
	try
	{
		if (num2 == 0)
			throw 0;
		cout << "�� : " << num1 / num2 <<endl;
		cout << "������ : " << num1 % num2 <<endl;
	}
	catch(int expn)
	{
		cout << "first catch" << endl;
		throw;
	}
}

int main(void)
{
	/*--------------------- �迭 Ŭ���� ���� ����?--------------- -*/
	/* ��ü�� ������ ���� �迭 Ŭ���� ���� */
	//BoundCheckPointArray arr(3);

	///* ��ü �� �޸� �� �׷����� */
	//arr[0] = Point(3, 4);
	//arr[1] = Point(5, 6);
	//arr[2] = Point(7, 8);
	///* ------------ ��� ���� -----------------*/
	///* ������ �����ε� + (***����Ʈ ���� ������ ȣ��***) */
	///* ��� ���� �ý��ۿ��� ���� �ι� ���� �Ǹ� �ȵ� */

	//arr[0].ShowData();
	//arr[1].ShowData();
	//arr[2].ShowData();

	///* �迭 �� �� */
	//BoundCheckPointArray cpy(3);
	//cpy = arr;

	/* --------------- ����ó�� --------------------------------- */
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
	/* �ܺ� �Լ����� try~catch ���� throw �Ѱ� ���ο��� �״�� �޾Ƽ� �� �ϰ�.. */
	return 0;
}