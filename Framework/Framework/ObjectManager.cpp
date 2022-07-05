#include "ObjectManager.h"
#include "CollisionManager.h"
#include "Object.h"
#include "ObjectPool.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::AddObject(Object* _Object)
{
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());

	if (iter == ObjectList.end())
	{
		list<Object*> TempList;
		TempList.push_back(_Object);
		ObjectPool::GetInstance()->AddObject(_Object->GetKey(), TempList);
		//ObjectList.insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		iter->second.push_back(_Object);
}

list<Object*>* ObjectManager::GetObjectList(string _Object)
{	
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object);

	if (iter == ObjectList.end())
		return nullptr;

	return &iter->second;
}

void ObjectManager::Update()
{
	ObjectPool::GetInstance()->Update();
}

void ObjectManager::Render()
{
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
			(*iter2)->Render();
}
