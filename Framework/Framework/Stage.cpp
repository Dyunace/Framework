#include "Stage.h"
#include "Player.h"
#include "SceneManager.h"
#include "ObjectManager.h"

void Stage::Initialize()
{
	//pPlayer = ObjectManager::GetInstance();
	//pPlayer->Initialize();
}

void Stage::Update()
{
	//pPlayer->Update();
}

void Stage::Render()
{
	//pPlayer->Render();
	ObjectManager::GetInstance()->Render();
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
