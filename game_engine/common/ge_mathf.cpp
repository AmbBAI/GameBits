#include "ge_mathf.h"

namespace ge
{

const float Mathf::epsilon = FLT_EPSILON;
const float Mathf::PI = (float)M_PI;
const float Mathf::infinity = FLT_MAX;
const float Mathf::negative_infinity = -FLT_MAX;
const float Mathf::deg2rad = (float)M_PI / 180.0f;
const float Mathf::rad2deg = 180.0f / (float)M_PI;

float Mathf::abs(float f)
{
	return ::fabs(f);
}
float Mathf::sign(float f)
{
	return ::signbit(f) ? -1.f : 1.f;
}
bool Mathf::approximately(float a, float b)
{
	return Mathf::abs(a - b) < Mathf::epsilon;
}

float Mathf::floor(float f)
{
	return ::floor(f);
}
int Mathf::floor_to_int(float f)
{
	return (int)(Mathf::floor(f) + Mathf::epsilon);
}
float Mathf::ceil(float f)
{
	return ::ceil(f);
}
int Mathf::ceil_to_int(float f)
{
	return (int)(Mathf::ceil(f) + Mathf::epsilon);
}
float Mathf::round(float f)
{
	return ::round(f);
}
float Mathf::round_to_int(float f)
{
	return (int)(Mathf::round(f) + Mathf::epsilon);
}

float Mathf::clamp(float value, float min, float max)
{
	return value > max ? max : Mathf::min(value, min);
}
float Mathf::clamp01(float value)
{
	return Mathf::clamp(value, 0.f, 1.f);
}

float Mathf::min(float a, float b)
{
	return ::fmin(a, b);
}
float Mathf::min(const float* values, int count) 
{
	if (values == nullptr) return 0.f;
	if (count <= 0) return 0.f;
	if (count == 1) return values[0];

	float min_value = values[0];
	for (int i = 1; i < count; ++i)
	{
		min_value = Mathf::min(min_value, values[i]);
	}
	return min_value;
}
float Mathf::min(const std::vector<float>& values)
{
	return *std::min_element(values.begin(), values.end());
}
float Mathf::max(float a, float b)
{
	return ::fmax(a, b);
}
float Mathf::max(const float* values, int count)
{
	if (values == nullptr) return 0.f;
	if (count <= 0) return 0.f;
	if (count == 1) return values[0];

	float max_value = values[0];
	for (int i = 1; i < count; ++i)
	{
		max_value = Mathf::max(max_value, values[i]);
	}
	return max_value;
}
float Mathf::max(const std::vector<float>& values)
{
	return *std::max_element(values.begin(), values.end());
}

float Mathf::sin(float f)
{
	return ::sin(f);
}
float Mathf::cos(float f)
{
	return ::cos(f);
}
float Mathf::tan(float f)
{
	return ::tan(f);
}
float Mathf::asin(float f)
{
	return ::asin(f);
}
float Mathf::acos(float f)
{
	return ::acos(f);
}
float Mathf::atan(float f)
{
	return ::atan(f);
}
float Mathf::atan2(float y, float x)
{
	return ::atan2(y, x);
}

float Mathf::lerp(float from, float to, float t)
{
	t = Mathf::clamp01(t);
	return to * t + from * (1.f - t);
}

float Mathf::inverse_lerp(float from, float to, float t)
{
	return Mathf::lerp(to, from, t);
}

float Mathf::repeat(float t, float length)
{
	t = Mathf::abs(t);
	length = Mathf::abs(length);
	if (Mathf::approximately(length, 0.f)) return 0.f;
	return ::fmod(t, length);
}

float Mathf::ping_pong(float t, float length)
{
	t = Mathf::abs(t);
	length = Mathf::abs(length);
	if (Mathf::approximately(length, 0.f)) return 0.f;
	
	int div_value = Mathf::ceil_to_int(t / length);
	float mod_value = ::fmod(t, length);
	if (div_value & 1) return length - mod_value;
	else return mod_value;
}

float Mathf::move_towards(float current, float target, float max_delta)
{
	if (current < target)
	{
		current += max_delta;
		if (current >= target) return target;
		return current;
	}
	else
	{
		current -= max_delta;
		if (current <= target) return target;
		return current;
	}
}

float Mathf::sqrt(float value)
{
	return ::sqrt(value);
}

float Mathf::pow(float f, float p)
{
	return ::pow(f, p);
}

float Mathf::exp(float f)
{
	return ::exp(f);
}

float Mathf::log(float f)
{
	return ::log(f);
}

float Mathf::log10(float f)
{
	return ::log10(f);
}

bool Mathf::is_power_of_two(int value)
{
	if (value <= 0) return false;
	return (value & (value - 1)) == 0;
}

int Mathf::next_power_of_two(int value)
{
	if (value <= 0) return 1;
	if (Mathf::is_power_of_two(value)) return value << 1;

	--value;
	value |= value >> 1;
	value |= value >> 2;
	value |= value >> 4;
	value |= value >> 8;
	value |= value >> 16;
	++value;
	return value;
}

int Mathf::closest_power_of_two(int value)
{
	if (value <= 0) return 1;
	if (Mathf::is_power_of_two(value)) return value;
	
	int next = Mathf::next_power_of_two(value);
	int prev = (next >> 1);
	return next - value < value - prev ? next : prev;
}





}
