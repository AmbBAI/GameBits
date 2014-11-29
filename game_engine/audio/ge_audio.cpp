#include "ge_audio.h"

namespace ge
{

bool Audio::init()
{
	GEFMOD* ge_fmod = GEFMOD::get_instance();
	ge_fmod->init();
	return true;
}

void Audio::destory()
{
	GEFMOD* ge_fmod = GEFMOD::get_instance();
	ge_fmod->destory();
}

void Audio::update()
{
	GEFMOD* ge_fmod = GEFMOD::get_instance();
	ge_fmod->update();
}



}