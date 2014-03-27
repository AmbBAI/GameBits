#ifndef _GAME_ENGINE_RENDER_DRAW_H_
#define _GAME_ENGINE_RENDER_DRAW_H_

#include "../../common/ge_include.h"
#include "../../utility/ge_vertex.h"

namespace ge
{

class GEREffect;
class GE_API GEDraw
{
	DLL_MANAGE_CLASS(GEDraw);

protected:
	GEDraw();
	virtual ~GEDraw();

public:
	virtual void render();

	virtual bool set_effect(GEREffect* effect);
	virtual GEREffect* get_effect();

protected:
	GEREffect* effect_;
};

} // namespace ge

#endif // _GAME_ENGINE_RENDER_DRAW_H_