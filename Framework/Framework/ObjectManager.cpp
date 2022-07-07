#include "ObjectManager.h"
#include "ObjectPool.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{
	EnableList = ObjectPool::GetEnableList();
	DisableList = ObjectPool::GetDisableList();
}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::AddObject(Object* _Object)
{
	map<string, list<Object*>>::iterator iter = EnableList->find(_Object->GetKey());
	
	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(_Object);
		EnableList->insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		iter->second.push_back(_Object);
}

list<Object*>* ObjectManager::GetObjectList(string _strKey)
{
	map<string, list<Object*>>::iterator iter = EnableList->find(_strKey);

	if (iter == EnableList->end())
		return nullptr;

	return &iter->second;
}

list<Object*>* ObjectManager::GetDisObjectList(string _strKey)
{
	map<string, list<Object*>>::iterator iter = DisableList->find(_strKey);

	if (iter == DisableList->end())
		return nullptr;

	return &iter->second;
}

list<Object*>::iterator ObjectManager::ThrowObject(list<Object*>::iterator _Where, Object* _Object)
{
	map<string, list<Object*>>::iterator iter = EnableList->find(_Object->GetKey());

	if (iter == EnableList->end())
		return _Where;

	ObjectPool::GetInstance()->CatchObject(_Object);
	return iter->second.erase(_Where);
}

void ObjectManager::RecycleObject(string _Key)
{
	auto Disiter = DisableList->find(_Key);
	auto Eniter = EnableList->find(_Key);

	auto pBullet = Disiter->second.front();

	if (Disiter == DisableList->end())
		return;
	else
	{
		if (Disiter->second.size() == 0)
		{
			Eniter->second.push_back(pBullet);
			Disiter->second.pop_front();
		}
	}
	// 이 함수에 포지션 매개변수 추가하기
	//pBullet->Initialize();
	//pBullet->SetPosition(TransInfo.Position);
	//
	//auto Disableiter = DisableList->find(_Key);
	//auto Enableiter = EnableList->find(_Key);
	//
	//Enableiter->second.push_back(Disableiter->second.front());
	//Disableiter->second.pop_front();
}

void ObjectManager::Update()
{
	ObjectPool::GetInstance()->Update();
}

void ObjectManager::Render()
{
	for (map<string, list<Object*>>::iterator iter = EnableList->begin();
		iter != EnableList->end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}