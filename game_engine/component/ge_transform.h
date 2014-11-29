#ifndef _GAME_ENGINE_TRANSFORM_H_
#define _GAME_ENGINE_TRANFSORM_H_

#include "common/ge_include.h"
#include "common/ge_engine.h"
#include "type/ge_vector3.h"
#include "component/ge_component.h"

namespace ge
{

class GE_API Transform : Component
{
	DLL_MANAGE_CLASS(Transform);

public:
	//void set_position(const Vector3& val);
	//const Vector3& get_position();

	void set_local_position(const Vector3& val);
	const Vector3& get_local_position();
	const Vector3& get_position();

	void set_local_rotation(const Vector3& val);
	const Vector3& get_local_rotation();
	const Vector3& get_rotation();

	void update_transform();

	//void set_rotation(const Vector3& val);

	void set_dirty();

protected:
	Vector3 position_;
	Vector3 rotation_;
	Vector3 scale_;
	Vector3 local_position_;
	Vector3 local_rotation_;
	Vector3 local_scale_;
	bool dirty_;

protected:
	Transform* parent_;
	std::set<Transform*> children_;
};

}

#endif //_GAME_ENGINE_TRANSFORM_H_