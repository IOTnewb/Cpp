#pragma once
#include "study.h"

/*
캡슐화 - 범위 (ex 기본 감기약과 comtax)
oop는 재사용성 유지보수 생각
만들어 보세요
감기 환자와 감기 약
*/

//콧물 약 캡슐
class SinivelCap
{
public:
	void Take() const
	{
		cout << "콧물이 멈춰" << endl;
	}
};
//재채기약 캡슐
class SneezeCap
{
public:
	void Take() const
	{
		cout << "재채기가 멈춰" << endl;
	}
};

//코막힘 약 캡슐
class SnuffCap
{
public:
	void Take() const
	{
		cout << "코가 뚫려" << endl;
	}
};

// 종합 갬기약
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
	//콧물 감기약 복용
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
