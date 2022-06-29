#include "Enemy.h"

#include "CursorManager.h"

Enemy::Enemy(){}
Enemy::Enemy(Transform _Info) : Object(_Info) { }
Enemy::~Enemy(){}

void Enemy::Initialize()
{
	strKey = "Enemy";

	Buffer[0] = (char*)"È£";
	Buffer[1] = (char*)"¤µ";
	
	TransInfo.Position = Vector3(0.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
}

int Enemy::Update()
{
	//TransInfo.Position.x -= 2;

	if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;

	return 0;
}

void Enemy::Render()
{
	for (int i = 0; i < 2; ++i)
	{
		CursorManager::Draw(
			TransInfo.Position.x - TransInfo.Scale.x * 0.5f,
			TransInfo.Position.y - TransInfo.Scale.x * 0.5f + i,
			Buffer[i]);
	}
}

void Enemy::Release()
{
}

