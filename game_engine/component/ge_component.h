#ifndef _GAME_ENGINE_COMPONENT_H_
#define _GAME_ENGINE_COMPONENT_H_

#include "common/ge_include.h"
#include "object/ge_game_object.h"
#include "component/ge_component_factory.h"

namespace ge
{

class GE_API Component
{
	REGISTER_COMPONENT(Component);

protected:
	Component();
	virtual ~Component();

public:
	virtual void awake();
	virtual void start();
	virtual void update();
	virtual void late_update();
	virtual void dispose();

	virtual void on_enable();
	virtual void on_disable();

	GameObject* get_object();

protected:
	virtual void on_frame_begin();
	virtual void on_frame_end();
	void set_object(GameObject* object);

protected:
	GameObject* object_;
	bool enabled_;
};
}

#endif //_GAME_ENGINE_COMPONENT_H_