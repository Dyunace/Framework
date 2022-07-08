#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ScrollBox.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "ObjectPool.h"

Stage::Stage() : Check(0), pPlayer(nullptr), pUI(nullptr) { }
Stage::~Stage() { Release(); }


void Stage::Initialize()
{
	Check = 0;

	ObjectManager::GetInstance()->AddObject("Player");
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();

	pUI = new ScrollBox;
	pUI->Initialize();
}

void Stage::Update()
{
	//Object* pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_TAB)
	{
		Enable_UI();
	}

	if (dwKey & KEY_ESCAPE)
	{
		if (pBulletList->size())
		{
			ObjectPool::GetInstance()->CatchObject(pBulletList->back());
			pBulletList->pop_back();
		}
	}

	//pPlayer->Update();
	ObjectManager::GetInstance()->Update();

	if (pBulletList != nullptr)
	{
		for (list<Object*>::iterator iter = pBulletList->begin();
			iter != pBulletList->end(); )
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
				if (CollisionManager::CircleCollision(pPlayer, *Enemyiter))
				{
					//Enemyiter = ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));
				}

				if (pBulletList != nullptr)
				{
					for (list<Object*>::iterator Bulletiter = pBulletList->begin();
						Bulletiter != pBulletList->end(); )
					{
						//if (CollisionManager::RectCollision(*Bulletiter, *Enemyiter))
						//	Bulletiter = ObjectManager::GetInstance()->ThrowObject(Bulletiter, (*Bulletiter));
						//else
						//	++Bulletiter;
					}
				}
			}
		}
	}

	if (Check)
		pUI->Update();
}

void Stage::Render()
{
	//pPlayer->Render();
	ObjectManager::GetInstance()->Render();

	if (Check)
		pUI->Render();
}

void Stage::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	delete pUI;
	pUI = nullptr;
}

void Stage::Enable_UI()
{
	Check = !Check;
}