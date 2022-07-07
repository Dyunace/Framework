#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;

		return Instance;
	}
private:
	map<string, list<Object*>>* EnableList;
	map<string, list<Object*>>* DisableList;
private:
	ObjectManager();
public:
	~ObjectManager();
public:
	void AddObject(Object* _Object);
	list<Object*>* GetObjectList(string _strKey);
	list<Object*>* GetDisObjectList(string _strKey);
	list<Object*>::iterator ThrowObject(list<Object*>::iterator _Where, Object* _Object);
	void RecycleObject(string _Key);
public:
	void Update();
	void Render();
};

