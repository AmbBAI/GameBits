#include "ge_component.h"


namespace ge
{

	REGISTER_COMPONENT_IMPLEMENT(Component)
Component::Component()
{
	awake();
}

Component::~Component()
{
	dispose();
}

void Component::awake()
{

}

void Component::start()
{

}

void Component::update()
{

}

void Component::dispose()
{
	if (enabled_) on_disable();
}

void Component::on_enable()
{

}

void Component::on_disable()
{

}

Object* Component::get_object()
{
	return object_;
}

void Component::set_object(Object* object)
{
	object_ = object;
}

}


