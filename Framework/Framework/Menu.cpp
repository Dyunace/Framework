#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"

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
	cout << str << endl;
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
