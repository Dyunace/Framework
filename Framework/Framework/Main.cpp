// ** Framework v6.2 CollisionManager
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"


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

	cout << "ют╥б : "; cin >> InputKey;

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

