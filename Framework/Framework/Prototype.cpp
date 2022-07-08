#include "Prototype.h"

#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

Prototype* Prototype::Instance = nullptr;
Prototype::Prototype(){}
Prototype::~Prototype(){}

void Prototype::Initialize()
{
	Transform Info;

	string Key = "Player";
	PrototypeList[Key] = (new Player(Info))->Initialize(Key);

	Key = "Enemy";
	PrototypeList[Key] = (new Enemy(Info))->Initialize(Key);

	Key = "Bullet";
	PrototypeList[Key] = (new Bullet(Info))->Initialize(Key);
}

Object* Prototype::PrototypeObject(string _Key)
{
	map<string, Object*>::iterator iter = PrototypeList.find(_Key);

	if (iter == PrototypeList.end())
	{
		return nullptr;
	}

	return iter->second;
}
