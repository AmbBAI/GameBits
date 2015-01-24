#include "ge_rect.h"

namespace ge
{

Rect::Rect()
: x(0.f)
, y(0.f)
, width(0.f)
, height(0.f)
{
}

Rect::Rect(float _x, float _y, float _width, float _height)
: x(_x)
, y(_y)
, width(_width)
, height(_height)
{
}

float Rect::get_min_x()
{
	if (width <= 0.f) return x + width;
	else return x;
}

float Rect::get_min_y()
{
	if (height <= 0.f) return y + height;
	else return y;
}

float Rect::get_max_x()
{
	if (width >= 0.f) return x + width;
	else return x;
}

float Rect::get_max_y()
{
	if (height >= 0.f) return y + height;
	else return y;
}

float Rect::size()
{
	return width * height;
}

}
