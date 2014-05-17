#include "ge_audio.h"

namespace ge
{

bool GEAudio::init()
{
	GEFMOD* ge_fmod = GEFMOD::get_instance();
	ge_fmod->init();
	return true;
}

void GEAudio::destory()
{
	GEFMOD* ge_fmod = GEFMOD::get_instance();
	ge_fmod->destory();
}

void GEAudio::update()
{
	GEFMOD* ge_fmod = GEFMOD::get_instance();
	ge_fmod->update();
}



}