#ifndef _GAME_ENGINE_CAMERA_H_
#define _GAME_ENGINE_CAMERA_H_

#include "common/ge_include.h"
#include "utility/ge_type.h"

namespace ge
{

class GE_API GECamera
{
public:
	GECamera();
	virtual ~GECamera();

public:
	bool init();
	void destory();

	bool do_view_trans(D3DXVECTOR3& position, D3DXVECTOR3& target, D3DXVECTOR3& up);
	bool do_projection_trans(float fovy);
	
	D3DXMATRIX&	get_view_matrix() {return view_matrix_;}
	D3DXMATRIX& get_proj_matrix() {return proj_matrix_;}

	void convert_to_screen_xy(GE_FPOINT& point);
	void convert_to_world_xy(GE_FPOINT& point);

protected:
	D3DXMATRIX			view_matrix_;
	D3DXMATRIX			proj_matrix_;

	D3DXVECTOR3			position_;
	D3DXVECTOR3			target_;
	D3DXVECTOR3			up_;
};

} // namespace ge

#endif // _GAME_ENGINE_CAMERA_H_