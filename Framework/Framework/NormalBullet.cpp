#include "NormalBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"


NormalBullet::NormalBullet()
{

}

NormalBullet::~NormalBullet()
{

}


void NormalBullet::Initialize()
{
	Speed = 0.5f;
	Color = 12;
}

int NormalBullet::Update(Transform& Info)
{
	Info.Direction = MathManager::GetDirection(
		Info.Position, Vector3(60.0f, 15.0f));

	Info.Position += Info.Direction * Speed;
	return 0;
}

void NormalBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"Bullet", Color);
}

void NormalBullet::Release()
{

}