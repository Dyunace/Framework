#include "Enemy.h"

void Enemy::Initialize()
{
	strKey = "Enemy";
}

void Enemy::Update()
{
}

void Enemy::Render()
{
	Message(strKey);
}

void Enemy::Release()
{
}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}
