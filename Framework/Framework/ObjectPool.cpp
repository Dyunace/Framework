#include "ObjectPool.h"
#include "Object.h"

ObjectPool* ObjectPool::Instance = nullptr;

ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
}

void ObjectPool::AddObject(string _Key, list<Object*> _List)
{
	EnableList.insert(make_pair(_Key, _List));
}

void ObjectPool::AddObject(Object* _Object)
{

}

void ObjectPool::Update()
{
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
				map<string, list<Object*>>::iterator Disableiter = DisableList.find((*iter2)->GetKey());

				if (Disableiter == DisableList.end())
				{
					list<Object*> TempList;
					TempList.push_back(*iter2);
					DisableList.insert(make_pair((*iter2)->GetKey(), TempList));
				}
				else
					Disableiter->second.push_back((*iter2));

				(*iter).second.erase(iter2);
			}
				break;

			default:
				++iter2;
				break;
			}
		}
	}
}
