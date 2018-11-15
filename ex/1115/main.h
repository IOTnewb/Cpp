#pragma once
#include <iostream>

using namespace std;

void printmenu()
{
	std::cout << "----------- MENU --------------" << std::endl;
	std::cout << "1.계좌 개설" << std::endl;
	std::cout << "2.입금" << std::endl;
	std::cout << "3.출금" << std::endl;
	std::cout << "4.계좌정보 전체 출력" << std::endl;
	std::cout << "5.프로그램 종료\n" << std::endl;
	std::cout << "선택 : ";
}
