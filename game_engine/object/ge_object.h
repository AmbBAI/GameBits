#ifndef _GAME_ENGINE_OBJECT_H_
#define _GAME_ENGINE_OBJECT_H_

#include "common/ge_include.h"
#include "common/ge_engine.h"
#include "ge_object_def.h"


namespace ge
{

class Component;
class GE_API Object
{
	DLL_MANAGE_CLASS(Object);

protected:
	Object();
	virtual ~Object();

public:
	bool initialize();
	void finalize();

	void update();

	void add_component(Component* component);

public:

protected:
	bool actived;

	std::set<Component*> components_;
};

} // namespace ge



#endif // _GAME_ENGINE_OBJECT_H_