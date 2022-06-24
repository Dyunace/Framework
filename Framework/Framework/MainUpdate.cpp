#include "MainUpdate.h"

void MainUpdate::Initialize()
{
	SceneState = LOGO;
	SceneManager::GetInstance()->SetScene(SceneState);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->InputKey();
}

void MainUpdate::Render()
{
}

void MainUpdate::Release()
{
}

MainUpdate::MainUpdate() : Count(0)
{
}

MainUpdate::~MainUpdate()
{
	Release();
}
