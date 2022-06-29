#include "Stage.h"
#include "SceneManager.h"

#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"

#include "CursorManager.h"
#include "CollisionManager.h"

void Stage::Initialize()
{
	Object* pEnemyProto = new Enemy;
	pEnemyProto->Initialize();

	for (int i = 0; i < 5; ++i)
	{
		srand(DWORD(GetTickCount64() * (i + 1)));

		Object* pEnemy = pEnemyProto->Clone();
		pEnemy->SetPosition(118.0f, float(rand() % 30));
		pEnemy->SetPosition(float(rand() % 118), float(rand() % 30));

		ObjectManager::GetInstance()->AddObject(pEnemy);
	}
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();

	Object* pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
	
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

	if (pBulletList != nullptr && pEnemyList != nullptr)
	{
		for (list<Object*>::iterator Bulletiter = pBulletList->begin();
			Bulletiter != pBulletList->end(); ++Bulletiter)
		{
			for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
				Enemyiter != pEnemyList->end(); ++Enemyiter)
			{
				if (CollisionManager::Collision(*Bulletiter, *Enemyiter))
				{
					CursorManager::Draw(50.0f, 1.0f, "충돌입니다");
				}
			}
		}
	}

	//if (pBulletList != nullptr && pEnemyList != nullptr)
	//{
	//	for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
	//			Enemyiter != pEnemyList->end(); ++Enemyiter)
	//	{
	//		for (list<Object*>::iterator Bulletiter = pBulletList->begin();
	//			Bulletiter != pBulletList->end(); )
	//		{
	//			if (CollisionManager::Collision(*Bulletiter, *Enemyiter))
	//			{
	//				CursorManager::Draw(50.0f, 1.0f, "충돌입니다");
	//				Bulletiter = pBulletList->erase(Bulletiter);
	//			}
	//			else
	//				++Bulletiter;
	//		}
	//	}
	//}

	if (pPlayer != nullptr && pEnemyList != nullptr)
	{
		for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
			Enemyiter != pEnemyList->end(); ++Enemyiter)
		{
			if (CollisionManager::Collision(pPlayer, *Enemyiter))
				CursorManager::Draw(50.0f, 1.0f, "충돌입니다");
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
