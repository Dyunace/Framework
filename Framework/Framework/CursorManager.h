#pragma once
#include "Headers.h"

class CursorManager
{
public:
	static void SetCursorPosition(float _x, float _y)
	{
		COORD Pos = { (SHORT)_x, (SHORT)_y };

		//SetConsoleCursorPosition : 커서 위치 바꿔주는 함수
		//GetStdHandle : 콘솔창 화면
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

	static void Draw(float _x, float _y, string _str)
	{
		SetCursorPosition(_x, _y);
		cout << _str;
	}
};