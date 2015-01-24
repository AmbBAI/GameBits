#ifndef _GAME_ENGINE_SCENE_H_
#define _GAME_ENGINE_SCENE_H_

#include "ge_include.h"

namespace ge
{

class GameObject;
class GE_API Scene
{
	DLL_MANAGE_CLASS(Scene)

protected:
	Scene();
	virtual ~Scene();

public:
	virtual bool init();
	virtual void destory();
	virtual bool show();
	virtual bool hide();

	virtual void update();

	void add_object(GameObject* obj);
	void remove_object(std::string name);

protected:
	typedef std::map<std::string, GameObject*> GE_OBJECT_MAP;
	GE_OBJECT_MAP object_map_;
};

} // namespace ge

#endif // _GAME_ENGINE_SCENE_H_