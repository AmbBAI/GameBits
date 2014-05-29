#ifndef _GAME_ENGINE_CAMERA_H_
#define _GAME_ENGINE_CAMERA_H_

#include "common/ge_include.h"
#include "utility/ge_type.h"

namespace ge
{

class GE_API GECamera
{
	DLL_MANAGE_CLASS(GECamera);

public:
	GECamera();
	virtual ~GECamera();

	enum ProjectionMode
	{
		ProjectionMode_2D,
		ProjectionMode_3D
	};

public:
	bool init();
	void destory();

	void update();

	void set_view_position(float x, float y, float z);
	void set_view_target(float x, float y, float z);
	void set_view_up(float x, float y, float z);

	void set_projection_mode(ProjectionMode mode);
	void set_projection_fovy(float fovy);
	void set_projcetion_range(float min_z, float max_z);

	bool do_view_trans();
	bool do_projection_trans();

	void convert_to_screen_xy(GE_FPOINT& point);
	void convert_to_world_xy(GE_FPOINT& point);

protected:
	D3DXMATRIX			view_matrix_;
	D3DXMATRIX			proj_matrix_;
	D3DXMATRIX			proj_view_matrix_;

	D3DXVECTOR3			position_;
	D3DXVECTOR3			target_;
	D3DXVECTOR3			up_;

	ProjectionMode		mode_;
	float				fovy_;
	float				min_z_;
	float				max_z_;

	bool				is_camera_moved_;
};

} // namespace ge

#endif // _GAME_ENGINE_CAMERA_H_