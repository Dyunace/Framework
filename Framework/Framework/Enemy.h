#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
public:
	Enemy();
	virtual ~Enemy();
};