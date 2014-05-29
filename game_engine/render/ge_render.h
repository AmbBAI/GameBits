#ifndef _GAME_ENGINE_RENDER_H_
#define _GAME_ENGINE_RENDER_H_

#include "common/ge_include.h"
#include "utility/ge_type.h"
#include "render/font/ge_font.h"

namespace ge
{

class GEDraw;
class GE_API GERender
{
protected:
	typedef std::queue<GEDraw*> RENDER_TASK_QUE;

public:
	GERender();
	virtual ~GERender();

	static GERender* get_instance();
	static void push_render(const GEDraw* p_draw);

public:
	bool init();
	bool init_state();
	void render(time_t delta);
	void destory();

	void _push_render(GEDraw* p_draw);

	virtual bool set_render_state(D3DRENDERSTATETYPE type, DWORD value);
	virtual DWORD get_render_state(D3DRENDERSTATETYPE type);

	virtual bool set_sampler_state(D3DSAMPLERSTATETYPE type, DWORD value);
	virtual DWORD get_sampler_state(D3DSAMPLERSTATETYPE type );

	virtual int get_drawcall_cnt() { return drawcall_cnt_; }
	virtual int get_drawvertex_cnt() { return drawvertex_cnt_; }

protected:
	RENDER_TASK_QUE		render_task_que_;

	int					drawcall_cnt_;
	int					drawvertex_cnt_;
};

} // namespace ge

#endif // _GAME_ENGINE_RENDER_H_