#ifndef _GAME_ENGINE_VECTOR2_H_
#define _GAME_ENGINE_VECTOR2_H_

#include "common/ge_include.h"

namespace ge
{
struct GE_API Vector2
{
	float x = 0.f;
	float y = 0.f;

	Vector2();
	Vector2(float _x, float _y);

	static const Vector2 zero;
	static const Vector2 one;
};
}

#endif //_GAME_ENGINE_VECTOR2_H_