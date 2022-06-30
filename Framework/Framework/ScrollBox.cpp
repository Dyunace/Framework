#include "ScrollBox.h"
#include "CursorManager.h"
#include "InputManager.h"

ScrollBox::ScrollBox()
{
}

ScrollBox::ScrollBox(Transform _Info) : UserInterface(_Info)
{
}

ScrollBox::~ScrollBox()
{
}

void ScrollBox::Initialize()
{
	strKey = "ScrollBox";

	//TextureList.push_back("¡¡¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	TextureList.push_back("¡¡ £¯£þ£þ£þ£þ£þ£þ£þ£þ£þ£¯_¡¬");
	//TextureList.push_back("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	TextureList.push_back(" £¯£þ£þ£þ£þ£þ£þ£¯£þ¡¬ ¦¢");
	TextureList.push_back("¦¢¡¡¡¡¡¡¡¡¡¡¡¡¦¢¡¡__£¯¦¢");
	TextureList.push_back(" ¡¬____________¡¬_____£¯");

	TransInfo.Position = Vector3(float(120 / 2), 5.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(14.0f, 2.0f);
}

int ScrollBox::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	auto iter = TextureList.end();
	iter -= 3;

	if (dwKey & KEY_CTRL)
	{
		TextureList.insert(iter, ("¡¡¦¢¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¦¢"));
	}

	return 0;
}

void ScrollBox::Render()
{
	for (int i = 0; i < TextureList.size(); ++i)
	{
		CursorManager::Draw(
			TransInfo.Position.x - (TransInfo.Scale.x * 0.5f),
			TransInfo.Position.y - (TransInfo.Scale.y * 0.5f) + i,
			TextureList[i]);
	}
}

void ScrollBox::Release()
{
}
