#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"

void MainUpdate::Initialize()
{
	CursorManager::GetInstance()->CreateBuffer(120.0f, 30.0f);

	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->InputKey();
	SceneManager::GetInstance()->Update();

	CursorManager::GetInstance()->FlipingBuffer();
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
