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
	bool init();
	void add_object(int key, GEObject* obj);
	void remove_object(int key);
	void destory();
	bool show();
	bool hide();

	void update(time_t delta);
	void render(time_t delta);

protected:
	typedef std::map<int, GEObject*> GE_OBJECT_MAP;
	GE_OBJECT_MAP object_map_;
};

} // namespace ge

#endif // _GAME_ENGINE_SCENE_H_