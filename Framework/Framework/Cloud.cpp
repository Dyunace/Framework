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
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		CursorManager::Draw(
			TransInfo.Position.x - TransInfo.Scale.x * 0.5f + i,
			TransInfo.Position.y - TransInfo.Scale.y * 0.5f,
			Buffer[i]);
	}
}

void Cloud::Release()
{
}
