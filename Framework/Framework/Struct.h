#pragma once


struct Vector3
{
	float x, y, z;

	Vector3() {};
	Vector3(float _x, float _y) : x(_x), y(_y), z(0) {};
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};
};

struct Transform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};