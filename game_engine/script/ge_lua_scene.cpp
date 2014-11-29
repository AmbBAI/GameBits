#include "ge_lua_scene.h"
#include "script/ge_lua_engine.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GELuaScene)

GELuaScene::GELuaScene()
: Scene()
, init_func_(NULL)
, destory_func_(NULL)
, show_func_(NULL)
, hide_func_(NULL)
, update_func_(NULL)
{

}

GELuaScene::~GELuaScene()
{
	destory();
}

bool GELuaScene::init()
{
	if (!Scene::init()) return false;
	if (init_func_)
	{
		GELuaEngine* p_lua_engine = GELuaEngine::get_instance();
		if (!p_lua_engine->run_function(init_func_, 0)) return false;
	}
	return true;
}

void GELuaScene::destory()
{
	if (destory_func_)
	{
		GELuaEngine* p_lua_engine = GELuaEngine::get_instance();
		p_lua_engine->run_function(destory_func_, 0);
	}
	Scene::destory();
}

bool GELuaScene::show()
{
	if (!Scene::show()) return false;
	if (show_func_)
	{
		GELuaEngine* p_lua_engine = GELuaEngine::get_instance();
		if (!p_lua_engine->run_function(show_func_, 0)) return false;
	}
	return true;
}

bool GELuaScene::hide()
{
	if (hide_func_)
	{
		GELuaEngine* p_lua_engine = GELuaEngine::get_instance();
		if (!p_lua_engine->run_function(hide_func_, 0)) return false;
	}
	return Scene::hide();
}

void GELuaScene::update()
{
	if (update_func_)
	{
		GELuaEngine* p_lua_engine = GELuaEngine::get_instance();
		p_lua_engine->run_function(update_func_, 0);
	}

	Scene::update();
}

}
