#include "ge_scene.h"
#include "object/ge_game_object.h"
//#include "render/ge_render.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(Scene)

Scene::Scene()
: object_map_()
{

}

Scene::~Scene()
{
	destory();
}

bool Scene::init()
{
	return true;
}

void Scene::destory()
{
	FOR_EACH (GE_OBJECT_MAP, object_map_, obj_it)
	{
		GameObject* p_obj = (GameObject*)(obj_it->second);
		GE_RELEASE(p_obj);
	}

	object_map_.clear();
}

void Scene::add_object(GameObject* obj)
{
	if (obj == nullptr) return;
	object_map_[obj->get_name()] = obj;
	if (obj != NULL) obj->retain();
}

void Scene::remove_object(std::string name)
{
	GE_OBJECT_MAP::iterator itor_key = object_map_.find(name);
	if (itor_key != object_map_.end())
	{
		GE_RELEASE((GameObject*)itor_key->second);
		object_map_.erase(itor_key);
	}
}

bool Scene::show()
{
	return true;
}

bool Scene::hide()
{
	return true;
}

void Scene::update()
{
	FOR_EACH (GE_OBJECT_MAP, object_map_, obj_it)
	{
		GameObject* p_obj = (GameObject*)(obj_it->second);
		if (NULL == p_obj) continue;
		p_obj->update();
	}
}

}