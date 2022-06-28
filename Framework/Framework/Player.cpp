#include "Player.h"
#include "Bullet.h"
#include "InputManager.h"

#include "ObjectManager.h"
#include "CursorManager.h"

Player::Player() : Horizontal(0), Vertical(0) { }
Player::~Player() { }

void Player::Initialize()
{
	strKey = "¡Ý";

	TransInfo.Position = Vector3(20.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 1.0f);
}

int Player::Update()
{
	
	DWORD Key = InputManager::GetInstance()->GetKey();

	if (Key & KEY_UP)
		TransInfo.Position.y -= 1;

	if (Key & KEY_DOWN)
		TransInfo.Position.y += 1;

	if (Key & KEY_LEFT)
		TransInfo.Position.x -= 1;

	if (Key & KEY_RIGHT)
		TransInfo.Position.x += 1;

	if (Key & KEY_SPACE)
	{
		Object* pBullet = new Bullet;
		pBullet->Initialize();
		pBullet->SetPosition(TransInfo.Position);

		ObjectManager::GetInstance()->AddObject(pBullet);
	}

	return 0;
}

void Player::Render()
{
	CursorManager::Draw(TransInfo.Position.x, TransInfo.Position.y, strKey);
}

void Player::Release()
{
}
