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
	TransInfo.Scale = Vector3(strlen(Buffer[0]), (float)MAX_SIZE);

	Color = 12;
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
		CursorManager::GetInstance()->WriteBuffer(TransInfo.Position.x, TransInfo.Position.y + i, Buffer[i], Color);
}

void Enemy::Release(){}

