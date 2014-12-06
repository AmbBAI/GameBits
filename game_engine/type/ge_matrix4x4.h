#ifndef _GAME_ENGINE_MATRIX4X4_H_
#define _GAME_ENGINE_MATRIX4X4_H_

#include "common/ge_include.h"
#include "common/ge_engine.h"
#include "type/ge_vector3.h"
#include "type/ge_quaternion.h"

namespace ge
{
struct GE_API Matrix4x4
{
	float m[16];

	float get(int r, int c);

	void identity();
	bool is_identity();

	const Matrix4x4& inverse();
	const Matrix4x4& transpose();

	void multiply(const Matrix4x4& mat);
	void operator *(const Matrix4x4& mat);

	void set_trs(const Vector3& pos, const Quaternion& q, const Vector3& s);

	static const Matrix4x4& ortho(float left, float right, float bottom, float top, float z_near, float z_far);
	static const Matrix4x4& perspective(float fov, float aspect, float z_near, float z_far);
	static const Matrix4x4& trs(const Vector3& pos, const Quaternion& q, const Vector3& s);

protected:
	void fill(float val);

	void assign_translation(const Vector3& translation);

	void assign_rotation_euler_angle(const Vector3& euler_angle);
	void assign_rotation_quaternion(const Quaternion& quaternion);
	void assign_rotation_x(float radians);
	void assign_rotation_y(float radians);
	void assign_rotation_z(float radians);

	void assign_scaling(const Vector3& scaling);
};

}

#endif //_GAME_ENGINE_MATRIX4X4_H_