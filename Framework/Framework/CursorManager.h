#pragma once
#include "Headers.h"

class CursorManager
{
public:
	static void SetCursorPosition(float _x, float _y)
	{
		COORD Pos = { (SHORT)_x, (SHORT)_y };

		//SetConsoleCursorPosition : Ŀ�� ��ġ �ٲ��ִ� �Լ�
		//GetStdHandle : �ܼ�â ȭ��
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

	static void Draw(float _x, float _y, string _str)
	{
		SetCursorPosition(_x, _y);
		cout << _str;
	}
};