#pragma once
#include "UserInterface.h"

class ScrollBox : public UserInterface
{
public:
	ScrollBox();
	ScrollBox(Transform _Info);
	virtual ~ScrollBox();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

