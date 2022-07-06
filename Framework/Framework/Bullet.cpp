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
	TransInfo.Scale = Vector3(2.0f, 2.0f);

	TransInfo.Direction = Vector3(0.0f, 0.0f);
}

int Bullet::Update()
{
	TransInfo.Direction = MathManager::GetDirection(TransInfo.Position, Vector3(60.0f, 15.0f));

	//TransInfo.Position += TransInfo.Direction;
	TransInfo.Position += Vector3(2.0f, 0.0f);

	float Distance = MathManager::GetDistance(TransInfo.Position, Vector3(60.0f, 15.0f));

	if (Distance < 4)
		return BUFFER_OVER;

	return 0;
}

void Bullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(TransInfo.Position, (char*)"Bullet");
}

void Bullet::Release()
{
}
