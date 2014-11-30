#include "ge_object.h"
#include "component/ge_transform.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(Object);

Object::Object()
: name("GameObject")
, actived(true)
, transform_(nullptr)
, components_()
{
	initialize();
}

Object::~Object()
{
	finalize();
}

bool Object::initialize()
{
	components_.clear();
	
	Transform* transform = (Transform*)add_component("Transform");
	if (transform != nullptr) transform_ = transform;

	return true;
}

void Object::finalize()
{
	FOR_EACH(std::set<Component*>, components_, itor_component)
	{
		if (Component* component = *itor_component)
		{
			component->dispose();
			ComponentFactory::release_component(component);
			component = nullptr;
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


Component* Object::add_component(const char* name)
{
	Component* component = ComponentFactory::create_component(name);
	if (component == nullptr) return nullptr;
	components_.insert(component);
	return component;
	//component->set_object(this);
}

void Object::remove_component(Component* component)
{
	std::set<Component*>::iterator itor_component = components_.find(component);
	if (itor_component == components_.end()) return;

	components_.erase(itor_component);
	ComponentFactory::release_component(component);
}

const std::string& Object::get_name()
{
	return name;
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

}