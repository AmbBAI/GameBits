#include "ge_quaternion.h"
#include "common/ge_mathf.h"

namespace ge
{

void Quaternion::set_euler_angle(float _x, float _y, float _z)
{
	float radx = (_x * Mathf::deg2rad);
	float rady = (_y * Mathf::deg2rad);
	float radz = (_z * Mathf::deg2rad);
	float cos_x_2 = Mathf::cos(radx / 2.f);
	float cos_y_2 = Mathf::cos(rady / 2.f);
	float cos_z_2 = Mathf::cos(radz / 2.f);
	float sin_x_2 = Mathf::sin(radx / 2.f);
	float sin_y_2 = Mathf::sin(rady / 2.f);
	float sin_z_2 = Mathf::sin(radz / 2.f);

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
	float radx = Mathf::atan2(2.f * (w * x + y * z), 1.f - 2.f * (x * x + y * y));
	float rady = Mathf::asin(2.f * (w * y + x * z));
	float radz = Mathf::atan2(2.f * (w * z + x * y), 1.f - 2.f * (y * y + z * z));

	return Vector3(
		radx * Mathf::rad2deg,
		rady * Mathf::rad2deg,
		radz * Mathf::rad2deg);
}



}
