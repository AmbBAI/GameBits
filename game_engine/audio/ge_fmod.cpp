#include "ge_fmod.h"

#ifdef _DEBUG
#pragma comment(lib, "support/fmod/fmod/lib/fmodexL.lib" )
#else
#pragma comment(lib, "support/fmod/fmod/lib/fmodex.lib" )
#endif

namespace ge
{

GEFMOD::GEFMOD()
: sys_(NULL)
, ver_(0)
{
}

GEFMOD::~GEFMOD()
{
	destory();
}

bool GEFMOD::init()
{
	int res;
	res = FMOD::System_Create(&sys_);
	if (res != FMOD_OK) return false;

	sys_->getVersion(&ver_);
	res = sys_->init(FMOD_MAX_CHANNELS, FMOD_INIT_NORMAL, 0);
	if (res != FMOD_OK)
	{
		destory();
		return false;
	}
	return true;
}

void GEFMOD::destory()
{
	if (sys_)
	{
		sys_->close();
		sys_->release();
		sys_ = NULL;
	}
}

GEFMOD* GEFMOD::get_instance()
{
	static GEFMOD _global_ge_fmod_;
	return &_global_ge_fmod_;
}

FMOD::System* GEFMOD::get_sys()
{
	GEFMOD* ge_fmod = get_instance();
	return ge_fmod->sys_;
}

void GEFMOD::update()
{
	if (sys_)
		sys_->update();
}

FMOD::Channel* GEFMOD::get_channel( FMOD::Sound* sound, int sid )
{
	if (sound == NULL) return NULL;
	if (sid < 0 || sid >= FMOD_MAX_CHANNELS) return NULL;

	FMOD::System* sys = get_sys();
	if (sys == NULL) return NULL;

	FMOD::Channel* channel = NULL;
	sys->getChannel(sid, &channel);
	if (channel == NULL) return false;
	FMOD::Sound* channel_sound = NULL;
	channel->getCurrentSound(&channel_sound);
	if (channel_sound == sound) return channel;
	return NULL;
}

int GEFMOD::get_channels_playing()
{
	int channels_cnt = 0;
	sys_->getChannelsPlaying(&channels_cnt);
	return channels_cnt;
}

int GEFMOD::get_memory_use()
{
	unsigned int mem_use = 0;
	sys_->getMemoryInfo(FMOD_MEMBITS_ALL, NULL, &mem_use, NULL);
	return (int)mem_use;
}

float GEFMOD::get_current_wave()
{
	float wave = 0.f;
	sys_->getWaveData(&wave, 1, 0);
	return wave;
}

const int GEFMOD::FMOD_MAX_CHANNELS = 32;

DLL_MANAGE_CLASS_IMPLEMENT(GEFMODSound)

GEFMODSound::GEFMODSound()
: sound_(NULL)
{
}

GEFMODSound::~GEFMODSound()
{
	destory();
}

bool GEFMODSound::init( const char* sound_file )
{
	destory();

	FMOD::System* sys = GEFMOD::get_sys();
	if (sys == NULL) return false;

	int res = FMOD_OK;
	res = sys->createSound(sound_file, FMOD_NONBLOCKING, false, &sound_);
	if (res != FMOD_OK)
	{
		destory();
		return false;
	}
	return true;
}

void GEFMODSound::destory()
{
	if (sound_)
	{
		sound_->release();
		sound_ = NULL;
	}
}

int GEFMODSound::play( bool loop /*= false*/ )
{
	if (sound_ == NULL) return -1;

	FMOD::System* sys = GEFMOD::get_sys();
	if (sys == NULL) return -1;

	int res = FMOD_OK;
	FMOD::Channel* channel;
	res = sys->playSound(FMOD_CHANNEL_FREE, sound_, false, &channel);
	if (res != FMOD_OK || channel == NULL)
	{
		return -1;
	}
	channel->setMode(loop ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF);

	int sid = -1;
	channel->getIndex(&sid);
	return sid;
}

bool GEFMODSound::pause( bool is_pause, int sid /*= -1*/ )
{
	if (sid >= GEFMOD::FMOD_MAX_CHANNELS) return false;
	if (sid < 0)
	{
		for (int i=0; i<GEFMOD::FMOD_MAX_CHANNELS; ++i)
		{
			if (FMOD::Channel* channel = GEFMOD::get_channel(sound_, i))
			{
				channel->setPaused(is_pause);
			}
		}
	}
	else
	{
		if (FMOD::Channel* channel = GEFMOD::get_channel(sound_, sid))
		{
			channel->setPaused(is_pause);
		}
	}
	return true;
}

bool GEFMODSound::stop( int sid /*= -1*/ )
{
	if (sid >= GEFMOD::FMOD_MAX_CHANNELS) return false;
	if (sid < 0)
	{
		for (int i=0; i<GEFMOD::FMOD_MAX_CHANNELS; ++i)
		{
			if (FMOD::Channel* channel = GEFMOD::get_channel(sound_, i))
			{
				channel->stop();
			}
		}
	}
	else
	{
		if (FMOD::Channel* channel = GEFMOD::get_channel(sound_, sid))
		{
			channel->stop();
		}
	}
	return false;
}




}