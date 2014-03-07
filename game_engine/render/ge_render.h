#ifndef _GAME_ENGINE_RENDER_H_
#define _GAME_ENGINE_RENDER_H_

#include "../common/ge_include.h"
#include "../utility/ge_type.h"
#include "../render/font/ge_font.h"

namespace ge
{

class GEObject;
class GE_API GERender
{
protected:
	typedef std::queue<GEObject*> RENDER_TASK_QUE;

public:
	GERender();
	virtual ~GERender();

	static GERender* get_instance();

public:
	bool init();
	bool init_state();
	void render(time_t delta);
	void destory();

	void push_render(GEObject* p_object);

	virtual bool do_view_trans(D3DXVECTOR3& position, D3DXVECTOR3& target, D3DXVECTOR3& up);
	virtual bool do_projection_trans(float fovy);
	
	D3DXMATRIX&	get_view_matrix() {return view_matrix_;}
	D3DXMATRIX& get_proj_matrix() {return proj_matrix_;}

	virtual bool set_render_state(D3DRENDERSTATETYPE type, DWORD value);
	virtual DWORD get_render_state(D3DRENDERSTATETYPE type);

	virtual bool set_sampler_state(D3DSAMPLERSTATETYPE type, DWORD value);
	virtual DWORD get_sampler_state(D3DSAMPLERSTATETYPE type );

protected:
	RENDER_TASK_QUE		render_task_que_;

	D3DXMATRIX			view_matrix_;
	D3DXMATRIX			proj_matrix_;

	D3DXVECTOR3			position_;
	D3DXVECTOR3			target_;
	D3DXVECTOR3			up_;
};

} // namespace ge

#endif // _GAME_ENGINE_RENDER_H_