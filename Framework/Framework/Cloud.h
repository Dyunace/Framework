#pragma once
#include "Object.h"

class Cloud : public Object
{
public:
	Cloud();
	Cloud(Transform _Info);
	virtual ~Cloud();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual Object* Clone() override { return new Cloud(*this); };
};

