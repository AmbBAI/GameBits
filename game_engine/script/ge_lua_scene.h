#ifndef _GAME_ENGINE_LUA_SCENE_H_
#define _GAME_ENGINE_LUA_SCENE_H_

#include "common/ge_include.h"
#include "common/ge_scene.h"

namespace ge
{

typedef int LUA_FUNCTION;
class GE_API GELuaScene : public Scene
{

	DLL_MANAGE_CLASS(GELuaScene)

protected:
	GELuaScene();
	virtual ~GELuaScene();

public:
	virtual bool init();
	virtual void destory();
	virtual bool show();
	virtual bool hide();

	virtual void update();

	void set_init_func(LUA_FUNCTION init_func)			{init_func_ = init_func;}
	void set_destory_func(LUA_FUNCTION destory_func)	{destory_func_ = destory_func;}
	void set_show_func(LUA_FUNCTION show_func)			{show_func_ = show_func;}
	void set_hide_func(LUA_FUNCTION hide_func)			{hide_func_ = hide_func;}
	void set_update_func(LUA_FUNCTION update_func)		{update_func_ = update_func;}

protected:
	LUA_FUNCTION init_func_;
	LUA_FUNCTION destory_func_;
	LUA_FUNCTION show_func_;
	LUA_FUNCTION hide_func_;
	LUA_FUNCTION update_func_;
};

} // namespace ge

#endif // _GAME_ENGINE_LUA_SCENE_H_