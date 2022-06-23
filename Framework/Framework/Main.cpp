// ** Framework v1.2
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

// ** 11. 포인터 (복습) & 캡슐화.
/*
	1. * 데이터, & 주소반환 연산자
	2. 포인터 변수라면 [동적 할당]
	3. [.] 아니면 [->]로 접근

	4. [동적 할당] 했다면 반드시 [할당 해제] = 메모리 누수 방지

	C, C++은 수동으로 지워줘야한다.

	JAVA, C#은 쓰레기통이 존재해서 자동으로 버려진다.
	단, 쓰레기통이 가득찰 때 삭제하기 때문에 런타임 도중에 렉이 발생할 수 있다.
	관리자에 명령을 내려 삭제할 수 있으나, 불필요한 순간에 삭제 명령이 이루어질 수 있다.
*/

// 연산자
/*
	1. & 연산자 (주소 연산자, AND 연산자)

	단항 연산에 사용 (&A). 해당 값의 주소를 반환함
	이항 연산에 사용 (A && B). 둘 모두가 조건을 충족 시 실행

	2. || 연산자 (OR 연산자)

	이항 연산에 사용 (A || B). 둘 중 하나라도 조건을 충족 시 실행

	3. ^ 연산자 (XOR 연산자)

	대응하는 값이 참/거짓에 따라 1/0을 반환

	5. << >> 연산자 (비트 연산자)

	지정한 수만큼 비트를 이동
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
	// 싱글톤 사용
	/*
	Singleton::GetInstance()->SetNumber(100);
	cout << Singleton::GetInstance()->GetNumber() << endl;
	*/

	// 틱 카운트
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

