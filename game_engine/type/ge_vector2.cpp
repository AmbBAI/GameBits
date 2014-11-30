#include "ge_vector2.h"

namespace ge
{
const Vector2 Vector2::one = Vector2(1.f, 1.f);
const Vector2 Vector2::zero = Vector2(0.f, 0.f);

Vector2::Vector2()
: x(0.f)
, y(0.f)
{

}

Vector2::Vector2(float _x, float _y)
: x(_x)
, y(_y)
{

}


}
