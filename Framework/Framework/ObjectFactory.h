#pragma once
#include"Headers.h"
#include "Object.h"

template <typename T>
class ObjectFactory
{
public:
	static Object* CreateObject()
	{
		Object* pObject = new T;
		pObject->Initialize();

		return pObject;
	}

	static Object* CreateObject(float _x, float _y)
	{
		Object* pObject = new T;
		pObject->Initialize();
		pObject->SetPosition(_x, _y);

		return pObject;
	}

	static Object* CreateObject(Vector3 Position)
	{
		Object* pObject = new T;
		pObject->Initialize();
		pObject->SetPosition(Position);

		return pObject;
	}
};