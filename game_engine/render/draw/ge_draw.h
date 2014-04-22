#ifndef _GAME_ENGINE_RENDER_DRAW_H_
#define _GAME_ENGINE_RENDER_DRAW_H_

#include "common/ge_include.h"
#include "utility/ge_vertex.h"

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

	virtual int get_drawcall_cnt() { return drawcall_cnt_; }
	virtual int get_drawvertex_cnt() { return drawvertex_cnt_; }

protected:
	GEREffect*	effect_;

	int			drawcall_cnt_;
	int			drawvertex_cnt_;
};

} // namespace ge

#endif // _GAME_ENGINE_RENDER_DRAW_H_