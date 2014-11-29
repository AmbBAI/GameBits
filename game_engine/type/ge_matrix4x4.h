#ifndef _GAME_ENGINE_MATRIX4X4_H_
#define _GAME_ENGINE_MATRIX4X4_H_

#include "common/ge_include.h"
#include "common/ge_engine.h"

namespace ge
{
struct GE_API Matrix4x4
{
	float r[4][4];
	float get_val(int row, int col);
};
}

#endif //_GAME_ENGINE_MATRIX4X4_H_