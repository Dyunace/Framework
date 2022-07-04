#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ScrollBox.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "CursorManager.h"
#include "CollisionManager.h"

Stage::Stage() : Check(0){}
Stage::~Stage(){
	Release();
}

void Stage::Initialize()
{
	Check = 0;

	Object* pEnemyProto = ObjectFactory<Enemy>::CreateObject();
	
	pUI = new ScrollBox;
	pUI->Initialize();

	for (int i = 0; i < 5; ++i)
	{
		srand(DWORD(GetTickCount64() * (i + 1)));

		Object* pEnemy = pEnemyProto->Clone();
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

	if (pPlayer != nullptr)
	{
		if (pEnemyList != nullptr)
		{
			for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
				Enemyiter != pEnemyList->end(); ++Enemyiter)
			{
				if (pBulletList != nullptr)
				{
					for (list<Object*>::iterator Bulletiter = pBulletList->begin();
						Bulletiter != pBulletList->end(); ++Bulletiter)
					{
						if (CollisionManager::Collision(*Bulletiter, *Enemyiter))
						{
							
						}
					}
				}

			}
		}
	}

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_TAB)
	{
		Enable_UI();
	}

	if (Check)
		pUI->Update();

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
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();

	if (Check)
		pUI->Render();
}

void Stage::Release()
{
}

void Stage::Enable_UI()
{
	Check = !Check;
}
