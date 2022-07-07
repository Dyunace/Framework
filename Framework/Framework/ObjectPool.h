#pragma once
#include "Headers.h"

class Object;
class ObjectPool
{
private:
	static ObjectPool* Instance;
public:
	static ObjectPool* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectPool;
		return Instance;
	}
private:
	static map<string, list<Object*>> EnableList;
	static map<string, list<Object*>> DisableList;
public:
	static map<string, list<Object*>>* GetEnableList() { return &EnableList; }
	static map<string, list<Object*>>* GetDisableList() { return &DisableList; }
	void CatchObject(Object* _Object);
	Object* RecycleObject(string _Key);
	void Update();
private:
	ObjectPool();
public:
	~ObjectPool();
};