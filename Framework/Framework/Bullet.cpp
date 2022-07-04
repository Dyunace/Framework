#include "Bullet.h"

#include "CursorManager.h"

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
	TransInfo.Direction = Vector3(0.0f, -0.0f);
}

int Bullet::Update()
{

	Vector3 Target = Vector3(60.0f, 15.0f);

	Vector3 TargetVector = Target - TransInfo.Position;

	float Distance = sqrt((TargetVector.x * TargetVector.x) + (TargetVector.y * TargetVector.y));

	TransInfo.Direction.x = TargetVector.x / Distance;
	TransInfo.Direction.y = TargetVector.y / Distance;

	TransInfo.Position += TransInfo.Direction;
	
	//cout << "PosX :" << TransInfo.Position.x << endl;
	//cout << "PosY :" << TransInfo.Position.y << endl;
	//cout << "SpdX :" << TransInfo.Direction.x << endl;
	//cout << "SpdY :" << TransInfo.Direction.y << endl << endl;

	return 0;
}

void Bullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(TransInfo.Position, (char*)"Bullet", 0);
}

void Bullet::Release()
{
}
