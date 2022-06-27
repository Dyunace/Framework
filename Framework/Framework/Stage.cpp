#include "Stage.h"
#include "Player.h"
#include "SceneManager.h"
#include "ObjectManager.h"

void Stage::Initialize()
{
	// 1. 반환 형태가 Object* && list<Object*>
	// 2. Key 가 전달되어야 함.
	list<Object*>* PlayerList = ObjectManager::GetInstance()->GetObjectList("Player");

	if (PlayerList != nullptr)
		pPlayer = PlayerList->front()->Clone();
}

void Stage::Update()
{
	if(pPlayer)
		pPlayer->Update();
}

void Stage::Render()
{
	if (pPlayer)
		pPlayer->Render();

	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	::Safe_Delete(pPlayer);
}

Stage::Stage() : pPlayer(nullptr)
{
}

Stage::~Stage()
{
	Release();
}
