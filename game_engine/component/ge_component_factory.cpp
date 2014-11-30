#include "ge_component_factory.h"
#include "component/ge_component.h"

namespace ge
{

ComponentType* ComponentFactory::registe_component(std::string name, Component* (*create_func)())
{
	if (create_func == nullptr) return nullptr;
	ComponentType* component_type = new ComponentType();
	component_type->create_func = create_func;
	(*component_type_map())[name] = component_type;
	return component_type;
}

Component* ComponentFactory::create_component(std::string name)
{
	ComponentTypeMap* type_map = component_type_map();
	ComponentTypeMap::iterator itor = type_map->find(name);
	if (itor == type_map->end()) return nullptr;
	if (itor->second->create_func == nullptr) return nullptr;
	return itor->second->create_func();
}

void ComponentFactory::release_component(Component* component)
{
	if (component == nullptr) return;
	component->release();
}

ComponentTypeMap* ComponentFactory::component_type_map()
{
	static ComponentTypeMap global_component_type_map_;
	return &global_component_type_map_;
}


}


