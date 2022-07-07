#pragma once
#include "Object.h"

class Player : public Object
{
private:
	map<string, list<Object*>>* DisableList;
public:
	Player();
	Player(Transform _Info);
	virtual ~Player();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual Object* Clone() override { return new Player(*this); };
};

