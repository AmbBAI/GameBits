#ifndef _GAME_ENGINE_OBJECT_H_
#define _GAME_ENGINE_OBJECT_H_

#include "common/ge_include.h"
#include "common/ge_engine.h"
#include "utility/ge_type.h"

namespace ge
{

class Component;
class Transform;
class GE_API Object
{
	DLL_MANAGE_CLASS(Object);

protected:
	Object();
	virtual ~Object();

	bool initialize();
	void finalize();

public:
	void update();

	const std::string& get_name();
	Transform* get_transform();

	Component* add_component(const char* name);
	void remove_component(Component* component);

public:

protected:
	std::string name;
	LayerID layer;
	bool actived;

	std::set<Component*> components_;
	Transform* transform_;
};

} // namespace ge



#endif // _GAME_ENGINE_OBJECT_H_