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

struct GE_API GE_IPOINT
{
	GE_IPOINT():x(0), y(0) {}
	GE_IPOINT(I32 x, I32 y):x(x), y(y) {}

	int x;
	int y;
};

struct GE_API GE_ISIZE
{
	GE_ISIZE():width(0), height(0) {}
	GE_ISIZE(int width, int height):width(width), height(height) {}

	int width;
	int height;
};

struct GE_API GE_IRECT : public RECT
{
	GE_IRECT();
	GE_IRECT(int left_, int top_, int right_, int bottom_);

	int width() {return right - left;}
	int height() {return bottom - top;}

	void move(int offset_x, int offset_y);
	void move_to(int pos_x, int pos_y);
	void expand(int pos_x, int pos_y);
};

struct GE_API Size
{
	Size():width(0.f), height(0.f) {}
	Size(float width, float height):width(width), height(height) {}

	float width;
	float height;
};


}

#endif // _GAME_ENGINE_UTILITY_TYPE_H_