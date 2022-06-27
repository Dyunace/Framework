#include "Enemy.h"

Enemy::Enemy(){}
Enemy::Enemy(Transform _Info) : Object(_Info) {}
Enemy::~Enemy(){}

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

