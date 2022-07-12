#include "SpecialBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"


SpecialBullet::SpecialBullet()
{

}

SpecialBullet::~SpecialBullet()
{

}


void SpecialBullet::Initialize()
{
	Speed = 0.5f;
	Color = 12;
}

int SpecialBullet::Update(Transform& Info)
{
	Info.Direction = MathManager::GetDirection(
		Info.Position, Vector3(60.0f, 15.0f));

	Info.Position.x += 1.0f;

	return 0;
}

void SpecialBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"SpecialBullet", Color);
}

void SpecialBullet::Release()
{

}