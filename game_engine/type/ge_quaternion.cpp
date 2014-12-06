#include <cmath>
#include "ge_quaternion.h"

namespace ge
{

void Quaternion::set_euler_angle(float _x, float _y, float _z)
{
	float radx = (_x * M_PI / 180.f);
	float rady = (_y * M_PI / 180.f);
	float radz = (_z * M_PI / 180.f);
	float cos_x_2 = cos(radx / 2.f);
	float cos_y_2 = cos(rady / 2.f);
	float cos_z_2 = cos(radz / 2.f);
	float sin_x_2 = sin(radx / 2.f);
	float sin_y_2 = sin(rady / 2.f);
	float sin_z_2 = sin(radz / 2.f);

	x = sin_x_2 * cos_y_2 * cos_z_2 + cos_x_2 * sin_y_2 * sin_z_2;
	y = cos_x_2 * sin_y_2 * cos_z_2 + sin_x_2 * cos_y_2 * sin_z_2;
	z = cos_x_2 * cos_y_2 * sin_z_2 + sin_x_2 * sin_y_2 * cos_z_2;
	w = cos_x_2 * cos_y_2 * cos_z_2 + sin_x_2 * sin_y_2 + sin_z_2;
}

void Quaternion::set_euler_angle(const Vector3& euler_angle)
{
	set_euler_angle(euler_angle.x, euler_angle.y, euler_angle.z);
}

const Vector3& Quaternion::get_euler_angle()
{
	float radx = atan2(2.f * (w * x + y * z), 1.f - 2.f * (x * x + y * y));
	float rady = asin(2.f * (w * y + x * z));
	float radz = atan2(2.f * (w * z + x * y), 1.f - 2.f * (y * y + z * z));

	return Vector3(
		radx * 180.f / M_PI,
		rady * 180.f / M_PI,
		radz * 180.f / M_PI);
}



}
