#ifndef _GAME_ENGINE_RENDER_H_
#define _GAME_ENGINE_RENDER_H_

#include "common/ge_include.h"
#include "utility/ge_type.h"
#include "render/font/ge_font.h"

namespace ge
{

class GEDraw;
class GECamera;
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

	bool set_render_state(D3DRENDERSTATETYPE type, DWORD value);
	DWORD get_render_state(D3DRENDERSTATETYPE type);

	bool set_sampler_state(D3DSAMPLERSTATETYPE type, DWORD value);
	DWORD get_sampler_state(D3DSAMPLERSTATETYPE type );

	int get_drawcall_cnt() { return drawcall_cnt_; }
	int get_drawvertex_cnt() { return drawvertex_cnt_; }

	GECamera* get_current_camera();

protected:
	RENDER_TASK_QUE		render_task_que_;

	int					drawcall_cnt_;
	int					drawvertex_cnt_;

	GECamera*			main_camera_;
	GECamera*			current_camera_;
};

} // namespace ge

#endif // _GAME_ENGINE_RENDER_H_