#include "ge_camera.h"
#include "common/ge_engine.h"
#include "common/ge_app.h"

namespace ge
{

GECamera::GECamera()
: position_(0.0f, 0.0f, -256.f)
, target_(0.0f, 0.0f, 0.0f)
, up_(0.0f, 1.0f, 0.0f)
{

}

GECamera::~GECamera()
{

}

bool GECamera::init()
{
	do_view_trans(position_, target_, up_);
	do_projection_trans(0.5f);

	return true;
}

void GECamera::destory()
{

}

bool GECamera::do_view_trans( D3DXVECTOR3& position, D3DXVECTOR3& target, D3DXVECTOR3& up )
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_device();
	if (p_d3d_device == NULL) return false;

	D3DXMatrixLookAtLH(&view_matrix_, &position, &target, &up);

	HRESULT h_res = p_d3d_device->SetTransform(D3DTS_VIEW, &view_matrix_);
	return SUCCEEDED(h_res);
}

bool GECamera::do_projection_trans( float fovy )
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

void GECamera::convert_to_screen_xy( GE_FPOINT& point )
{
	D3DXMATRIX proj_view = proj_matrix_ * view_matrix_;

	D3DXVECTOR4 out_coord;
	D3DXVECTOR4 coord(point.x, point.y, 0.f, 1.f);
	D3DXVec4Transform(&out_coord, &coord, &proj_view);

	float factor = 1.0 / coord.w;
	GE_IRECT& wnd_rect = GEApp::get_instance()->get_game_rect();
	point.x = wnd_rect.width() * out_coord.x * factor;
	point.y = wnd_rect.height() * out_coord.y * factor;
}

void GECamera::convert_to_world_xy( GE_FPOINT& point )
{
	D3DXMATRIX proj_view = proj_matrix_ * view_matrix_;

	D3DXMATRIX proj_view_inv;
	D3DXMatrixInverse(&proj_view_inv, NULL, &proj_view);

	float z_clip = proj_view.m[4][3] / proj_view.m[4][4];
	GE_IRECT& wnd_rect = GEApp::get_instance()->get_game_rect();

	D3DXVECTOR4 coord(point.x / wnd_rect.width(), point.y / wnd_rect.height(), z_clip, 1);
	D3DXVECTOR4 out_coord;
	D3DXVec4Transform(&out_coord, &coord, &proj_view_inv);

	float factor = 1.0 / out_coord.w;

	point.x = out_coord.x * factor;
	point.y = out_coord.y * factor;
}

}

