#include "Logo.h"

void Logo::Initialize()
{
	str = "Logo";
}

void Logo::Update()
{
	DWORD Key = InputManager::GetInstance()->GetKey();

	if (Key & KEY_ENTER)
		SceneManager::GetInstance()->SetScene(MENU);
}

void Logo::Render()
{
	cout << str << endl;
}

void Logo::Release()
{
}

Logo::Logo()
{
}

Logo::~Logo()
{
}
