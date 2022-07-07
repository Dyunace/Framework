#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "CollisionManager.h"

Bullet::Bullet(){}
Bullet::Bullet(Transform _Info) : Object(_Info) { }
Bullet::~Bullet(){}

void Bullet::Initialize()
{
	strKey = "Bullet";

	Buffer[0] = (char*)"¡¬";
	Buffer[1] = (char*)"£¯";

	TransInfo.Position = Vector3(20.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(strlen(Buffer[0]), (float)MAX_SIZE);

	TransInfo.Direction = Vector3(0.0f, 0.0f);
	Color = 14;
}

int Bullet::Update()
{
	TransInfo.Direction = MathManager::GetDirection(
		TransInfo.Position, Vector3(60.0f, 15.0f));

	//TransInfo.Position += TransInfo.Direction * 1.5f;
	TransInfo.Position += Vector3(2.0f, 0.0f);

	return 0;
}

void Bullet::Render()
{
	for (int i = 0; i < MAX_SIZE; ++i)
		CursorManager::GetInstance()->WriteBuffer(TransInfo.Position.x, TransInfo.Position.y + i, Buffer[i], Color);
}

void Bullet::Release()
{
}
