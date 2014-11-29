#include "ge_color.h"

namespace ge
{
const Color Color::white = Color(1.0f, 1.0f, 1.0f, 1.0f);
const Color Color::black = Color(0.0f, 0.0f, 0.0f, 1.0f);

Color::Color(float _r, float _g, float _b, float _a)
: r(_r)
, g(_g)
, b(_b)
, a(_a)
{
}

}