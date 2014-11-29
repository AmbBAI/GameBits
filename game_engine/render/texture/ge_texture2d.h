#ifndef _GAME_ENGINE_TEXTURE2D_H_
#define _GAME_ENGINE_TEXTURE2D_H_

#include "common/ge_include.h"

namespace ge
{

class GE_API Texture2D
{
	DLL_MANAGE_CLASS(Texture2D);

protected:
	Texture2D();
	virtual ~Texture2D();

public:


protected:
	float width;
	float height;
};

} // namespace ge

#endif // _GAME_ENGINE_TEXTURE2D_H_