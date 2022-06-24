#include "MainUpdate.h"

void MainUpdate::Initialize()
{
	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->InputKey();
	SceneManager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
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
