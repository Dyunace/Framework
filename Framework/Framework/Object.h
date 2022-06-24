#pragma once
#include "Headers.h"

class Object
{
public:
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
public:
	Object();
	virtual ~Object();
};

