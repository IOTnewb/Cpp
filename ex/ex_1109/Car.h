#pragma once
#ifndef __CAR__
#define __CAR__

#include <iostream>
#include <cstring>

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
#endif