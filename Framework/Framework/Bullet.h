#pragma once
#include "Parent.h"

class Bullet : public Parent
{
public:
	void Initialize()
	{
		m_Number = 10;
	}
	
	virtual void Update()
	{
		m_Number += 10;
	}

	void Output()
	{
		cout << m_Number << endl;
	}
};

// 인라인 함수
/*
	h 파일에 함수 내용을 직접 입력해서 사용.
	일반 함수 보다 우선적으로 사용되도록 돕는다.

	예외의 경우도 있어서 무조건 우선은 아니다.


*/