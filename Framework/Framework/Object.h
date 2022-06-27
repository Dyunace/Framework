#pragma once
#include "Headers.h"

class Object
{
protected:
	string strKey;
public:
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
public:
	string GetKey() const { return strKey; }
public:
	Object();
	virtual ~Object();
};
