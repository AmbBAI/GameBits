#ifndef _GAME_ENGINE_FMOD_H_
#define _GAME_ENGINE_FMOD_H_

#include "common/ge_include.h"

#include "support/fmod/fmod/inc/fmod.hpp"

namespace ge
{


class GE_API GEFMODSound
{
	DLL_MANAGE_CLASS(GEFMODSound);

	GEFMODSound();
	virtual ~GEFMODSound();

public:
	bool init(const char* sound_file);
	void destory();

	int play(bool loop = false);
	bool pause(bool is_pause, int sid = -1);
	bool stop(int sid = -1);

private:
	FMOD::Sound* sound_;
};

class GE_API GEFMOD
{
	friend GEFMODSound;

public:
	GEFMOD();
	virtual ~GEFMOD();

	static const int FMOD_MAX_CHANNELS;
	static GEFMOD* get_instance();

public:
	bool init();
	void destory();

	void update();

	int get_channels_playing();
	int get_memory_use();
	float get_current_wave();

protected:
	static FMOD::System* get_sys();
	static FMOD::Channel* get_channel(FMOD::Sound* sound, int sid);

private:
	FMOD::System*	sys_;
	unsigned int	ver_;
};

} // namespace ge


#endif // _GAME_ENGINE_FMOD_H_