#pragma once
#include "Headers.h"
#include "Object.h"

class CollisionManager
{
public:
	static bool Collision (const Object* _ObjA, const Object* _ObjB)
	{
		Vector3 Position_A = _ObjA->GetPosition();
		Vector3 Position_B = _ObjB->GetPosition();

		Vector3 Scale_A = _ObjA->GetScale();
		Vector3 Scale_B = _ObjB->GetScale();

		// Å¾ºä
		/*
		if (Position_A.x + (Scale_A.x * 0.5f) > Position_B.x - (Scale_B.x * 0.5f) &&
			Position_B.x + (Scale_B.x * 0.5f) > Position_A.x - (Scale_A.x * 0.5f) &&
			Position_A.y == Position_B.y)
			return true;
		*/

		// È¾½ºÅ©·Ñ °ÔÀÓ
		if (Position_A.x + (Scale_A.x * 0.5f) > Position_B.x - (Scale_B.x * 0.5f) &&
			Position_B.x + (Scale_B.x * 0.5f) > Position_A.x - (Scale_A.x * 0.5f) &&
			Position_A.y + (Scale_A.y * 0.5f) == Position_B.y + (Scale_B.y * 0.5f))
			return true;

		// »çÀÌµåºä °ÔÀÓ
		/*
		if (Position_A.x + (Scale_A.x * 0.5f) > Position_B.x - (Scale_B.x * 0.5f) &&
			Position_B.x + (Scale_B.x * 0.5f) > Position_A.x - (Scale_A.x * 0.5f) &&
			Position_A.y + (Scale_A.y * 0.5f) > Position_B.y - (Scale_B.y * 0.5f) &&
			Position_B.y + (Scale_B.y * 0.5f) > Position_A.y - (Scale_A.y * 0.5f))
			return true;
		*/

		return false;
	}
};