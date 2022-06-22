#include "Parent.h"
#include "Child.h"
#include "Bullet.h"


// ** 1. ��������
//		private:	= �ڱ� �ڽŸ� ��� ����.
//		protected:	= ��Ӱ��� ������ ����. ���� Ŭ���� ���Ұ�. �ܺ� ��� �Ұ�.
//		public:		= ������ ����


// ** 2. ĸ��ȭ
//		������(����)�� ���(�Լ�)�� �������� ����ϴ� ��.


// ** 3. �߻�ȭ
//		�������� �ʴ� ���¸� �߻� Ŭ���� ��� �Ѵ�.

//		��:) ���, �л�, ���� ���� ����� Ư������ �ʴ� ���.(�߻����� ���.)
//			 "ȫ�浿�� �л��̴�." ��� ȫ�浿�̶�� Ư�� ����� �����Ƿ�,
//			 �߻��� ���·� �� �� ����.


// ** 4. ���
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


	[main ���]
	//BBB b;
	//b.Initialize();
	//b.Output();
	//
	//CCC c;
	//c.Initialize();
	//c.Output();
*/

// ** 5. ������
//		�پ��� ���·� ������ �� �ִ�.

// ** 6. namespace
//		������ ������ �����Ͽ� ������ �̸��� �Լ��� ����� �� �ֵ��� ��.


// ** 7. ������ & �Ҹ��� & ���� ������.

// ** 8. �������� ��������.

// ** 9. �����ε� & �������̵�.

// ** 10. ������ �����ε�.

// ** 11. ������ (����).








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

