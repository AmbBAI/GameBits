#ifndef _GAME_ENGINE_SCENE_H_
#define _GAME_ENGINE_SCENE_H_

#include "ge_include.h"

namespace ge
{

typedef int LUA_FUNCTION;
class GEObject;
class GE_API GEScene
{
	DLL_MANAGE_CLASS(GEScene)

protected:
	GEScene();
	virtual ~GEScene();

public:
	virtual bool init();
	virtual void destory();
	virtual bool show();
	virtual bool hide();

	virtual void update(time_t delta);
	virtual void render(time_t delta);

	void add_object(int key, GEObject* obj);
	void remove_object(int key);

	// FOR LUA
	void set_init_func(LUA_FUNCTION init_func)			{init_func_ = init_func;}
	void set_destory_func(LUA_FUNCTION destory_func)	{destory_func_ = destory_func;}
	void set_show_func(LUA_FUNCTION show_func)			{show_func_ = show_func;}
	void set_hide_func(LUA_FUNCTION hide_func)			{hide_func_ = hide_func;}
	void set_update_func(LUA_FUNCTION update_func)		{update_func_ = update_func;}
	//void set_render_func(LUA_FUNCTION render_func)		{render_func_ = render_func;}
	// FOR LUA END

protected:
	typedef std::map<int, GEObject*> GE_OBJECT_MAP;
	GE_OBJECT_MAP object_map_;

	// FOR LUA
	LUA_FUNCTION init_func_;
	LUA_FUNCTION destory_func_;
	LUA_FUNCTION show_func_;
	LUA_FUNCTION hide_func_;
	LUA_FUNCTION update_func_;
	//LUA_FUNCTION render_func_;
	// FOR LUA END
};

} // namespace ge

#endif // _GAME_ENGINE_SCENE_H_