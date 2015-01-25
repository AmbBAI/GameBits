#ifndef _GAME_ENGINE_COLOR_H_
#define _GAME_ENGINE_COLOR_H_

#include "common/ge_include.h"
#include "utility/ge_type.h"

namespace ge
{

struct GE_API Color
{
	float r = 1.f;
	float g = 1.f;
	float b = 1.f;
	float a = 1.f;

	Color(float _a, float _r, float _g, float _b);

	static const Color white;
	static const Color black;
};


struct GE_API Color32
{
	U32 argb = 0x00000000;

	Color32() : argb(0xffffffff) {}
	Color32(U8 a, U8 r, U8 g, U8 b) : argb((((((a << 8) | r) << 8) | g) << 8) | b) {}
	Color32(U32 argb) : argb(argb) {}
	Color32(const Color& color);

	static const Color32 white;
	static const Color32 black;
};

}

#endif //_GAME_ENGINE_COLOR_H_