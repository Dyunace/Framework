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

