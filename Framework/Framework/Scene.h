#pragma once
#include "Headers.h"

class Scene
{
protected:
	string str;
public:
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
public:
	Scene();
	Scene(string* _str);
	virtual ~Scene();
};

