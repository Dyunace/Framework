#include "Menu.h"

void Menu::Initialize()
{
}

void Menu::Update()
{
	DWORD Key = InputManager::GetInstance()->GetKey();

	if (Key & KEY_UP)
		SceneManager::GetInstance()->SetScene(STAGE);
}

void Menu::Render()
{
}

void Menu::Release()
{
}

Menu::Menu()
{
}

Menu::~Menu()
{
}
