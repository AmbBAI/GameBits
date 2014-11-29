#ifndef _GAME_ENGINE_TIME_H_
#define _GAME_ENGINE_TIME_H_
#include "common\ge_include.h"
#include "common\ge_app.h"

namespace ge
{

class GE_API Time
{
	friend GEApp;

protected:
	static void init();
	static void update();

public:
	static float get_time();
	static float get_delta_time();
	static float get_time_scale();
	static void set_time_scale(float time_scale);

	static float get_real_time();
	static float get_real_delta_time();
protected:
	static float time_;
	static float delta_time_;
	static float time_scale_;

	static float real_time_;
	static float real_delta_time_;
		
private:
	static float last_time_;
	static float cur_time_;
};
}


#endif //_GAME_ENGINE_TIME_H_