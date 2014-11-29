#include "ge_object.h"
#include "component/ge_transform.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(Object);

Object::Object()
{
}

Object::~Object()
{
	finalize();
}

bool Object::initialize()
{
	components_.clear();
	Transform* transform = Transform::create();
	transform_ = transform;
	add_component((Component*)transform);
	return true;
}

void Object::finalize()
{
	FOR_EACH(std::set<Component*>, components_, itor_component)
	{
		if (Component* component = *itor_component)
		{
			component->dispose();
			GE_RELEASE(component);
		}
	}
	components_.clear();
}

void Object::update()
{
	FOR_EACH(std::set<Component*>, components_, itor_component)
	{
		if (Component* component = *itor_component)
		{
			component->update();
		}
	}
}


void Object::add_component(Component* component)
{
	if (component == nullptr) return;
	components_.insert(component);
	component->set_object(this);
}

//
//D3DXMATRIX& Object::get_world_transform()
//{
//	if (is_transform_dirty_)
//	{
//		D3DXMATRIX		trans_matrix;
//		D3DXMATRIX		rotatex_matrix;
//		D3DXMATRIX		rotatey_matrix;
//		D3DXMATRIX		rotatez_matrix;
//		D3DXMATRIX		scale_matrix;
//
//		// 位置
//		D3DXMatrixTranslation(&trans_matrix, transform_.px, transform_.py, transform_.pz);
//
//		// 旋转
//		D3DXMatrixRotationX(&rotatex_matrix, transform_.rx);
//		D3DXMatrixRotationY(&rotatey_matrix, transform_.ry);
//		D3DXMatrixRotationZ(&rotatez_matrix, transform_.rz);
//
//		// 缩放
//		D3DXMatrixScaling(&scale_matrix, transform_.sx, transform_.sy, transform_.sz);
//
//		// TODO 顺序问题
//		d3d_world_transform_ = scale_matrix;
//		d3d_world_transform_ = d3d_world_transform_ * rotatex_matrix;
//		d3d_world_transform_ = d3d_world_transform_ * rotatey_matrix;
//		d3d_world_transform_ = d3d_world_transform_ * rotatez_matrix;
//		d3d_world_transform_ = d3d_world_transform_ * trans_matrix;
//
//		is_transform_dirty_ = false;
//	}
//	return d3d_world_transform_;
//}

//void Object::set_transform( GETransform& transform )
//{
//	transform_ = transform;
//	is_transform_dirty_ = true;
//}
//
//void Object::add_child( Object* obj )
//{
//	if (obj == NULL) return;
//	childs_.insert(obj);
//	obj->retain();
//	obj->set_parent(this);
//}
//
//void Object::set_parent( Object* obj )
//{
//	parent_ = obj;
//}
//
//Object* Object::get_parent()
//{
//	return parent_;
//}


}