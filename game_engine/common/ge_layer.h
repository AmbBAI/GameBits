#ifndef _GAME_ENGINE_LAYER_H_
#define _GAME_ENGINE_LAYER_H_

#include "ge_include.h"
#include "utility/ge_type.h"

namespace ge
{
class GE_API Layer
{
public:
	struct LayerData
	{
		LayerID index;
		std::string name;
	};
	LayerData layers_[32];
};

} // namespace ge

#endif // _GAME_ENGINE_LAYER_H_