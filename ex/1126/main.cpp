#include <iostream>
#include <cstring>

using namespace std;

template <typename T>	// 내가 정의 하기 나름

class Point
{
private:
	T xpos, ypos;
public:
	Point(T x=0, T y=0)
		: xpos(x), ypos(y)
	{}

	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

int main(void)
{
	/* 1. 클래스 템플릿 */
	//- 배열을 위한 클래스를 템플릿화
	//- STL에서 자주씀
	Point<int> pos1(3, 4);
	pos1.ShowPosition();

	Point<double> pos2(2.2, 5.5);
	pos2.ShowPosition();

	Point<char> pos3('X', 'Y');
	pos3.ShowPosition();


}