#ifndef _GAME_ENGINE_UTILITY_TYPE_H_
#define _GAME_ENGINE_UTILITY_TYPE_H_

#include "../common/ge_include.h"

namespace ge
{

struct GE_API GE_IPOINT
{
	GE_IPOINT():x(0), y(0) {}
	GE_IPOINT(int x, int y):x(x), y(y) {}
	~GE_IPOINT() {}

	int x;
	int y;
};

struct GE_API GE_ISIZE
{
	GE_ISIZE():width(0), height(0) {}
	GE_ISIZE(int width, int height):width(width), height(height) {}
	~GE_ISIZE() {}

	int width;
	int height;
};

struct GE_API GE_IRECT : public RECT
{
	GE_IRECT();
	GE_IRECT(int left_, int top_, int right_, int bottom_);
	~GE_IRECT() {}

	int width() {return right - left;}
	int height() {return bottom - top;}

	void move(int offset_x, int offset_y);
	void move_to(int pos_x, int pos_y);
	void include(int pos_x, int pos_y);
};

struct GE_API GE_FPOINT
{
	GE_FPOINT():x(0.f), y(0.f) {}
	GE_FPOINT(float x, float y):x(x), y(y) {}
	~GE_FPOINT() {}

	float x;
	float y;
};

struct GE_API GE_FSIZE
{
	GE_FSIZE():width(0.f), height(0.f) {}
	GE_FSIZE(float width, float height):width(width), height(height) {}
	~GE_FSIZE() {}

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
	~GE_FRECT()  {}

	float width() {return right - left;}
	float height() {return bottom - top;}

	void move(float offset_x, float offset_y);
	void move_to(float pos_x, float pos_y);
	void include(float pos_x, float pos_y);
};

}

#endif // _GAME_ENGINE_UTILITY_TYPE_H_