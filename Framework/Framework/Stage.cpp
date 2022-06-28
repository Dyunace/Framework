#include "Stage.h"
#include "SceneManager.h"

#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"

#include "CursorManager.h"

void Stage::Initialize()
{
	Object* pEnemyProto = new Enemy;
	pEnemyProto->Initialize();

	for (int i = 0; i < 5; ++i)
	{
		srand(DWORD(GetTickCount64() * (i + 1)));

		Object* pEnemy = pEnemyProto->Clone();
		pEnemy->SetPosition(118.0f, float(rand() % 30));

		ObjectManager::GetInstance()->AddObject(pEnemy);
	}
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();

	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("£ª");
	
	if (pBulletList != nullptr)
	{
		for (list<Object*>::iterator iter = pBulletList->begin();
			iter != pBulletList->end();)
		{
			if ((*iter)->GetPosition().x >= 120.0f)
				iter = pBulletList->erase(iter);
			else
				++iter;
		}
	}
}

void Stage::Render()
{
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
