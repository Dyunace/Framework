#pragma once
#include "Object.h"

class Player : public Object
{
public:
	Player();
	Player(Transform _Info);
	virtual ~Player();
public:
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual Object* Clone() override { return new Player(*this); };
public:
	Object* CreateBullet();
};
