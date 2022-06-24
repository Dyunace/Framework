#include "Stage.h"

void Stage::Initialize()
{
}

void Stage::Update()
{
	DWORD Key = InputManager::GetInstance()->GetKey();

	if (Key & KEY_UP)
		SceneManager::GetInstance()->SetScene(EXIT);
}

void Stage::Render()
{
}

void Stage::Release()
{
}

Stage::Stage()
{
}

Stage::~Stage()
{
}
