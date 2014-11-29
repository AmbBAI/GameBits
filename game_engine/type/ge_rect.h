#ifndef _GAME_ENGINE_RECT_H_
#define _GAME_ENGINE_RECT_H_

#include "common/ge_include.h"

namespace ge
{
struct GE_API Rect
{
	float x;
	float y;
	float width;
	float height;

	Rect();
	Rect(float _x, float _y, float _width, float _height);

	float get_min_x();
	float get_min_y();
	float get_max_x();
	float get_max_y();

	void set_min_x(float _x);
	void set_min_y(float _y);
	void set_max_x(float _x);
	void set_max_y(float _y);

	float size();
};
}

#endif //_GAME_ENGINE_RECT_H_