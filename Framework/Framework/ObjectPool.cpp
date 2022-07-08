#include "ObjectPool.h"
#include "Object.h"
#include "CursorManager.h"
#include "ObjectManager.h"

ObjectPool* ObjectPool::Instance = nullptr;
map<string, list<Object*>> ObjectPool::EnableList;

ObjectPool::ObjectPool()
{

}

ObjectPool::~ObjectPool()
{

}

void ObjectPool::CatchObject(Object* _Object)
{
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_Object->GetKey());

	if (Disableiter == DisableList.end())
	{
		list<Object*> TempList;
		TempList.push_back(_Object);
		DisableList.insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		Disableiter->second.push_back(_Object);
}

Object* ObjectPool::ThrowObject(string _Key)
{
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_Key);

	if (Disableiter != DisableList.end() && Disableiter->second.size())
	{
		Object* pObject = Disableiter->second.front();
		Disableiter->second.pop_front();
		pObject->Initialize(_Key);
		return pObject;
	}

	return nullptr;
}

void ObjectPool::Update()
{
	CursorManager::GetInstance()->WriteBuffer(85.0f, 0.0f, (char*)"DisableList : ");
	CursorManager::GetInstance()->WriteBuffer(100.0f, 0.0f, (int)DisableList["Bullet"].size());

	CursorManager::GetInstance()->WriteBuffer(85.0f, 1.0f, (char*)"EnableList : ");
	CursorManager::GetInstance()->WriteBuffer(100.0f, 1.0f, (int)EnableList["Bullet"].size());

	for (map<string, list<Object*>>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); )
		{
			int result = (*iter2)->Update();

			switch (result)
			{
			case BUFFER_OVER:
			{
				CursorManager::GetInstance()->WriteBuffer(100.0f, 2.0f, (char*)"Bullet is out");
				map<string, list<Object*>>::iterator Disableiter = DisableList.find((*iter2)->GetKey());

				if (Disableiter == DisableList.end())
				{
					list<Object*> TempList;
					TempList.push_back((*iter2));
					DisableList.insert(make_pair((*iter2)->GetKey(), TempList));
				}
				else
					Disableiter->second.push_back((*iter2));

				(*iter).second.erase(iter2);
			}

			case 2:
				CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"충돌하였습니다");
				++iter2;
				break;

			default:
				++iter2;
			}
		}
	}
}