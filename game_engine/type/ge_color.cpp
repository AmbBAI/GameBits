#include "ge_color.h"

namespace ge
{
const Color Color::white = Color(1.0f, 1.0f, 1.0f, 1.0f);
const Color Color::black = Color(0.0f, 0.0f, 0.0f, 1.0f);

Color::Color(float _a, float _r, float _g, float _b)
: a(_a)
, r(_r)
, g(_g)
, b(_b)
{
}


Color32::Color32(const Color& color)
:Color32(U8(color.a * 255), U8(color.r * 255), U8(color.g * 255), U8(color.b * 255))
{
}

}