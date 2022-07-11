#pragma once
#include "Headers.h"

class Object;
class Prototype
{
private:
	static Prototype* Instance;
public:
	static Prototype* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Prototype;
		return Instance;
	}
private:
	map<string, Object*> ProtoTypeList;
public:
	void Initialize();
	Object* ProtoTypeObject(string _Key);
private:
	Prototype();
public:
	~Prototype();
};