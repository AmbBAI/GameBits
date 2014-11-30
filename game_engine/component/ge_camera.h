#ifndef _GAME_ENGINE_CAMERA_H_
#define _GAME_ENGINE_CAMERA_H_

#include "common/ge_include.h"
#include "utility/ge_type.h"
#include "component/ge_component.h"
#include "type/ge_rect.h"

namespace ge
{

class GE_API Camera : Component
{
	REGISTER_COMPONENT(Camera);

protected:
	Camera();
	virtual ~Camera();


public:
	bool init();
	void destory();

	void update();

	//void set_projection_mode(ProjectionMode mode);
	//void set_projection_fovy(float fovy);
	//void set_projcetion_range(float min_z, float max_z);

	//bool do_view_trans();
	//bool do_projection_trans();

	//void convert_to_screen_xy(Vector2& point);
	//void convert_to_world_xy(Vector2& point);

protected:

	enum ProjectionMode
	{
		Orthographic,
		Perspection,
	};
	ProjectionMode		projection_;
	LayerMask			layer_mask_;

	float				clipping_near_;
	float				clipping_far_;

	Rect				rect_;
};

} // namespace ge

#endif // _GAME_ENGINE_CAMERA_H_