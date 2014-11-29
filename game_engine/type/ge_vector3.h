#ifndef _GAME_ENGINE_VECTOR3_H_
#define _GAME_ENGINE_VECTOR3_H_

#include "common/ge_include.h"
#include "common/ge_engine.h"

namespace ge
{
struct GE_API Vector3
{
	float x = 0.f;
	float y = 0.f;
	float z = 0.f;

	Vector3();
	Vector3(float _x, float _y, float _z);

	static const Vector3 zero;
	static const Vector3 one;
};
}

#endif //_GAME_ENGINE_VECTOR3_H_