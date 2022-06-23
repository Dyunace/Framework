#include "MainUpdate.h"

void MainUpdate::Initialize()
{
	Stage = LOGO;
}

void MainUpdate::Update()
{
	++Count;

	if (Count <= 100)
	{
		Count = 0;
	}
}

void MainUpdate::Render()
{
}

void MainUpdate::Release()
{
}

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
	Release();
}
