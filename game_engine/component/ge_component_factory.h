#ifndef _GAME_ENGINE_COMPONENT_FACTORY_H_
#define _GAME_ENGINE_COMPONENT_FACTORY_H_

#include "common/ge_include.h"

namespace ge
{

class Component;

struct ComponentType
{
	Component* (*create_func)();
};
typedef std::map<std::string, ComponentType*> ComponentTypeMap;

class GE_API ComponentFactory
{
public:
	static ComponentType* RegisterComponent(std::string name, Component* (*create_func)());
	static Component* CreateComponent(std::string name);
	static void ReleaseComponent(Component* component);

protected:
	//static ComponentFactory* get_instance();
	static ComponentTypeMap* component_type_map();
};

}

#endif //_GAME_ENGINE_COMPONENT_FACTORY_H_