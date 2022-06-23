#pragma once
#include "Headers.h"

class SceneManager
{
private:
	static SceneManager* Instance;
public:
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SceneManager;

		return Instance;
	}

private:

public:
	void SetScene(SCENEID SceneState);
private:
	SceneManager();
public:
	~SceneManager();
};

