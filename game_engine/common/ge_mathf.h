#ifndef _GAME_ENGINE_MATHF_H_
#define _GAME_ENGINE_MATHF_H_

#include "common/ge_include.h"
#include "type/ge_rect.h"
#include "type/ge_color.h"
#include "component/ge_camera.h"

namespace ge
{

class GE_API Mathf
{
public:
	static const float epsilon;
	static const float PI;
	static const float infinity;
	static const float negative_infinity;
	static const float deg2rad;
	static const float rad2deg;

	static float abs(float f);
	static float sign(float f);
	static bool approximately(float a, float b);

	static float floor(float f);
	static int floor_to_int(float f);
	static float ceil(float f);
	static int ceil_to_int(float f);
	static float round(float f);
	static float round_to_int(float f);

	static float clamp(float value, float min, float max);
	static float clamp01(float value);
	static float lerp(float from, float to, float t);
	static float lerp_angle(float a, float b, float t);
	static float inverse_lerp(float from, float to, float t);
	static float repeat(float t, float length);
	static float ping_pong(float t, float length);
	static float move_towards(float current, float target, float max_delta);
	//static float smooth_damp(float current, float target, float current_velocity, float smooth_time, float max_speed = Mathf::infinity);
	//static float smooth_damp(float current, float target, float current_velocity, float smooth_time, float max_speed, float delta_time);

	static float min(float a, float b);
	static float min(const float* values, int count);
	static float min(const std::vector<float>& values);
	static float max(float a, float b);
	static float max(const float* values, int count);
	static float max(const std::vector<float>& values);

	static float sqrt(float value);
	static float pow(float f, float p);
	static float exp(float f);
	static float log(float f);
	static float log10(float f);
	static bool is_power_of_two(int value);
	static int closest_power_of_two(int value);
	static int next_power_of_two(int value);

	static float sin(float f);
	static float cos(float f);
	static float tan(float f);
	static float asin(float f);
	static float acos(float f);
	static float atan(float f);
	static float atan2(float y, float x);

};

} // namespace ge

#endif // _GAME_ENGINE_MATHF_H_