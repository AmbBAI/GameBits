#ifndef _GAME_ENGINE_AUDIO_H_
#define _GAME_ENGINE_AUDIO_H_

#include "common/ge_include.h"
#include "common/ge_engine.h"
#include "audio/ge_fmod.h"


namespace ge
{

class GE_API Audio
{
public:
	static bool init();
	static void destory();

	static void update();
};

} // namespace ge


#endif // _GAME_ENGINE_AUDIO_H_