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

GameObject* Component::get_object()
{
	return object_;
}

void Component::set_object(GameObject* object)
{
	object_ = object;
}

void Component::on_frame_begin()
{

}

void Component::on_frame_end()
{

}

void Component::late_update()
{

}

}


