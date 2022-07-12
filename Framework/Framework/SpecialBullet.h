#pragma once
#include "BulletBridge.h"

class SpecialBullet : public BulletBridge
{
public:
	SpecialBullet();
	virtual ~SpecialBullet();
public:
	virtual void Initialize() override;
	virtual int Update(Transform& Info) override;
	virtual void Render() override;
	virtual void Release() override;
};

