#ifndef _GAME_ENGINE_QUATERNION_H_
#define _GAME_ENGINE_QUATERNION_H_
#include "common/ge_include.h"
#include "common/ge_engine.h"
#include "type/ge_vector3.h"

namespace ge
{
struct GE_API Quaternion
{
	float x = 0.f;
	float y = 0.f;
	float z = 0.f;
	float w = 0.f;

	Quaternion();
	Quaternion(float _x, float _y, float _z, float w);

	void set_euler_angle(float _x, float _y, float _z);
	void set_euler_angle(const Vector3& euler_angle);
	const Vector3& get_euler_angle();

};
}

#endif //_GAME_ENGINE_QUATERNION_H_