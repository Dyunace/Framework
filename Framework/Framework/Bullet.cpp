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
	strKey = "Bullet";

	Buffer[0] = (char*)"¡¬";
	Buffer[1] = (char*)"£¯";

	TransInfo.Position = Vector3(20.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
}

int Bullet::Update()
{
	TransInfo.Position.x += 2;

	return 0;
}

void Bullet::Render()
{
	for (int i = 0; i < 2; ++i)
	{
		CursorManager::Draw(
			TransInfo.Position.x - TransInfo.Scale.x * 0.5f ,
			TransInfo.Position.y - TransInfo.Scale.y * 0.5f + i,
			Buffer[i]);
	}
}

void Bullet::Release()
{
}
