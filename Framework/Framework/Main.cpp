// ** Framework v10.0 ObjectPool
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

// ������ ���� ����
/*
	���� ���� ��� ���

	���۸� a, b 2���� �����.
	a�� ȭ�鿡 ��� ���� b�� ����� ���� �׸���.
	����, b�� ȭ�鿡 ���� a�� ����� ���� �׸���.
*/

int main(void)
{
	system("title �̽¿� - ����");

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

