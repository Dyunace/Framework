#include "Parent.h"
#include "Child.h"
#include "Bullet.h"


// ** 1. 정보은닉
//		private:	= 자기 자신만 사용 가능.
//		protected:	= 상속간의 공개된 상태. 비상속 클레스 사용불가. 외부 사용 불가.
//		public:		= 공개된 상태


// ** 2. 캡슐화
//		데이터(변수)와 기능(함수)을 묶음으로 사용하는 것.


// ** 3. 추상화
//		존재하지 않는 형태를 추상 클래스 라고 한다.

//		예:) 사람, 학생, 군인 등의 대상이 특정되지 않는 경우.(추상적인 경우.)
//			 "홍길동은 학생이다." 라면 홍길동이라는 특정 대상이 있으므로,
//			 추상적 형태로 볼 수 없음.


// ** 4. 상속
/*
	class AAA
	{
	protected:
		string m_str;
	public:
		void Output() { cout << m_str << endl; }
	};

	class BBB : public AAA
	{
	public:
		void Initialize() { m_str = "BBB"; }
	};

	class CCC : public AAA
	{
	public:
		void Initialize() { m_str = "CCC"; }
	};


	[main 출력]
	//BBB b;
	//b.Initialize();
	//b.Output();
	//
	//CCC c;
	//c.Initialize();
	//c.Output();
*/

// ** 5. 다형성
//		다양한 형태로 존재할 수 있다.

// ** 6. namespace
//		별도의 영역을 지정하여 동일한 이름의 함수를 사용할 수 있도록 함.


// ** 7. 생성자 & 소멸자 & 복사 생성자.

// ** 8. 깊은복사 얕은복사.

// ** 9. 오버로딩 & 오버라이딩.

// ** 10. 연산자 오버로딩.

// ** 11. 포인터 (복습).








const int ID_Child = 0;
const int ID_Bullet = 1;


int main(void)
{
	Parent* p[2];

	p[ID_Child] = new Child;
	p[ID_Bullet] = new Bullet;

	for (int i = 0; i < 2; ++i)
		p[i]->Initialize();

	while (true)
	{
		system("cls");
		for (int i = 0; i < 2; ++i)
			p[i]->Update();

		for (int i = 0; i < 2; ++i)
			p[i]->Output();
	}




	return 0;
}

