// ** Framework v10.1 BulletCollision
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

// 동적 : 주소가 바뀔 수 있다. -> 데이터를 사용하려는 객체가 서로 다른 값을 가질 수 있다.
// 정적 : 주소가 바뀌지 않는다. -> 데이터를 사용하려는 객체 모두가 같은 주소값을 가르킨다.

/*
	정적 데이터가 많아지면 프로그램의 실행 전 데이터 업로드 시간도 오래 걸리고,
	다른 곳에서 정적 데이터에 접근할 위험성이 생기기 때문에
	정적 데이터를 많이 사용하는 것은 좋지 않다.
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

