#ifndef _GAME_ENGINE_UTILITY_TYPE_H_
#define _GAME_ENGINE_UTILITY_TYPE_H_

#include "common/ge_include.h"

namespace ge
{

typedef char*				STR;
typedef wchar_t*			WSTR;
typedef char				I8;
typedef short				I16;
typedef int					I32;
typedef __int64				I64;
typedef unsigned char		U8;
typedef unsigned short		U16;
typedef unsigned int		U32;
typedef unsigned __int64	U64;
typedef float				F32;
typedef double				F64;


typedef U32					LayerMask;
typedef U8					LayerID;

struct GE_API Size
{
	Size():width(0.f), height(0.f) {}
	Size(float width, float height):width(width), height(height) {}

	float width;
	float height;
};


}

#endif // _GAME_ENGINE_UTILITY_TYPE_H_