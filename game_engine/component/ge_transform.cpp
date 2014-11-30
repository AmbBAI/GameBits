#include "ge_transform.h"

namespace ge
{

REGISTER_COMPONENT_IMPLEMENT(Transform)

void Transform::set_local_position(const Vector3& val)
{
	local_position_ = val;
	set_dirty();
}

const Vector3& Transform::get_local_position()
{
	return local_position_;
}

const Vector3& Transform::get_position()
{
	if (dirty_)
	{
		update_transform();
	}
	return position_;
}

void Transform::set_local_rotation(const Vector3& val)
{
	local_rotation_ = val;
	if (!dirty_) set_dirty();
}

const Vector3& Transform::get_local_rotation()
{
	return local_rotation_;
}

const Vector3& Transform::get_rotation()
{
	if (dirty_)
	{
		update_transform();
		dirty_ = false;
	}
	return rotation_;
}

void Transform::update_transform()
{
	Vector3 parent_position = Vector3::zero;
	Vector3 parent_rotation = Vector3::zero;
	if (parent_ != nullptr)
	{
		parent_position = parent_->get_position();
		parent_rotation = parent_->get_rotation();
	}

	position_ = local_position_;
	rotation_ = local_rotation_;
	scale_ = local_scale_;

	//TODO

}


void Transform::set_dirty()
{
	dirty_ = true;
	is_changed_ = true;
	FOR_EACH(std::set<Transform*>, children_, itor_child)
	{
		if (Transform* transform = *itor_child)
		{
			transform->set_dirty();
		}
	}
}

void Transform::on_frame_end()
{
	is_changed_ = false;
}

bool Transform::get_is_changed()
{
	return is_changed_;
}



}


