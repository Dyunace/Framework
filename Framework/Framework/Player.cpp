#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "ObjectPool.h"

Player::Player() { }
Player::Player(Transform _TransInfo) : Object(_TransInfo) { }
Player::~Player() { }


void Player::Initialize()
{
	strKey = "Player";

	Buffer[0] = (char*)"¿À";
	Buffer[1] = (char*)"¤µ";

	TransInfo.Position = Vector3(20.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);

	Color = 15;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
		TransInfo.Position.y -= 1;

	if (dwKey & KEY_DOWN)
		TransInfo.Position.y += 1;

	if (dwKey & KEY_LEFT)
		TransInfo.Position.x -= 1;

	if (dwKey & KEY_RIGHT)
		TransInfo.Position.x += 1;

	if (dwKey & KEY_SPACE)
	{
		auto EnableList = ObjectManager::GetInstance()->GetObjectList("Bullet");
		auto DisableList = ObjectManager::GetInstance()->GetDisObjectList("Bullet");

		if (DisableList->size() == 0)
		{
			ObjectManager::GetInstance()->AddObject(ObjectFactory<Bullet>::CreateObject(TransInfo.Position));
		}
		else
		{
			//ObjectManager::GetInstance()->RecycleObject("Bullet");

			auto pBullet = DisableList->front();
			EnableList->push_back(pBullet);
			DisableList->pop_front();
			
			pBullet->Initialize();
			pBullet->SetPosition(TransInfo.Position);

			CursorManager::GetInstance()->WriteBuffer(15.0f, 2.0f, (char*)"Recycle Bullets");
		}
	}

	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		TransInfo.Position, (char*)"Player", Color);
}

void Player::Release()
{

}