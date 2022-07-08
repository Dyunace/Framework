#include "Cloud.h"
#include "CursorManager.h"

Cloud::Cloud()
{
}

Cloud::Cloud(Transform _Info) : Object(_Info)
{
}

Cloud::~Cloud()
{
}

Object* Cloud::Initialize(string _Key)
{
	strKey = _Key;

	Buffer[0] = (char*)"c";
	Buffer[1] = (char*)"3";

	return nullptr;
}

int Cloud::Update()
{


    return 0;
}

void Cloud::Render()
{
	CursorManager::GetInstance()->WriteBuffer(TransInfo.Position, (char*)"Cloud");
}

void Cloud::Release()
{
}
