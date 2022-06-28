#include "Bullet.h"

#include "CursorManager.h"

Bullet::Bullet()
{
}

Bullet::Bullet(Transform _Info) : Object(_Info) { }

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	strKey = "£ª";

	TransInfo.Position = Vector3(20.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 1.0f);
}

int Bullet::Update()
{
	TransInfo.Position.x += 2;

	return 0;
}

void Bullet::Render()
{
	CursorManager::Draw(TransInfo.Position.x, TransInfo.Position.y, strKey);
}

void Bullet::Release()
{
}
