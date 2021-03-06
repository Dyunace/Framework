#pragma once
#include "BulletBridge.h"

class NormalBullet : public BulletBridge
{
public:
	NormalBullet();
	virtual ~NormalBullet();
public:
	virtual void Initialize() override;
	virtual int Update(Transform& Info) override;
	virtual void Render() override;
	virtual void Release() override;
};

