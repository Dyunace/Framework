// ** Framework v7.1.1 ObjectFactory & UserInterface
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

/*
// 템플릿 : 자료형을 보내줄 수 있다.
template <typename T, typename T1>
class Temp
{
public:
	static T* func()
	{
		return new T;
	}
	static T* func(int i)
	{
		return new T(i);
	}
	static T* func(float f)
	{
		return new T(f);
	}

	static T* func(int i, int j)
	{
		return new T(f);
	}
};
class A
{
public:
	int Number;
};
class B
{
public:
	int Number;
};
*/

int main(void)
{
	MainUpdate main;
	main.Initialize();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			main.Update();
			main.Render();
		}
	}

	/*
	DWORD InputKey = 0;

	cout << "입력 : "; cin >> InputKey;

	if (InputKey & KEY_UP)
		cout << "KEY_UP" << endl;

	if (InputKey & KEY_DOWN)
		cout << "KEY_DOWN" << endl;

	if (InputKey & KEY_LEFT)
		cout << "KEY_LEFT" << endl;

	if (InputKey & KEY_RIGHT)
		cout << "KEY_RIGHT" << endl;

	if (InputKey & KEY_SPACE)
		cout << "KEY_SPACE" << endl;

	if (InputKey & KEY_ENTER)
		cout << "KEY_ENTER" << endl;

	if (InputKey & KEY_CTRL)
		cout << "KEY_CTRL" << endl;

	if (InputKey & KEY_ALT)
		cout << "KEY_ALT" << endl;
	*/

	return 0;
}

