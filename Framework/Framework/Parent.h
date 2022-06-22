#pragma once
#include "Headers.h"

class Parent
{
private:
	// ** �ڱ� �ڽŸ� ��� ����.

protected:
	// ** ��Ӱ��� ������ ����. ���� Ŭ���� ���Ұ�. �ܺ� ��� �Ұ�.
	int m_Number;
public:
	// ** ������ ����
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Output() = 0;

	// ** [virtual] = �����Լ�
	// ** [= 0] : virtual �Լ����� ���ϼ� �ִ�.
	// ** �Լ��� ���� [= 0] ���̰� �Ǹ� [���� ���� �Լ�] �� �ȴ�.

	// ** [���� ���� �Լ�]
	// ** virtual �Լ��� �Լ��� ��ü(����)�� ������ ����Ѵ�.
	
	// ** virtual �Լ��� ����ϴ� ����?
	// ** (���������Լ� ������� �˻�)
};

