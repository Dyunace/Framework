// ** Framework v10.0 ObjectPool
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

// 깜빡임 현상 방지
/*
	이중 버퍼 방식 사용

	버퍼를 a, b 2개로 만든다.
	a를 화면에 띄운 동안 b를 지우고 새로 그린다.
	다음, b를 화면에 띄우고 a를 지우고 새로 그린다.
*/

int main(void)
{
	system("title 이승우 - 게임");

	system("mode con cols=120 lines=30");

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

	return 0;
}

