#include "ge_layer.h"
#include "common/ge_engine.h"
#include "object/ge_object.h"
//#include "render/ge_render.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(Layer)

Layer::Layer()
: object_map_()
{

}

Layer::~Layer()
{
	destory();
}

bool Layer::init()
{
	return true;
}

void Layer::destory()
{
	FOR_EACH (GE_OBJECT_MAP, object_map_, obj_it)
	{
		Object* p_obj = (Object*)(obj_it->second);
		GE_RELEASE(p_obj);
	}

	object_map_.clear();
}

void Layer::add_object(Object* obj)
{
	if (obj == nullptr) return;
	object_map_[obj->get_name()] = obj;
	if (obj != NULL) obj->retain();
}

void Layer::remove_object(std::string name)
{
	GE_OBJECT_MAP::iterator itor_key = object_map_.find(name);
	if (itor_key != object_map_.end())
	{
		GE_RELEASE((Object*)itor_key->second);
		object_map_.erase(itor_key);
	}
}

bool Layer::show()
{
	return true;
}

bool Layer::hide()
{
	return true;
}

void Layer::update()
{
	FOR_EACH (GE_OBJECT_MAP, object_map_, obj_it)
	{
		Object* p_obj = (Object*)(obj_it->second);
		if (NULL == p_obj) continue;
		p_obj->update();
	}
}

}