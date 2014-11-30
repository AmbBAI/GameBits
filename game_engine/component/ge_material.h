#ifndef _GAME_ENGINE_MATERIAL_H_
#define _GAME_ENGINE_MATERIAL_H_

#include "common/ge_include.h"
#include "component/ge_component.h"

namespace ge
{

class Shader;
class GE_API Material : Component
{
	REGISTER_COMPONENT(Material);


protected:
	Shader* shader_;
};

}

#endif //_GAME_ENGINE_MATERIAL_H_