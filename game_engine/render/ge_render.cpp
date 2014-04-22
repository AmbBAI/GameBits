#include "ge_render.h"
#include "common/ge_app.h"
#include "common/ge_engine.h"
#include "draw/ge_draw.h"

namespace ge
{

GERender::GERender()
: position_(0.0f, 0.0f, -256.f)
, target_(0.0f, 0.0f, 0.0f)
, up_(0.0f, 1.0f, 0.0f)
, drawcall_cnt_(0)
, drawvertex_cnt_(0)
{

}

GERender::~GERender()
{

}

GERender* GERender::get_instance()
{
	static GERender _global_ge_render;
	return &_global_ge_render;
}

bool GERender::init()
{
	do_view_trans(position_, target_, up_);
	do_projection_trans(0.5f);
	init_state();
	return true;
}

bool GERender::init_state()
{
	set_render_state(D3DRS_FILLMODE, D3DFILL_SOLID);
	set_render_state(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);

	set_render_state(D3DRS_ALPHABLENDENABLE, true);
	set_render_state(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	set_render_state(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

#ifdef GE_3D_VIEW
	set_render_state(D3DRS_LIGHTING, true);
	set_render_state(D3DRS_NORMALIZENORMALS, true);
	set_render_state(D3DRS_SPECULARENABLE, true);

	set_render_state(D3DRS_ZENABLE, true);
	set_render_state(D3DRS_ZFUNC, D3DCMP_LESSEQUAL); //??
	set_render_state(D3DRS_ZWRITEENABLE, true);
#else
	set_render_state(D3DRS_LIGHTING, false);
	set_render_state(D3DRS_CULLMODE, D3DCULL_NONE);
#endif

	set_sampler_state(D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	set_sampler_state(D3DSAMP_MINFILTER, D3DTEXF_LINEAR);

	return true;
}

void GERender::render(time_t delta)
{
	drawcall_cnt_ = 0;
	drawvertex_cnt_ = 0;
	while (!render_task_que_.empty())
	{
		GEDraw* p_draw = render_task_que_.front();
		render_task_que_.pop();
		if(!p_draw) continue;
		p_draw->render();
		drawcall_cnt_ += p_draw->get_drawcall_cnt();
		drawvertex_cnt_ += p_draw->get_drawvertex_cnt();
	}

	return;
}


bool GERender::do_view_trans( D3DXVECTOR3& position, D3DXVECTOR3& target, D3DXVECTOR3& up )
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_device();
	if (p_d3d_device == NULL) return false;

	D3DXMatrixLookAtLH(&view_matrix_, &position, &target, &up);

	HRESULT h_res = p_d3d_device->SetTransform(D3DTS_VIEW, &view_matrix_);
	return SUCCEEDED(h_res);
}

bool GERender::do_projection_trans( float fovy )
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_device();
	if (p_d3d_device == NULL) return false;
	GE_IRECT& wnd_rect = GEApp::get_instance()->get_game_rect();

#ifdef GE_3D_VIEW
	D3DXMatrixPerspectiveFovLH(
		&proj_matrix_,
		D3DX_PI * fovy,
		(float) wnd_rect.width() / wnd_rect.height(),
		0.f, 1000.f);
#else
	D3DXMatrixOrthoLH(&proj_matrix_, wnd_rect.width(), wnd_rect.height(), 0.f, 1000.f);
#endif

	HRESULT h_res = p_d3d_device->SetTransform(D3DTS_PROJECTION, &proj_matrix_);
	return SUCCEEDED(h_res);
}

void GERender::destory()
{
}

bool GERender::set_render_state( D3DRENDERSTATETYPE type, DWORD value )
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_device();
	if (p_d3d_device == NULL) return false;

	HRESULT h_res = p_d3d_device->SetRenderState(type, value);
	return SUCCEEDED(h_res);
}

DWORD GERender::get_render_state( D3DRENDERSTATETYPE type )
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_device();
	if (p_d3d_device == NULL) return 0;

	DWORD value = 0;
	p_d3d_device->GetRenderState(type, &value);
	return value;
}

bool GERender::set_sampler_state( D3DSAMPLERSTATETYPE type, DWORD value )
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_device();
	if (p_d3d_device == NULL) return 0;

	HRESULT h_res = p_d3d_device->SetSamplerState(0, type, value);
	return SUCCEEDED(h_res);
}

DWORD GERender::get_sampler_state( D3DSAMPLERSTATETYPE type )
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_device();
	if (p_d3d_device == NULL) return 0;

	DWORD value = 0;
	p_d3d_device->GetSamplerState(0, type, &value);
	return value;
}

void GERender::_push_render( GEDraw* p_draw )
{
	render_task_que_.push(p_draw);
}

void GERender::push_render( const GEDraw* p_draw )
{
	GERender* ge_render = get_instance();
	ge_render->_push_render((GEDraw*)p_draw);
}

}

