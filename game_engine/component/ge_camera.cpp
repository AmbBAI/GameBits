#include "ge_camera.h"
#include "common/ge_engine.h"
#include "common/ge_app.h"
#include "object/ge_object.h"
#include "component/ge_transform.h"

namespace ge
{

REGISTER_COMPONENT_IMPLEMENT(Camera);

Camera::Camera()
: projection_(Perspection)
, clipping_near_(0.1f)
, clipping_far_(1000.f)
, rect_(0.f, 0.f, 1.f, 1.f)
{
	if (main_camera_ == nullptr) main_camera_ = this;
	all_cameras_.insert(this);
}

Camera::~Camera()
{

}

bool Camera::init()
{
	//do_view_trans();
	//do_projection_trans();
	return true;
}

void Camera::destory()
{

}

//bool Camera::do_view_trans()
//{
//	return false;
//	//LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_device();
//	//if (p_d3d_device == NULL) return false;
//
//	//D3DXMatrixLookAtLH(&view_matrix_, &position_, &target_, &up_);
//
//	//HRESULT h_res = p_d3d_device->SetTransform(D3DTS_VIEW, &view_matrix_);
//	//return SUCCEEDED(h_res);
//}
//
//bool Camera::do_projection_trans()
//{
//	return false;
//	//LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_device();
//	//if (p_d3d_device == NULL) return false;
//	//GE_IRECT& wnd_rect = Application::get_instance()->get_game_rect();
//
//	//switch (projection_)
//	//{
//	//case ProjectionMode_3D:
//	//	D3DXMatrixPerspectiveFovLH(
//	//		&proj_matrix_,
//	//		D3DX_PI * fovy_,
//	//		(float) wnd_rect.width() / wnd_rect.height(),
//	//		min_z_, max_z_);
//	//	break;
//	//case ProjectionMode_2D:
//	//	D3DXMatrixOrthoLH(&proj_matrix_,
//	//		(float)wnd_rect.width(),
//	//		(float)wnd_rect.height(),
//	//		min_z_, max_z_);
//	//	break;
//	//}
//
//	//HRESULT h_res = p_d3d_device->SetTransform(D3DTS_PROJECTION, &proj_matrix_);
//	//return SUCCEEDED(h_res);
//}

void Camera::render()
{
	if (object_ == nullptr) return;
	Transform* transform = object_->get_transform();
	if (transform == nullptr) return;

	if (transform->get_is_changed())
	{
		// Update
		dirty_ = true;
	}

	if (dirty_)
	{
		// Update
	}

	// render
}

void Camera::set_projection(ProjectionMode mode)
{
	projection_ = mode;
	dirty_ = true;
}

ge::ProjectionMode Camera::get_projection()
{
	return projection_;
}

void Camera::update_view_matrix()
{

}

void Camera::update_projection_matrix()
{

}

Camera* Camera::main_camera_ = nullptr;
std::set<Camera*> Camera::all_cameras_;

//void Camera::convert_to_screen_xy( Vector2& point )
//{
//	D3DXVECTOR4 out_coord;
//	D3DXVECTOR4 coord(point.x, point.y, 0.f, 1.f);
//	D3DXVec4Transform(&out_coord, &coord, &proj_view_matrix_);
//
//	float factor = 1.0 / coord.w;
//	GE_IRECT& wnd_rect = Application::get_instance()->get_game_rect();
//	point.x = wnd_rect.width() * (out_coord.x * 0.5f + 0.5f) * factor;
//	point.y = wnd_rect.height() * (-out_coord.y * 0.5f + 0.5f) * factor;
//}
//
//void Camera::convert_to_world_xy( Vector2& point )
//{
//	D3DXMATRIX proj_view_inv;
//	D3DXMatrixInverse(&proj_view_inv, NULL, &proj_view_matrix_);
//
//	float z_clip = proj_view_matrix_.m[3][2] / proj_view_matrix_.m[3][3];
//	GE_IRECT& wnd_rect = Application::get_instance()->get_game_rect();
//
//	D3DXVECTOR4 coord(2.0f * point.x / wnd_rect.width() - 1.f, 1.f - 2.0f * point.y / wnd_rect.height(), z_clip, 1);
//	D3DXVECTOR4 out_coord;
//	D3DXVec4Transform(&out_coord, &coord, &proj_view_inv);
//
//	float factor = 1.0 / out_coord.w;
//
//	point.x = out_coord.x * factor;
//	point.y = out_coord.y * factor;
//}
//
//void Camera::set_view_position( float x, float y, float z )
//{
//	position_.x = x;
//	position_.y = y;
//	position_.z = z;
//	is_camera_moved_ = true;
//}
//
//void Camera::set_view_target( float x, float y, float z )
//{
//	target_.x = x;
//	target_.y = y;
//	target_.z = z;
//	is_camera_moved_ = true;
//}
//
//void Camera::set_view_up( float x, float y, float z )
//{
//	up_.x = x;
//	up_.y = y;
//	up_.z = z;
//	is_camera_moved_ = true;
//}
//
//void Camera::set_projection_mode( ProjectionMode mode )
//{
//	projection_ = mode;
//	is_camera_moved_ = true;
//}
//
//void Camera::set_projection_fovy( float fovy )
//{
//	fovy_ = fovy;
//	is_camera_moved_ = true;
//}
//
//void Camera::set_projcetion_range( float min_z, float max_z )
//{
//	min_z_ = min_z;
//	max_z_ = max_z;
//	is_camera_moved_ = true;
//}
//
//void Camera::update()
//{
//	if (is_camera_moved_)
//	{
//		do_view_trans();
//		do_projection_trans();
//		is_camera_moved_ = false;
//	}
//}

}

