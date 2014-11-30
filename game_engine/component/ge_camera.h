#ifndef _GAME_ENGINE_CAMERA_H_
#define _GAME_ENGINE_CAMERA_H_

#include "common/ge_include.h"
#include "utility/ge_type.h"
#include "component/ge_component.h"
#include "type/ge_rect.h"
#include "type/ge_matrix4x4.h"

namespace ge
{

enum ProjectionMode
{
	Orthographic,
	Perspection,
};

class GE_API Camera : Component
{
	REGISTER_COMPONENT(Camera);

protected:
	static std::set<Camera*> all_cameras_;
	static Camera* main_camera_;

	Camera();
	virtual ~Camera();


public:
	bool init();
	void destory();

	void render();

	void set_projection(ProjectionMode mode);
	ProjectionMode get_projection();
	//void set_projection_fovy(float fovy);
	//void set_projcetion_range(float min_z, float max_z);

	void update_view_matrix();
	void update_projection_matrix();

	//void convert_to_screen_xy(Vector2& point);
	//void convert_to_world_xy(Vector2& point);

protected:
	ProjectionMode		projection_;
	LayerMask			layer_mask_;

	float				clipping_near_;
	float				clipping_far_;

	Rect				rect_;

	bool				dirty_;

	Matrix4x4			projection_matrix_;
	Matrix4x4			view_matrix_;
};

} // namespace ge

#endif // _GAME_ENGINE_CAMERA_H_