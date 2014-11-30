#include "ge_time.h"

namespace ge
{

void Time::init()
{
	last_time_ = 0.f;
	cur_time_ = clock() / 1000.f;

	real_delta_time_ = 0.f;
	real_time_ = 0.f;

	delta_time_ = 0.f;
	time_ = 0.f;

	time_scale_ = 1.f;
}

void Time::update()
{
	last_time_ = cur_time_;
	cur_time_ = clock() / 1000.f;
	real_delta_time_ = cur_time_ - last_time_;
	real_time_ += real_delta_time_;

	delta_time_ = real_delta_time_ * time_scale_;
	time_ += delta_time_;
}

float Time::get_time()
{
	return time_;
}

float Time::get_delta_time()
{
	return delta_time_;
}

float Time::get_time_scale()
{
	return time_scale_;
}

void Time::set_time_scale(float time_scale)
{
	time_scale_ = time_scale;
}

float Time::get_real_time()
{
	return real_time_;
}

float Time::get_real_delta_time()
{
	return real_delta_time_;
}

float Time::cur_time_ = 0.f;
float Time::last_time_ = 0.f;
float Time::real_delta_time_ = 0.f;
float Time::real_time_ = 0.f;
float Time::time_scale_ = 1.f;
float Time::delta_time_ = 0.f;
float Time::time_ = 0.f;

}


