#include "Player.h"

void Player::Initialize()
{
}

void Player::Update()
{
	/*
	DWORD Key = InputManager::GetInstance()->GetKey();

	if (Key & KEY_UP)
			cout << "KEY_UP" << endl;

	if (Key & KEY_DOWN)
		cout << "KEY_DOWN" << endl;

	if (Key & KEY_LEFT)
		cout << "KEY_LEFT" << endl;

	if (Key & KEY_RIGHT)
		cout << "KEY_RIGHT" << endl;

	if (Key & KEY_SPACE)
		cout << "KEY_SPACE" << endl;

	if (Key & KEY_ENTER)
	{

	}

	if (Key & KEY_CTRL)
		cout << "KEY_CTRL" << endl;

	if (Key & KEY_ALT)
		cout << "KEY_ALT" << endl;
	*/
}

void Player::Render()
{
	Message("Player");
}

void Player::Release()
{
}

Player::Player() { }

Player::~Player() { }
