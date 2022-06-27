#include "Stage.h"
#include "Player.h"
#include "SceneManager.h"
#include "ObjectManager.h"

void Stage::Initialize()
{
	// 1. ��ȯ ���°� Object* && list<Object*>
	// 2. Key �� ���޵Ǿ�� ��.
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
