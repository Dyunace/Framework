#pragma once
#include "Parent.h"

class Child : public Parent
{
public:
	virtual void Initialize();
	virtual void Update();
	virtual void Output();
};

