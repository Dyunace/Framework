#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	Bullet(Transform _Info);
	~Bullet();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual Object* Clone() override { return new Bullet(*this); };
};

