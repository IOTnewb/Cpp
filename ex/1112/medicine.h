#pragma once
#include "study.h"

/*
ĸ��ȭ - ���� (ex �⺻ ������ comtax)
oop�� ���뼺 �������� ����
����� ������
���� ȯ�ڿ� ���� ��
*/

//�๰ �� ĸ��
class SinivelCap
{
public:
	void Take() const
	{
		cout << "�๰�� ����" << endl;
	}
};
//��ä��� ĸ��
class SneezeCap
{
public:
	void Take() const
	{
		cout << "��ä�Ⱑ ����" << endl;
	}
};

//�ڸ��� �� ĸ��
class SnuffCap
{
public:
	void Take() const
	{
		cout << "�ڰ� �շ�" << endl;
	}
};

// ���� �����
class compact600
{
private:
	SinivelCap scap;
	SneezeCap snecap;
	SnuffCap snucap;
public:
	void Take()
	{
		scap.Take();
		snecap.Take();
		snucap.Take();
	}
};

class Cold
{
public:
	//�๰ ����� ����
	void TakeSinivelCap(SinivelCap &cap)
	{
		cap.Take();
	}
	void TakeSneezeCap(SneezeCap &cap)
	{
		cap.Take();
	}
	void TakeSnuffCap(SnuffCap &cap)
	{
		cap.Take();
	}
	void TakeCompactCap(compact600 &cap)
	{
		cap.Take();
	}

};
