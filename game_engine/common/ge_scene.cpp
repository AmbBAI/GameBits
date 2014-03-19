#include "ge_scene.h"
#include "../common/ge_engine.h"
#include "../object/ge_object.h"
#include "../render/ge_render.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GEScene)

GEScene::GEScene()
: object_map_()
, init_func_(NULL)
, destory_func_(NULL)
, show_func_(NULL)
, hide_func_(NULL)
, update_func_(NULL)
//, render_func_(NULL)
{

}

GEScene::~GEScene()
{
	destory();
}

bool GEScene::init()
{
	if (init_func_) return init_func_();
	return true;
}

void GEScene::destory()
{
	//FOR_EACH (GE_OBJECT_MAP, object_map_, obj_it)
	//{
	//	GEObject* p_obj = (GEObject*)(obj_it->second);
	//	if (NULL == p_obj) continue;
	//	p_obj->destory();
	//	obj_it->second = NULL;
	//}

	if (destory_func_) destory_func_();
	object_map_.clear();
}

void GEScene::add_object( int key, GEObject* obj )
{
	object_map_[key] = obj;
}

void GEScene::remove_object( int key )
{
	object_map_.erase(key);
}

bool GEScene::show()
{
	if (show_func_) return show_func_();
	return true;
}

bool GEScene::hide()
{
	if (hide_func_) return hide_func_();
	return true;
}

void GEScene::update( time_t delta )
{
	if (update_func_) update_func_(delta);

	FOR_EACH (GE_OBJECT_MAP, object_map_, obj_it)
	{
		GEObject* p_obj = (GEObject*)(obj_it->second);
		if (NULL == p_obj) continue;
		p_obj->update(delta);
	}
}

void GEScene::render( time_t delta )
{
	GERender* p_render = GERender::get_instance();
	if (p_render == NULL) return;

	FOR_EACH (GE_OBJECT_MAP, object_map_, obj_it)
	{
		GEObject* p_obj = (GEObject*)(obj_it->second);
		if (NULL == p_obj) continue;
		p_render->push_render(p_obj);
	}
}

}