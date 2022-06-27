#include "Player.h"
#include "InputManager.h"

Player::Player() : Horizontal(0), Vertical(0) { }
Player::~Player() { }

void Player::Initialize()
{
	strKey = "Player";
	Horizontal = 0;
	Vertical = 0;
}

void Player::Update()
{
	
	DWORD Key = InputManager::GetInstance()->GetKey();

	if (Key & KEY_UP)
		Vertical += 1;

	if (Key & KEY_DOWN)
		Vertical -= 1;

	if (Key & KEY_LEFT)
		Horizontal -= 1;

	if (Key & KEY_RIGHT)
		Horizontal += 1;

	if (Key & KEY_SPACE)
		cout << "KEY_SPACE" << endl;

	if (Key & KEY_CTRL)
		cout << "KEY_CTRL" << endl;

	if (Key & KEY_ALT)
		cout << "KEY_ALT" << endl;
	
}

void Player::Render()
{
	Message(strKey);

	cout << "X : " << Horizontal << endl;
	cout << "Y : " << Vertical << endl;

}

void Player::Release()
{
}
