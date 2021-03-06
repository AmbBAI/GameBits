#include "ge_object.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GEObject);

GEObject::GEObject()
: parent_(NULL)
, is_transform_dirty_(true)
{
	memset(&transform_, 0, sizeof(transform_));
	transform_.sx = 1.f;
	transform_.sy = 1.f;
	transform_.sz = 1.f;

}

GEObject::~GEObject()
{
	destory();
}

bool GEObject::init()
{
	return true;
}

void GEObject::destory()
{
	FOR_EACH (GE_OBJECT_SET, childs_, itor_child)
	{
		GEObject* obj = *itor_child;
		GE_RELEASE(obj);
	}
	childs_.clear();
}

void GEObject::update( time_t delta )
{
	FOR_EACH (GE_OBJECT_SET, childs_, itor_child)
	{
		if (GEObject* obj = *itor_child)
		{
			obj->update(delta);
		}
	}
}

D3DXMATRIX& GEObject::get_world_transform()
{
	if (is_transform_dirty_)
	{
		D3DXMATRIX		trans_matrix;
		D3DXMATRIX		rotatex_matrix;
		D3DXMATRIX		rotatey_matrix;
		D3DXMATRIX		rotatez_matrix;
		D3DXMATRIX		scale_matrix;

		// 位置
		D3DXMatrixTranslation(&trans_matrix, transform_.px, transform_.py, transform_.pz);

		// 旋转
		D3DXMatrixRotationX(&rotatex_matrix, transform_.rx);
		D3DXMatrixRotationY(&rotatey_matrix, transform_.ry);
		D3DXMatrixRotationZ(&rotatez_matrix, transform_.rz);

		// 缩放
		D3DXMatrixScaling(&scale_matrix, transform_.sx, transform_.sy, transform_.sz);

		// TODO 顺序问题
		d3d_world_transform_ = scale_matrix;
		d3d_world_transform_ = d3d_world_transform_ * rotatex_matrix;
		d3d_world_transform_ = d3d_world_transform_ * rotatey_matrix;
		d3d_world_transform_ = d3d_world_transform_ * rotatez_matrix;
		d3d_world_transform_ = d3d_world_transform_ * trans_matrix;

		is_transform_dirty_ = false;
	}
	return d3d_world_transform_;
}

void GEObject::set_transform_dirty( bool is_dirty )
{
	is_transform_dirty_ = is_dirty;
}

GETransform& GEObject::get_transform()
{
	return transform_;
}

void GEObject::set_transform( GETransform& transform )
{
	transform_ = transform;
	is_transform_dirty_ = true;
}

void GEObject::add_child( GEObject* obj )
{
	if (obj == NULL) return;
	childs_.insert(obj);
	obj->retain();
	obj->set_parent(this);
}

void GEObject::set_parent( GEObject* obj )
{
	parent_ = obj;
}

GEObject* GEObject::get_parent()
{
	return parent_;
}


}