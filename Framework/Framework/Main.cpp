// ** Framework v10.1 BulletCollision
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

// ���� : �ּҰ� �ٲ� �� �ִ�. -> �����͸� ����Ϸ��� ��ü�� ���� �ٸ� ���� ���� �� �ִ�.
// ���� : �ּҰ� �ٲ��� �ʴ´�. -> �����͸� ����Ϸ��� ��ü ��ΰ� ���� �ּҰ��� ����Ų��.

/*
	���� �����Ͱ� �������� ���α׷��� ���� �� ������ ���ε� �ð��� ���� �ɸ���,
	�ٸ� ������ ���� �����Ϳ� ������ ���輺�� ����� ������
	���� �����͸� ���� ����ϴ� ���� ���� �ʴ�.
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

