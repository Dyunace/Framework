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
	map<string, Object*> PrototypeList;
private:
	Prototype();
public:
	~Prototype();
public:
	void Initialize();
	Object* PrototypeObject(string _Key);
};

