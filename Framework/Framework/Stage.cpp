#include "Stage.h"
#include "SceneManager.h"
#include "Player.h"

void Stage::Initialize()
{
	pPlayer = new Player;
	pPlayer->Initialize();
}

void Stage::Update()
{
	pPlayer->Update();
}

void Stage::Render()
{
	pPlayer->Render();
}

void Stage::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}

Stage::Stage() : pPlayer(nullptr)
{
}

Stage::~Stage()
{
	Release();
}
