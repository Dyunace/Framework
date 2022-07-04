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

void Cloud::Initialize()
{
	strKey = "Cloud";

	Buffer[0] = (char*)"c";
	Buffer[1] = (char*)"3";
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
