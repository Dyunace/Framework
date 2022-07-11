#pragma once
#include "Bridge.h"

class BulletBridge : public Bridge
{
protected:
	// �Ҹ��� �����͸� ����
	float Speed;
	int Color;
public:
	BulletBridge() : Speed(0), Color(0) {};
	virtual ~BulletBridge() {};
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
};