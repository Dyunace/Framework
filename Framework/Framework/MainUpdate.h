#pragma once
#include "Headers.h"

class MainUpdate
{
private:
	int Count;
	SCENEID SceneState;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
public:
	MainUpdate();
	~MainUpdate();
};

