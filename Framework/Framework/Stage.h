#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "InputManager.h"

class Stage : public Scene
{
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage();
	virtual ~Stage();
};

