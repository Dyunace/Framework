#pragma once
#include "Headers.h"
#include "SceneManager.h"
#include "InputManager.h"

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

