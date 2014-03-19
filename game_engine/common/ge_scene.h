#ifndef _GAME_ENGINE_SCENE_H_
#define _GAME_ENGINE_SCENE_H_

#include "ge_include.h"

namespace ge
{

class GEObject;
class GE_API GEScene
{
	DLL_MANAGE_CLASS(GEScene)

protected:
	GEScene();
	virtual ~GEScene();

public:
	typedef bool (*SCENE_INIT_FUNC)();
	typedef void (*SCENE_DESTORY_FUNC)();
	typedef bool (*SCENE_SHOW_FUNC)();
	typedef bool (*SCENE_HIDE_FUNC)();

	typedef void (*SCENE_UPDATE_FUNC)(time_t delta);
	//typedef void (*SCENE_RENDER_FUNC)(time_t delta);

	void set_init_func(SCENE_INIT_FUNC init_func)			{init_func_ = init_func;}
	void set_destory_func(SCENE_DESTORY_FUNC destory_func)	{destory_func_ = destory_func;}
	void set_show_func(SCENE_SHOW_FUNC show_func)			{show_func_ = show_func;}
	void set_hide_func(SCENE_HIDE_FUNC hide_func)			{hide_func_ = hide_func;}
	void set_update_func(SCENE_UPDATE_FUNC update_func)		{update_func_ = update_func;}

	bool init();
	void destory();
	bool show();
	bool hide();

	void update(time_t delta);
	void render(time_t delta);

	void add_object(int key, GEObject* obj);
	void remove_object(int key);

protected:
	typedef std::map<int, GEObject*> GE_OBJECT_MAP;
	GE_OBJECT_MAP object_map_;

	SCENE_INIT_FUNC			init_func_;
	SCENE_DESTORY_FUNC		destory_func_;
	SCENE_SHOW_FUNC			show_func_;
	SCENE_HIDE_FUNC			hide_func_;
	SCENE_UPDATE_FUNC		update_func_;
	//SCENE_RENDER_FUNC		render_func_;
};

} // namespace ge

#endif // _GAME_ENGINE_SCENE_H_