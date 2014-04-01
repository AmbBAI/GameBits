#include "ge_lua_scene.h"
#include "../ge_lua_engine.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GELuaScene)

GELuaScene::GELuaScene()
: GEScene()
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
	if (!GEScene::init()) return false;
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
	GEScene::destory();
}

bool GELuaScene::show()
{
	if (!GEScene::show()) return false;
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
	return GEScene::hide();
}

void GELuaScene::update( time_t delta )
{
	if (update_func_)
	{
		GELuaEngine* p_lua_engine = GELuaEngine::get_instance();
		float fdelta = delta / 1000.f;
		p_lua_engine->push_float(fdelta);
		p_lua_engine->run_function(update_func_, 1);
	}

	GEScene::update(delta);
}

}
