#include "ge_matrix4x4.h"

namespace ge
{


void Matrix4x4::fill(float val)
{
	memcpy(m, &val, sizeof(float) * 16);
}

void Matrix4x4::identity()
{
	fill(0.f);
	m[0] = m[5] = m[10] = m[15] = 1.0f;
}

bool Matrix4x4::is_identity()
{
	static float identity[] = { 1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	return (memcmp(identity, m, sizeof(float)* 16) == 0);
}

void Matrix4x4::multiply(const Matrix4x4& mat)
{
	Matrix4x4 self = *this;
	m[0] = self.m[0] * mat.m[0] + self.m[4] * mat.m[1] + self.m[8] * mat.m[2] + self.m[12] * mat.m[3];
	m[1] = self.m[1] * mat.m[0] + self.m[5] * mat.m[1] + self.m[9] * mat.m[2] + self.m[13] * mat.m[3];
	m[2] = self.m[2] * mat.m[0] + self.m[6] * mat.m[1] + self.m[10] * mat.m[2] + self.m[14] * mat.m[3];
	m[3] = self.m[3] * mat.m[0] + self.m[7] * mat.m[1] + self.m[11] * mat.m[2] + self.m[15] * mat.m[3];

	m[4] = self.m[0] * mat.m[4] + self.m[4] * mat.m[5] + self.m[8] * mat.m[6] + self.m[12] * mat.m[7];
	m[5] = self.m[1] * mat.m[4] + self.m[5] * mat.m[5] + self.m[9] * mat.m[6] + self.m[13] * mat.m[7];
	m[6] = self.m[2] * mat.m[4] + self.m[6] * mat.m[5] + self.m[10] * mat.m[6] + self.m[14] * mat.m[7];
	m[7] = self.m[3] * mat.m[4] + self.m[7] * mat.m[5] + self.m[11] * mat.m[6] + self.m[15] * mat.m[7];

	m[8] = self.m[0] * mat.m[8] + self.m[4] * mat.m[9] + self.m[8] * mat.m[10] + self.m[12] * mat.m[11];
	m[9] = self.m[1] * mat.m[8] + self.m[5] * mat.m[9] + self.m[9] * mat.m[10] + self.m[13] * mat.m[11];
	m[10] = self.m[2] * mat.m[8] + self.m[6] * mat.m[9] + self.m[10] * mat.m[10] + self.m[14] * mat.m[11];
	m[11] = self.m[3] * mat.m[8] + self.m[7] * mat.m[9] + self.m[11] * mat.m[10] + self.m[15] * mat.m[11];

	m[12] = self.m[0] * mat.m[12] + self.m[4] * mat.m[13] + self.m[8] * mat.m[14] + self.m[12] * mat.m[15];
	m[13] = self.m[1] * mat.m[12] + self.m[5] * mat.m[13] + self.m[9] * mat.m[14] + self.m[13] * mat.m[15];
	m[14] = self.m[2] * mat.m[12] + self.m[6] * mat.m[13] + self.m[10] * mat.m[14] + self.m[14] * mat.m[15];
	m[15] = self.m[3] * mat.m[12] + self.m[7] * mat.m[13] + self.m[11] * mat.m[14] + self.m[15] * mat.m[15];
}

void Matrix4x4::operator*(const Matrix4x4& mat)
{
	multiply(mat);
}

void Matrix4x4::assign_rotation_euler_angle(const Vector3& euler_angle)
{
	Quaternion quaternion;
	quaternion.set_euler_angle(euler_angle);
	assign_rotation_quaternion(quaternion);
}

void Matrix4x4::assign_rotation_quaternion(const Quaternion& quaternion)
{
	double xx = quaternion.x * quaternion.x;
	double xy = quaternion.x * quaternion.y;
	double xz = quaternion.x * quaternion.z;
	double xw = quaternion.x * quaternion.w;

	double yy = quaternion.y * quaternion.y;
	double yz = quaternion.y * quaternion.z;
	double yw = quaternion.y * quaternion.w;

	double zz = quaternion.z * quaternion.z;
	double zw = quaternion.z * quaternion.w;

	m[0] = 1 - 2 * (yy + zz);
	m[1] = 2 * (xy + zw);
	m[2] = 2 * (xz - yw);
	m[3] = 0;

	m[4] = 2 * (xy - zw);
	m[5] = 1 - 2 * (xx + zz);
	m[6] = 2 * (yz + xw);
	m[7] = 0.0;

	m[8] = 2 * (xz + yw);
	m[9] = 2 * (yz - xw);
	m[10] = 1 - 2 * (xx + yy);
	m[11] = 0.0;

	m[12] = 0.0;
	m[13] = 0.0;
	m[14] = 0.0;
	m[15] = 1.0;
}

void Matrix4x4::assign_rotation_x(float radians)
{
	/*
		|  1  0       0       0 |
	M = |  0  cos(A) -sin(A)  0 |
		|  0  sin(A)  cos(A)  0 |
		|  0  0       0       1 |

	*/

	m[0] = 1.0f;
	m[1] = 0.0f;
	m[2] = 0.0f;
	m[3] = 0.0f;

	m[4] = 0.0f;
	m[5] = cosf(radians);
	m[6] = sinf(radians);
	m[7] = 0.0f;

	m[8] = 0.0f;
	m[9] = -sinf(radians);
	m[10] = cosf(radians);
	m[11] = 0.0f;

	m[12] = 0.0f;
	m[13] = 0.0f;
	m[14] = 0.0f;
	m[15] = 1.0f;
}

void Matrix4x4::assign_rotation_y(float radians)
{
	/*
		|  cos(A)  0   sin(A)  0 |
	M = |  0       1   0       0 |
		| -sin(A)  0   cos(A)  0 |
		|  0       0   0       1 |
	*/

	m[0] = cosf(radians);
	m[1] = 0.0f;
	m[2] = -sinf(radians);
	m[3] = 0.0f;

	m[4] = 0.0f;
	m[5] = 1.0f;
	m[6] = 0.0f;
	m[7] = 0.0f;

	m[8] = sinf(radians);
	m[9] = 0.0f;
	m[10] = cosf(radians);
	m[11] = 0.0f;

	m[12] = 0.0f;
	m[13] = 0.0f;
	m[14] = 0.0f;
	m[15] = 1.0f;
}

void Matrix4x4::assign_rotation_z(float radians)
{
	/*
		|  cos(A)  -sin(A)   0   0 |
	M = |  sin(A)   cos(A)   0   0 |
		|  0        0        1   0 |
		|  0        0        0   1 |
	*/

	m[0] = cosf(radians);
	m[1] = sinf(radians);
	m[2] = 0.0f;
	m[3] = 0.0f;

	m[4] = -sinf(radians);
	m[5] = cosf(radians);
	m[6] = 0.0f;
	m[7] = 0.0f;

	m[8] = 0.0f;
	m[9] = 0.0f;
	m[10] = 1.0f;
	m[11] = 0.0f;

	m[12] = 0.0f;
	m[13] = 0.0f;
	m[14] = 0.0f;
	m[15] = 1.0f;
}

void Matrix4x4::assign_scaling(const Vector3& scaling)
{
	fill(0.f);
	m[0] = scaling.x;
	m[5] = scaling.y;
	m[10] = scaling.z;
	m[15] = 1.0f;
}

void Matrix4x4::assign_translation(const Vector3& translation)
{
	fill(0.f);

	m[0] = 1.0f;
	m[5] = 1.0f;
	m[10] = 1.0f;

	m[12] = translation.x;
	m[13] = translation.y;
	m[14] = translation.z;
	m[15] = 1.0f;
}

const Matrix4x4& Matrix4x4::ortho(float left, float right, float bottom, float top, float z_near, float z_far)
{
	float tx = -((right + left) / (right - left));
	float ty = -((top + bottom) / (top - bottom));
	float tz = -((z_far + z_near) / (z_far - z_near));

	Matrix4x4 mat;
	mat.identity();
	mat.m[0] = 2 / (right - left);
	mat.m[5] = 2 / (top - bottom);
	mat.m[10] = -2 / (z_far - z_near);
	mat.m[12] = tx;
	mat.m[13] = ty;
	mat.m[14] = tz;

	return mat;
}

const Matrix4x4& Matrix4x4::perspective(float fov, float aspect, float z_near, float z_far)
{
	float r = (fov / 2) * M_PI / 180.f;
	float z_delta = z_far - z_near;
	float s = sin(r);
	float cotangent = 0;

	Matrix4x4 mat;
	if (z_delta == 0 || s == 0 || aspect == 0) {
		return mat;
	}

	//cos(r) / sin(r) = cot(r)
	cotangent = cos(r) / s;

	mat.identity();
	mat.m[0] = cotangent / aspect;
	mat.m[5] = cotangent;
	mat.m[10] = -(z_far + z_near) / z_delta;
	mat.m[11] = -1;
	mat.m[14] = -2 * z_near * z_far / z_delta;
	mat.m[15] = 0;

	return mat;
}

const Matrix4x4& Matrix4x4::trs(const Vector3& pos, const Quaternion& q, const Vector3& s)
{
	Matrix4x4 mat;
	mat.set_trs(pos, q, s);
	return mat;
}

void Matrix4x4::set_trs(const Vector3& pos, const Quaternion& q, const Vector3& s)
{
	identity();

	Matrix4x4 tmp;
	tmp.assign_scaling(s);
	multiply(tmp);

	tmp.assign_rotation_quaternion(q);
	multiply(tmp);

	tmp.assign_translation(pos);
	multiply(tmp);
}

const Matrix4x4& Matrix4x4::inverse()
{
	Matrix4x4 mat;
	double det;
	int i;

	mat.m[0] = m[5] * m[10] * m[15] -
		m[5] * m[11] * m[14] -
		m[9] * m[6] * m[15] +
		m[9] * m[7] * m[14] +
		m[13] * m[6] * m[11] -
		m[13] * m[7] * m[10];

	mat.m[4] = -m[4] * m[10] * m[15] +
		m[4] * m[11] * m[14] +
		m[8] * m[6] * m[15] -
		m[8] * m[7] * m[14] -
		m[12] * m[6] * m[11] +
		m[12] * m[7] * m[10];

	mat.m[8] = m[4] * m[9] * m[15] -
		m[4] * m[11] * m[13] -
		m[8] * m[5] * m[15] +
		m[8] * m[7] * m[13] +
		m[12] * m[5] * m[11] -
		m[12] * m[7] * m[9];

	mat.m[12] = -m[4] * m[9] * m[14] +
		m[4] * m[10] * m[13] +
		m[8] * m[5] * m[14] -
		m[8] * m[6] * m[13] -
		m[12] * m[5] * m[10] +
		m[12] * m[6] * m[9];

	mat.m[1] = -m[1] * m[10] * m[15] +
		m[1] * m[11] * m[14] +
		m[9] * m[2] * m[15] -
		m[9] * m[3] * m[14] -
		m[13] * m[2] * m[11] +
		m[13] * m[3] * m[10];

	mat.m[5] = m[0] * m[10] * m[15] -
		m[0] * m[11] * m[14] -
		m[8] * m[2] * m[15] +
		m[8] * m[3] * m[14] +
		m[12] * m[2] * m[11] -
		m[12] * m[3] * m[10];

	mat.m[9] = -m[0] * m[9] * m[15] +
		m[0] * m[11] * m[13] +
		m[8] * m[1] * m[15] -
		m[8] * m[3] * m[13] -
		m[12] * m[1] * m[11] +
		m[12] * m[3] * m[9];

	mat.m[13] = m[0] * m[9] * m[14] -
		m[0] * m[10] * m[13] -
		m[8] * m[1] * m[14] +
		m[8] * m[2] * m[13] +
		m[12] * m[1] * m[10] -
		m[12] * m[2] * m[9];

	mat.m[2] = m[1] * m[6] * m[15] -
		m[1] * m[7] * m[14] -
		m[5] * m[2] * m[15] +
		m[5] * m[3] * m[14] +
		m[13] * m[2] * m[7] -
		m[13] * m[3] * m[6];

	mat.m[6] = -m[0] * m[6] * m[15] +
		m[0] * m[7] * m[14] +
		m[4] * m[2] * m[15] -
		m[4] * m[3] * m[14] -
		m[12] * m[2] * m[7] +
		m[12] * m[3] * m[6];

	mat.m[10] = m[0] * m[5] * m[15] -
		m[0] * m[7] * m[13] -
		m[4] * m[1] * m[15] +
		m[4] * m[3] * m[13] +
		m[12] * m[1] * m[7] -
		m[12] * m[3] * m[5];

	mat.m[14] = -m[0] * m[5] * m[14] +
		m[0] * m[6] * m[13] +
		m[4] * m[1] * m[14] -
		m[4] * m[2] * m[13] -
		m[12] * m[1] * m[6] +
		m[12] * m[2] * m[5];

	mat.m[3] = -m[1] * m[6] * m[11] +
		m[1] * m[7] * m[10] +
		m[5] * m[2] * m[11] -
		m[5] * m[3] * m[10] -
		m[9] * m[2] * m[7] +
		m[9] * m[3] * m[6];

	mat.m[7] = m[0] * m[6] * m[11] -
		m[0] * m[7] * m[10] -
		m[4] * m[2] * m[11] +
		m[4] * m[3] * m[10] +
		m[8] * m[2] * m[7] -
		m[8] * m[3] * m[6];

	mat.m[11] = -m[0] * m[5] * m[11] +
		m[0] * m[7] * m[9] +
		m[4] * m[1] * m[11] -
		m[4] * m[3] * m[9] -
		m[8] * m[1] * m[7] +
		m[8] * m[3] * m[5];

	mat.m[15] = m[0] * m[5] * m[10] -
		m[0] * m[6] * m[9] -
		m[4] * m[1] * m[10] +
		m[4] * m[2] * m[9] +
		m[8] * m[1] * m[6] -
		m[8] * m[2] * m[5];

	det = m[0] * mat.m[0] + m[1] * mat.m[4] + m[2] * mat.m[8] + m[3] * mat.m[12];

	if (det == 0) {
		return mat;
	}

	det = 1.0 / det;

	for (i = 0; i < 16; i++) {
		mat.m[i] *= det;
	}

	return mat;
}

const Matrix4x4& Matrix4x4::transpose()
{
	int x, z;
	Matrix4x4 mat;

	for (z = 0; z < 4; ++z) {
		for (x = 0; x < 4; ++x) {
			mat.m[(z * 4) + x] = m[(x * 4) + z];
		}
	}

	return mat;
}



















}
