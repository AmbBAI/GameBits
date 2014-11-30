#include "ge_vector3.h"

namespace ge
{

const Vector3 Vector3::one = Vector3(1.f, 1.f, 1.f);
const Vector3 Vector3::zero = Vector3(0.f, 0.f, 0.f);

Vector3::Vector3()
	: x(0.f)
	, y(0.f)
	, z(0.f)
{

}

Vector3::Vector3(float _x, float _y, float _z)
	: x(_x)
	, y(_y)
	, z(_z)
{

}
}
