#include "Enemy.h"

#include "CursorManager.h"

Enemy::Enemy(){}
Enemy::Enemy(Transform _Info) : Object(_Info) { }
Enemy::~Enemy(){}

void Enemy::Initialize()
{
	strKey = "Enemy";

	Buffer[0] = (char*)"ȣ";
	Buffer[1] = (char*)"��";
	
	TransInfo.Position = Vector3(0.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
}

int Enemy::Update()
{
	if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;

	return 0;
}

void Enemy::Render()
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		CursorManager::Draw(
			TransInfo.Position.x - TransInfo.Scale.x * 0.5f,
			TransInfo.Position.y - TransInfo.Scale.y * 0.5f + i,
			Buffer[i]);
	}
}

void Enemy::Release(){}

