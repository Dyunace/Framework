#pragma once
#include "Headers.h"

class MainUpdate
{
private:
	int Count;
	SCENEID Stage;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
public:
	MainUpdate();
	~MainUpdate();
};

