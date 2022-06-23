// ** Framework v1.2
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

// ** 11. ������ (����) & ĸ��ȭ.
/*
	1. * ������, & �ּҹ�ȯ ������
	2. ������ ������� [���� �Ҵ�]
	3. [.] �ƴϸ� [->]�� ����

	4. [���� �Ҵ�] �ߴٸ� �ݵ�� [�Ҵ� ����] = �޸� ���� ����

	C, C++�� �������� ��������Ѵ�.

	JAVA, C#�� ���������� �����ؼ� �ڵ����� ��������.
	��, ���������� ������ �� �����ϱ� ������ ��Ÿ�� ���߿� ���� �߻��� �� �ִ�.
	�����ڿ� ����� ���� ������ �� ������, ���ʿ��� ������ ���� ����� �̷���� �� �ִ�.
*/

// ������
/*
	1. & ������ (�ּ� ������, AND ������)

	���� ���꿡 ��� (&A). �ش� ���� �ּҸ� ��ȯ��
	���� ���꿡 ��� (A && B). �� ��ΰ� ������ ���� �� ����

	2. || ������ (OR ������)

	���� ���꿡 ��� (A || B). �� �� �ϳ��� ������ ���� �� ����

	3. ^ ������ (XOR ������)

	�����ϴ� ���� ��/������ ���� 1/0�� ��ȯ

	5. << >> ������ (��Ʈ ������)

	������ ����ŭ ��Ʈ�� �̵�
*/

// Singleton
/*
class Singleton
{
private:
	static Singleton* Instance;
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Singleton;

		return Instance;
	}

private:
	int Number;
public:
	int GetNumber() const { return Number; }
	void SetNumber(const int _Number) { Number = _Number; }
private:
	Singleton() : Number(0) {};
public:
	~Singleton() {};
};

Singleton* Singleton::Instance = nullptr;
*/

int main(void)
{
	// �̱��� ���
	/*
	Singleton::GetInstance()->SetNumber(100);
	cout << Singleton::GetInstance()->GetNumber() << endl;
	*/

	// ƽ ī��Ʈ
	/*
	MainUpdate main;
	main.Initialize();

	auto Time = GetTickCount64();

	while (true)
	{
		if (Time % 60 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");
		}
	}
	*/

	return 0;
}

