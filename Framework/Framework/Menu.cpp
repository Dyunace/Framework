#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"

void Menu::Initialize()
{
	str = "Menu";
}

void Menu::Update()
{
	DWORD Key = InputManager::GetInstance()->GetKey();

	if (Key & KEY_ENTER)
		SceneManager::GetInstance()->SetScene(STAGE);
}

void Menu::Render()
{
	CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"Menu");
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
