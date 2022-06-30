#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectFactory.h"

void Logo::Initialize()
{
	str = "Logo";

	ObjectManager::GetInstance()->AddObject(ObjectFactory<Player>::CreateObject());
	//ObjectManager::GetInstance()->AddObject(ObjectFactory<Enemy>::CreateObject());
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
