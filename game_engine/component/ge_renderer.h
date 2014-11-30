#ifndef _GAME_ENGINE_RENDERER_H_
#define _GAME_ENGINE_RENDERER_H_

#include "common/ge_include.h"
#include "common/ge_engine.h"
#include "component/ge_component.h"

namespace ge
{

class GE_API Renderer : Component
{
	REGISTER_COMPONENT(Renderer);
};

}

#endif //_GAME_ENGINE_RENDERER_H_