#include "ge_scene.h"
#include "common/ge_engine.h"
#include "object/ge_object.h"
#include "render/ge_render.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GEScene)

GEScene::GEScene()
: object_map_()
{

}

GEScene::~GEScene()
{
	destory();
}

bool GEScene::init()
{
	return true;
}

void GEScene::destory()
{
	FOR_EACH (GE_OBJECT_MAP, object_map_, obj_it)
	{
		GEObject* p_obj = (GEObject*)(obj_it->second);
		GE_RELEASE(p_obj);
	}

	object_map_.clear();
}

void GEScene::add_object( int key, GEObject* obj )
{
	object_map_[key] = obj;
	if (obj != NULL) obj->retain();
}

void GEScene::remove_object( int key )
{
	GE_OBJECT_MAP::iterator itor_key = object_map_.find(key);
	if (itor_key != object_map_.end())
	{
		GE_RELEASE((GEObject*)itor_key->second);
		object_map_.erase(itor_key);
	}
}

bool GEScene::show()
{
	return true;
}

bool GEScene::hide()
{
	return true;
}

void GEScene::update( time_t delta )
{
	FOR_EACH (GE_OBJECT_MAP, object_map_, obj_it)
	{
		GEObject* p_obj = (GEObject*)(obj_it->second);
		if (NULL == p_obj) continue;
		p_obj->update(delta);
	}
}

}