#pragma once
#include "Object.h"

class Player : public Object
{
private:
	int Horizontal;
	int Vertical;
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
public:
	Player();
	virtual ~Player();
};

