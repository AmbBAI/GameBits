#ifndef _GAME_ENGINE_COMPONENT_H_
#define _GAME_ENGINE_COMPONENT_H_

#include "common/ge_include.h"
#include "common/ge_engine.h"

namespace ge
{

class Object;
class GE_API Component
{
	DLL_MANAGE_CLASS(Component);

protected:
	Component();
	virtual ~Component();

public:
	virtual void awake();
	virtual void start();
	virtual void update();
	virtual void dispose();

	virtual void on_enable();
	virtual void on_disable();

	void set_object(Object* object);
	Object* get_object();

protected:
	Object* object_;
	bool enabled_;
};

}

#endif //_GAME_ENGINE_COMPONENT_H_