#ifndef _GAME_ENGINE_UTILITY_TYPE_H_
#define _GAME_ENGINE_UTILITY_TYPE_H_

#include "../common/ge_include.h"

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

struct GE_API GE_FPOINT
{
	GE_FPOINT():x(0.f), y(0.f) {}
	GE_FPOINT(float x, float y):x(x), y(y) {}

	float distance(const GE_FPOINT& point) const;

	float x;
	float y;
};

struct GE_API GE_FSIZE
{
	GE_FSIZE():width(0.f), height(0.f) {}
	GE_FSIZE(float width, float height):width(width), height(height) {}

	float width;
	float height;
};

struct GE_API GE_FRECT
{
	float left;
	float top;
	float right;
	float bottom;

	GE_FRECT();
	GE_FRECT(float left_, float top_, float right_, float bottom_);

	float width() {return right - left;}
	float height() {return bottom - top;}

	void move(float offset_x, float offset_y);
	void move_to(float pos_x, float pos_y);
	void expand(float pos_x, float pos_y);
};

struct GE_COLOR
{
	U32 argb;

	GE_COLOR() : argb(0xffffffff) {}
	GE_COLOR(U8 a, U8 r, U8 g, U8 b) : argb((((((a<<8) | r) << 8) | g) <<8) | b) {}
	GE_COLOR(U32 argb) : argb (argb) {}
};

}

#endif // _GAME_ENGINE_UTILITY_TYPE_H_